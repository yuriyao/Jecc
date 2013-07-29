/**
 *  语法分析器
 **/
#include "state.h"
#include "GT.h"
#include "stack.h"
#include "token.h"
#include "states_table.h"
#include "word_analysis.h"
#include <stdlib.h>
#include "seman.h"

extern const struct GrammerItem* lr1_table[TABLE_COLUMNS][TABLE_ROWS];

static struct TokenNode* iter;
static struct TokenNode* token_buffer;
void GA_init()
{
	iter = create_iter();
	token_buffer = NULL;
}

/*********************************************************/
//语法分析的输入
/*enum GA_STATES 
{
	GA_ID,
	GA_PLUS,
	GA_MUL,
	GA_L,
	GA_R,
	GA_DOLOR,
	GA_E,
	GA_E1,
	GA_T,
	GA_T1,
	GA_F
};

int remap(struct TokenNode *node)
{
	if(!node)
		return GA_DOLOR;
	switch(node->type)
	{
	case TOKEN:
		return GA_ID;
	case L_PARENT:
		return GA_L;
	case R_PARENT:
		return GA_R;
	case PLUS:
		return GA_PLUS;
	case MULTI:
	case STAR:
		return GA_MUL;
	default:
		return GA_DOLOR;
	}
}*/

enum GA_STATES
{
	GA_PLUS, //0
	GA_MINUS, //1
	GA_STAR, //2
	GA_DIV, //扩展一下，可以支持/, >=, <=, <, >, ==
	GA_SIMPLE_TYPE, //4
	GA_NUMBER, //5
	GA_L_PARENT, //6
	GA_R_PARENT, //7
	GA_L_BPARENT, //8
	GA_R_BPARENT, //9
	GA_MAIN, //10
	GA_SEPERATE, //11
	GA_TOKEN, //12
	GA_EXTERN,//13
	GA_INT,//14
	GA_LDQUOTA,//15
	GA_RDQUOTA,//16
	GA_STRING,//17
	GA_STRUCT,//18
	GA_VOID, //19
	GA_COMMA, //20
	GA_EQUAL, //21
	GA_IF, //22
	GA_ELSE, //23
	GA_FOR, //24
	GA_WHILE,//25
	GA_RETURN,//26
	GA_DOLOR, //27
	GA_PROGRAM,
	GA_PARAMLIST,
	GA_PARAMLIST1
};

static int key_word_to_type(struct TokenNode *node)
{
	char *str = node->value_p;
	char *simple_types[] = {"char", "float", "unsigned", "long", "short", "double", "byte"};
	int i = 0;
	for(i = 0; i < sizeof(simple_types) / sizeof(char*); i ++)
	{
		if(strcmp(str, simple_types[i]) == 0)
			return GA_SIMPLE_TYPE;
	}
	if(strcmp("int", str) == 0)
		return GA_INT;
	if(strcmp("extern", str) == 0)
		return GA_EXTERN;
	if(strcmp("void", str) == 0)
		return GA_VOID;
	if(strcmp("if", str) == 0)
		return GA_IF;
	if(strcmp("else", str) == 0)
		return GA_ELSE;
	if(strcmp("for", str) == 0)
		return GA_FOR;
	if(strcmp("while", str) == 0)
		return GA_WHILE;
	if(strcmp("struct", str) == 0)
		return GA_STRUCT;
	if(strcmp("return", str) == 0)
		return GA_RETURN;
	return GA_TOKEN;
} 

/*将词法分析的类型映射到语法分析的类型*/
static int remap(struct TokenNode *node)
{
	if(!node)
		return GA_DOLOR;
	switch(node->type)
	{

	case TOKEN:
		if(strcmp("main", node->value_p) == 0)
			return GA_MAIN;
		return GA_TOKEN;
	case L_PARENT:
		return GA_L_PARENT;
	case R_PARENT:
		return GA_R_PARENT;
	case PLUS:
		return GA_PLUS;
	case MINUS:
		return GA_MINUS;
	case MULTI:
	case STAR:
		return GA_STAR;
	/*扩展一下除运算，使其支持>=, <=, <, >, ==等逻辑运算，前后兼容的恶心做法*/
	case EE:
	case LG:
	case GT:
	case LE:
	case GE:
	case DIVIDE:
		return GA_DIV;
	case EQUAL:
		return GA_EQUAL;
	case KEYWORD:
		return key_word_to_type(node);
	case COMMA:
		return GA_COMMA;
	case L_QUOTA:
		return GA_LDQUOTA;
	case R_QUOTA:
		return GA_RDQUOTA;
	case L_BPARENT:
		return GA_L_BPARENT;
	case R_BPARENT:
		return GA_R_BPARENT;
	case STRING:
		return GA_STRING;
	case SEMICOLON:
		return GA_SEPERATE;
	case FLOAT:
	case INT:
	case LONG:
	case DOUBLE:
		return GA_NUMBER;
	default:
		return GA_DOLOR;
	}
}

void store_token(struct TokenNode *node)
{
	token_buffer = node;
}

struct TokenNode* get_a_token(int *state)
{
	struct TokenNode *node;
	if(!token_buffer)
		node = next(&iter);
	else
	{
		node = token_buffer;
		token_buffer = NULL;
	}
	//if(node)
		//print_token(stdout, node);
	*state = remap(node);
	//printf("In the get_a_state, %d\n", *state);
	return node;
}
/************************************************/

struct GrammerTreeNode* handle_table()
{
	struct stack* stack = create_stack();
	int state = 0;
	int stack_top;
	struct TokenNode* token;
	struct GrammerItem *item;
	struct CFG *cfg;
	struct GrammerTreeNode **gts, *t, *v;
	int i;

	if(!stack)
		return NULL;
	//将初始状态压入栈
	push(stack, (void*)0);
	while(1)
	{
		token = get_a_token(&state);
		//printf("The input type is %d\n", state);
		stack_top = (int)top(stack);
		item = lr1_table[stack_top][state];
		v = create_GTNode(FINAL, token);
		/*归约*/
		if(item->type == GI_SHIFT)
		{
			push(stack, (void*)v);
			push(stack, (void*)item->gi_skip);
		}
		/*归约*/
		else if(item->type == GI_REDUCE)
		{
			//获得用于归约的生成式
			cfg = item->gi_cfg;
			//用于合成新节点的子树森林
			gts = (struct GrammerTreeNode**)mm_malloc(cfg->items * sizeof(struct GrammerTreeNode*));
			if(!gts)
				return NULL;
			for(i = cfg->items - 1; i >= 0; i --)
			{
				pop(stack);
				gts[i] = (struct GrammerTreeNode*)pop(stack);
			}
			t = to_one_tree2(cfg->items, 0, cfg, gts);
			//printf("----------------------\n");
			//wfs(stdout, t);
			//printf("----------------------\n");
			stack_top = (int)top(stack);
			mm_free(gts);
			//压入新合成的节点
			push(stack, (void*)t);
			//获得新状态
			item = lr1_table[stack_top][cfg->row];
			store_token(token);
			if(item->type == GI_ERR)
			{
				printf("Enter error state\n");
				return NULL;
			}
			push(stack, (void*)item->gi_skip);
		}
		/*接受*/
		else if(item->type == GI_ACC)
		{
			pop(stack);
			return (struct GrammerTreeNode*)pop(stack);
		}
		/*出错*/
		else 
		{
			printf("源文件语法有问题啊!! the stack top is %d, state is %d\n", stack_top, state);
			exit(-1);
		}
	}
	/*已经到末尾，如果不能接受，就错误*/
	stack_top = (int)pop(stack);
	if(lr1_table[stack_top][state]->type == GI_ACC)
		return (struct GrammerTreeNode*)pop(stack);
	return NULL;
}
  
int main(int argc, char **argv)
{
	struct GrammerTreeNode *root;
	FILE *fp;
	/*生成的汇编代码写入的文件*/
	FILE *asm_fp;
	int ret;
	if(argc < 3)
	{
		printf("Usage:%s <src_file> <des_file>\n", argv[0]);
		return -1;
	}
	/**/ 
	//_Z13word_analysisPcS_(argv[1], "word.txt");
	word_analysis(argv[1], "word.txt");
	//process();
	//process_float_all('a');
	/**/
	/*进行语法分析*/
	GA_init();
	root = handle_table();
	/*写入语法分析结果的文件*/
	fp = fopen("gts.txt", "w");
	if(!fp)
	{
		perror("fopen");
		exit(-1);
	}
	/*打开汇编代码的文件*/
	asm_fp = fopen(argv[2], "w");
	if(!asm_fp)
	{
		perror("fopen");
		exit(-1);
	}
	/**/
	if(root)
	{
		printf("好耶！语法分析成功!\n");
		wfs(fp, root);
	}
	else
	{
		printf("语法分析失败,不能归约啊！！亲！\n");
		goto error;
	}
	
	seman_init();
	/*来，进行语义分析*/
	ret = process_seman(root, asm_fp, argv[1]);

	/*好，成功完成汇编，打印信息*/
	if(ret == 0)
	{
		printf("-------->>>>>>jecc<<<<<<----------\n");
		printf("成功生成汇编代码了！！！OH, YES.BUT FUCK ASSHOLE,你需要调用一下gcc指令完成可执行文件的生成\n");
		printf("Call me @>>>>>>>>>>heishiyuriyao@gmail.com<<<<<<<<<<<<\n");
		printf(">>>>>>>>>>>>>不给满分不好吧！！！！！<<<<<<<<<<<<<<<\n");
		printf("( -> _ -> )( @ + @ )( <- _ <- )\n");
		goto ok;
	}
error:
	printf("-------->>>>>>jecc<<<<<<----------\n");
	printf("OOPS!!发生了错误,汇编程序生成失败\n");
	printf("Call me @>>>>>>>>>>heishiyuriyao@gmail.com<<<<<<<<<<<<\n");
	printf(">>>>>>>>>>>>>不给满分不好吧！！！！！<<<<<<<<<<<<<<<\n");
	printf("( -> _ -> )( @ + @ )( <- _ <- )\n");
ok:
	close(fp);
	close(asm_fp);
	return 0;
}


