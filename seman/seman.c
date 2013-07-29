/**
 *  语义分析
 **/
/**
 *  根程序块，存放全局变量
 **/
#include "seman.h"
#include <stdio.h>
#include <string.h>

static struct block_info *root_block;

/**
 *  函数的信息hash表
 **/
static struct HashTable *func_table;

/**
 *  全局的字符串常量哈希表
 **/
static struct HashTable *string_table;

/**
 *  字符串常量的计数器，用于生成汇编代码时的标记符命名
 **/
static int string_counter = 1;
/**
 *  是否出错
 **/
static int err_occur = 0;
/**
 *  用于跳转的标号
 **/
static volatile int jmp_label = 0;

struct block_info* build_block(struct GrammerTreeNode *head, FILE *fp, struct func_info *func);
static void handle_func_call(struct GrammerTreeNode *head, FILE *fp);
static struct variant_info* handle_expr(struct GrammerTreeNode *head, FILE *fp);

//用于广度优先搜索的节点
struct wfs_type
{
	struct GrammerTreeNode *node;
	struct list_head list;
	int new_line;
};

typedef void (*dfs_handler)(struct GrammerTreeNode *node, char *buffer, int *pointer);

/**
 *  深度优先搜索
 **/
static void dfs_begin(char *buffer, struct list_head *list, int pointer, dfs_handler handler)
{
	struct list_head *v = del_head(list);
	//struct list_head temp;
	struct wfs_type *w;
	struct wfs_type *t = NULL;
	struct list_head *l;
	//
	struct GrammerTreeNode *c;
	//处理队列头
	if(!v)
		return;
	w = list_entry(v, struct wfs_type, list);
	if(handler)
	{
		handler(w->node, buffer, &pointer);
	}
	//将队列头的孩子节点加入列表头
	//INIT_LIST_HEAD(&temp);
	list_for_each_tail(l, &w->node->childs)
	{
		c = list_entry(l, struct GrammerTreeNode, brother);
		t = (struct wfs_type*)mm_malloc(sizeof(struct wfs_type));
		t->new_line = 0;
		t->node = c;
		if(!t)
			return;
		insert_head(list, &t->list);
	}
	if(t)
		t->new_line = 1;
	//if()
	mm_free(w);
	dfs_begin(buffer, list, pointer, handler);
}

/**
 *  进行深度优先搜索
 **/
static void dfs(char *buffer, struct GrammerTreeNode *root, dfs_handler handler)
{
	struct list_head list;
	struct wfs_type *node;
	INIT_LIST_HEAD(&list);
	node = (struct wfs_type*)mm_malloc(sizeof(struct wfs_type));
	if(!node)
		return;
	node->node = root;
	node->new_line = 1;
	insert_head(&list, &node->list);
	dfs_begin(buffer, &list, 0, handler);
}

static void type_handler(struct GrammerTreeNode *node, char *buffer, int *pointer)
{
	char t[257];
	if(node->type == FINAL)
	{
		node_to_string(node->value, t);
		//strcpy(t, node->value->value_p);
		strcpy(buffer + *pointer, t);
		*pointer += strlen(t);
		buffer[*pointer] = ' ';
		(*pointer) ++;
		buffer[*pointer] = '\0';
	}
}

static void param_handler(struct GrammerTreeNode *node, char *buffer, int *pointer)
{
	type_handler(node, buffer, pointer);
}

/**
 *  获得有严谨格式的类型字符串
 **/
static void _get_type(struct GrammerTreeNode *head, char *buffer)
{
	dfs(buffer, head, type_handler);
	/*去掉末尾的空格*/
	buffer[strlen(buffer) - 1] = '\0';
}

/**
 *  获得有严谨格式的参数列表的字符串
 **/
void _get_param_list(struct GrammerTreeNode *head, char *buffer)
{
	dfs(buffer, head, param_handler);
	/*去掉末尾的空格*/
	buffer[strlen(buffer) - 1] = '\0';
}

/**
 *  生成函数的汇编代码
 **/
static void generate_func_code(char *type, char *name, 
	char *param_list, FILE *fp)
{
	/*生成注释*/
	fprintf(fp, "//Func:%s %s(%s)\n", type, name, param_list);
	fprintf(fp, ".globl %s\n", name);
	fprintf(fp, "%s:\n", name);
	/*处理函数栈*/
	fprintf(fp, "\tpushl %%ebp\n\tmovl %%esp, %%ebp\n\tsubl $24, %%esp\n");
}

static void generate_leave_func_code(FILE *fp)
{
	fprintf(fp, "\tleave\n\tret\n\n");
}

/**
 *  创建一个函数并且生成汇编代码，写入文件@fp之中
 *  head  函数定义的跟节点
 *  fp    待写入汇编的文件
 **/
struct func_info* build_func(struct GrammerTreeNode *head, FILE *fp)
{
	char type[256];
	char name[33];
	char param_list[1024];
	int i = 0;
	struct GrammerTreeNode *v;
	struct list_head *h;
	struct func_info *ret;

	if(!head)
		return NULL;

	list_for_each(h, &head->childs)
	{
		v = list_entry(h, struct GrammerTreeNode, brother);
		switch(i)
		{
		//Type
		case 0:
			_get_type(v, type);
			break;
		//Name
		case 1:
			strcpy(name, v->value->value_p);
			break;
		//Paramlist
		case 3:
			_get_param_list(v, param_list);
			ret = create_func_info(type, name, param_list);
			if(!ret)
				return NULL;
			insert_func_table(func_table, ret);
			generate_func_code(type, name, param_list, fp);
			break;
		//Block
		case 5:
			
			build_block(v, fp, ret);
			generate_leave_func_code(fp);
			break;
		default:
			break;
		}
		i ++;
	}
	/*********/
	//printf("func_info: type:%s, name:%s, param_list:%s\n", type, name, param_list);
	//
	return ret;
}

/**
 *  处理函数申明
 **/
struct func_info* handle_func_state(struct GrammerTreeNode *head, FILE *fp)
{
	char type[256];
	char name[33];
	char param_list[1024];
	int i = 0;
	struct GrammerTreeNode *v;
	struct list_head *h;
	struct func_info *ret;

	if(!head)
		return NULL;

	list_for_each(h, &head->childs)
	{
		v = list_entry(h, struct GrammerTreeNode, brother);
		switch(i)
		{
		//Type
		case 1:
			_get_type(v, type);
			break;
		//Name
		case 2:
			strcpy(name, v->value->value_p);
			break;
		//Paramlist
		case 4:
			_get_param_list(v, param_list);
			ret = create_func_info(type, name, param_list);
			if(!ret)
				return NULL;
			insert_func_table(func_table, ret);
			break;
		default:
			break;
		}
		i ++;
	}
	fprintf(fp, "//function state:%s %s(%s)\n\n", type, name, param_list);
	return 0;
}

void handle_main(struct GrammerTreeNode *head, FILE *fp)
{
	struct func_info* func;
	struct GrammerTreeNode *v;
	struct list_head *l;
	int i = 0;

	func = create_func_info("int", "main", "");
	generate_func_code("int", "main", "", fp);
	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		//创建函数块
		if(i == 4)
		{
			build_block(v, fp, func);
		}
		i ++;
	}
	generate_leave_func_code(fp);

}

static void handle_statement(struct GrammerTreeNode *head, FILE *fp)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		/*函数调用*/
		if(v->cfg == FUNC_CALL_CFG)
		{
			handle_func_call(v, fp);
		}
		/*处理类型定义*/
		else if(v->type != FINAL && v->cfg->parent == TYPEDEF_CFG)
		{
			handle_variant(v, fp);
		}
		/*处理赋值语句*/
		else if(v->type != FINAL && v->cfg->parent == ASSIGN_CFG)
		{
			handle_value(v, fp);
		}
		/*return*/
		else if(v->type != FINAL && v->cfg->parent == RETURN_CFG)
		{
			handle_return(v, fp);
		}
		/*处理表达式*/
		else if(v->type != FINAL && v->cfg->parent == EXPR_CFG)
		{
			handle_expr(v, fp);
		}
	}
}

/**
 *  处理代码块
 **/
static void build_block1(struct GrammerTreeNode *head, FILE *fp)
{
	struct list_head *l;
	struct GrammerTreeNode *v;

	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		//仍然是Block'
		if(v->cfg && v->cfg->parent == BLOCK1_CFG)
		{
			build_block1(v, fp);
		}
		/*Statement*/
		else if(v->cfg->parent == STATEMENT_CFG)
		{
			handle_statement(v, fp);
		}
		/*if*/
		else if(v->cfg == IF_CFG)
		{
			handle_if(v, fp, -1);
		}
		/*for*/
		else if(v->cfg == FOR_CFG)
		{
			handle_for(v, fp);
		}
		/*while*/
		else if(v->cfg == WHILE_CFG)
		{
			handle_while(v, fp);
		}
		/*if else*/
		else if(v->cfg == IF_ELSE_CFG)
		{
			handle_if_else(v, fp);
		}
		else
		{
			printf("impossible block'\n");
		}

	}
}

struct block_info* build_block(struct GrammerTreeNode *head, FILE *fp, struct func_info *func)
{
	//切换程序块时，保存父程序块
	struct block_info *parent = CURRENT_BLOCK;
	struct list_head *l;
	struct GrammerTreeNode *v;
	struct block_info *self;
	int i = 0;
	struct variant_info *vi;
	int ret;
	int addr = 8;

	/*创建程序块*/
	self = create_block(parent, func ? FUNCTION : NORMAL);
	/*切换当前的程序块*/
	CURRENT_BLOCK = self;
	if(!self)
	{
		printf("内部错误，创建程序块失败\n");
		return NULL;
	}
	/*将参数添加到局部变量中*/
	if(func)
	{
		for(i = 0; i < func->param_info->param_num; i ++)
		{
			vi = func->param_info->type_info + i;
			ret = block_add_var_var(self, vi, (void*)addr);
			/*重复定义*/
			if(ret == -1)
			{
				printf("error:在函数\"%s\"重复定义变量\"%s\"", func->fi_name, vi->vi_name);
			}
			/*设置下一个参数的地址*/
			addr += ALIGN_LONG(vi->type_info->len);
		}

	}
	
	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		build_block1(v, fp);
	}
	CURRENT_BLOCK = self->parent;
	return self;
}

/**
 *  扩展除,设计时的前后兼容的恶心扩展方法
 **/
enum EXTAND_OPS
{
	EXTAND_DIV,// /
	EXTAND_EE,//==
	EXTAND_LE,//<=
	EXTAND_GE,//>=
	EXTAND_LG,// <
	EXTAND_GT,// >
	EXTAND_ERR,//不支持
};

enum EXTAND_OPS _get_extand_type(char *ops)
{
	if(!ops)
		return EXTAND_ERR;
	if(strcmp(ops, "/") == 0)
		return EXTAND_DIV;
	else if(strcmp(ops, "==") == 0)
		return EXTAND_EE;
	else if(strcmp(ops, "<=") == 0)
		return EXTAND_LE;
	else if(strcmp(ops, ">=") == 0)
		return EXTAND_GE;
	else if(strcmp(ops, "<") == 0)
		return EXTAND_LG;
	else if(strcmp(ops, ">") == 0)
		return EXTAND_GT;
	return EXTAND_ERR;
}

/**
 *  处理表达式
 *  处理结果存放在eax, 和ebx中
 **/
static struct variant_info* handle_expr(struct GrammerTreeNode *head, FILE *fp)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	int number ;
	struct variant_info *vi;
	char name[257];
	int i = 0;
	char ops[3];
	enum EXTAND_OPS op_type;

	list_for_each_tail(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		/*纯数字的表达式*/
		if(v->parent->cfg == EXPR_NUMBER_CFG)
		{
			fprintf(fp, "\tmovl $%d, %%eax\n", v->value->value_i);
			return create_variant_info("int", "");
		}
		/*纯变量的表达式*/
		else if(v->parent->cfg == EXPR_TOKEN_CFG)
		{
			node_to_string(v->value, name);
			//先搜索变量表
			vi = search_variant(name);
			if(vi)
			{
				//全局变量
				if(vi->global)
				{
					fprintf(fp, "\tmovl $%s, %%eax\n", vi->vi_name);
				}
				//局部变量
				else
				{
					fprintf(fp, "\tmovl %d(%%ebp), %%eax\n", vi->vi_addr);
				}
			}
			else
			{
				/*应该检查函数表，看看是否是函数指针，但这里就不支持了*/
				printf("error:\"%s\"是未定义的变量名\n", name);
				err_occur = 1;
				return NULL;
			}
		}
		/*+-* /*/
		else if(head->type != FINAL)
		{
			
			switch(i) 
			{
			case 1:
				handle_expr(v, fp);
				fprintf(fp, "\tpushl %%eax\n");
				break;
			case 2:
				node_to_string(v->value, ops);
				op_type = _get_extand_type(ops);
				//printf("ops:%s\n", ops);
				break;
			case 3:
				handle_expr(v, fp);
				fprintf(fp, "\tpopl %%ecx\n");
				/*+*/
				if(head->cfg == EXPR_ADD_CFG)
				{
					fprintf(fp, "\taddl %%ecx, %%eax\n");
				}
				else if(head->cfg == EXPR_SUB_CFG)
				{
					fprintf(fp, "\tsubl %%ecx, %%eax\n");
				}
				else if(head->cfg == EXPR_MULTI_CFG)
				{
					fprintf(fp, "\timull %%ecx, %%eax\n");
				}
				/*除扩展了许多操作*/
				else if(head->cfg == EXPR_DIV_CFG)
				{
					switch(op_type)
					{
					//除
					case EXTAND_DIV:
						fprintf(fp, "\txor %%edx, %%edx\n");
						fprintf(fp, "\tidivl %%ecx\n");
						break;
					//==
					case EXTAND_EE:
						fprintf(fp, "\tcmpl %%ecx, %%eax\n\tsete %%al\n\tmovzbl %%al, %%eax\n");
						break;
					//>=
					case EXTAND_GE:
						fprintf(fp, "\tcmpl %%ecx, %%eax\n\tsetge %%al\n\tmovzbl %%al, %%eax\n");
						break;
					//<=
					case EXTAND_LE:
						fprintf(fp, "\tcmpl %%ecx, %%eax\n\tsetle %%al\n\tmovzbl %%al, %%eax\n");
						break;
					//<
					case EXTAND_LG:
						fprintf(fp, "\tcmpl %%ecx, %%eax\n\tsetl %%al\n\tmovzbl %%al, %%eax\n");
						break;
					//>
					case EXTAND_GT:
						fprintf(fp, "\tcmpl %%ecx, %%eax\n\tsetg %%al\n\tmovzbl %%al, %%eax\n");
						break;
					default:
						printf("内部错误：不可到达的状态\n");
						break;
					}
					
				}
				break;
			default:
				break;
			}
			
		}
		i ++;

	}
}

static int total_param_len(struct func_info *fi)
{
	struct param_info *pi;
	int i = 0;
	int total = 0;
	if(!fi)
		return 0;
	pi = fi->param_info;
	for(i = 0; i < pi->param_num; i ++)
	{
		total += ALIGN_LONG(pi->type_info->type_info->len);
	}	
	return total;
}

static int total_param_len_index(struct func_info *fi, int index)
{
	struct param_info *pi;
	int i = 0;
	int total = 0;
	if(!fi)
		return 0;
	pi = fi->param_info;
	for(i = 0; i < index; i ++)
	{
		total += ALIGN_LONG(pi->type_info->type_info->len);
	}	
	return total;
}

/*处理RealParam'生成式*/
static int handle_real_param1(struct GrammerTreeNode *head, FILE *fp, struct func_info *fi, int *index)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	struct variant_info *vi;
	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		if(v->type != FINAL && v->cfg->parent == RP1_CFG)
		{
			handle_real_param1(v, fp, fi, index);
		}
		/*expr*/
		else if(v->type != FINAL && v->cfg->parent == EXPR_CFG)
		{
			if(*index >= fi->param_info->param_num)
			{
				printf("error:\"%s\"传递的参数大于实际的参数%d\n", fi->fi_name, fi->param_info->param_num);
				err_occur = 1;
				return -1;
			}
			vi = handle_expr(v, fp);
			
			/*参数类型比较*/
			//if(type_equal(vi, fi->param_info->type_info + *index) != 0)
			//{
			//	printf("Waring:\"%s\"中传递的实参和形参不一致\n", fi->fi_name);
			//}
			//参数设置
			if(fi->param_info->type_info[*index].type_info->len <= 4)
			{
				fprintf(fp, "\tmovl %%eax, %d(%%esp)\n", total_param_len_index(fi, *index));
			}
			else
			{
				fprintf(fp, "\tmovl %%eax, %d(%%esp)\n", fi->param_info->type_info[*index].vi_addr - 8);
				fprintf(fp, "\tmovl %%ecx, %d(%%esp)\n", fi->param_info->type_info[*index].vi_addr - 4);
			}
			*index += 1;
		}
	}
	return 0;
}

static int handle_real_param(struct GrammerTreeNode *head, FILE *fp, struct func_info *fi)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	int index = 0;

	//无参数函数调用
	if(head->cfg == RP_VOID_CFG)
	{
		if(fi->param_info->param_num == 0)
		{
			return 0;
		}
		else
		{
			printf("error:\"%s\"需要%d个参数，而实际上只提供了0个参数\n", fi->fi_name, fi->param_info->param_num);
			err_occur = 1;
			return -1;
		}
	}
	/*参数有好几个*/
	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		fprintf(fp, "\tsubl $%d, %%esp\n", total_param_len(fi));
		handle_real_param1(v, fp, fi, &index);
	}
	return 0;
	//handle_real_param1(head->)
}

/**
 *  处理函数调用
 **/
static void handle_func_call(struct GrammerTreeNode *head, FILE *fp)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	int i = 0;
	char name[257];
	struct func_info *fi;
	int ret;

	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		switch(i)
		{
		//函数名
		case 0:
			node_to_string(v->value, name);
			fi = get_func_from_table(func_table, name);
			if(!fi)
			{
				printf("Error:函数\"%s\"没有申明和定义\n", name);
				err_occur = 1;
				return;
			}
			break;
		//实参
		case 2:
			//将实参压栈
			ret = handle_real_param(v, fp, fi);
			if(ret == 0)
			{
				/*调用函数恢复栈*/
				fprintf(fp, "\tcall %s\n\taddl $%d, %%esp\n", name, total_param_len(fi));
				break;
			}

		default:
			break;
		}
		i ++;
	}
}

/**
 *  处理for循环
 **/
void handle_for(struct GrammerTreeNode *head, FILE *fp)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	struct GrammerTreeNode *center;//for循环的中间的表达式
	struct GrammerTreeNode *last;//for循环的最后一个表达式
	int h = jmp_label ++;
	int t = jmp_label ++;
	int i = 0;

	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		switch(i)
		{
		case 2:
			handle_statement(v, fp);
			fprintf(fp, "\tjmp .L%d\n.L%d:\n", t, h);
			break;
		case 3:
			center = v;
			break;
		case 4:
			last = v;
			break;
		case 6:
			build_block(v, fp, NULL);
			break;
		}
		i ++;
	}
	handle_statement(last, fp);
	fprintf(fp, ".L%d:\n", t);
	handle_statement(center, fp);
	fprintf(fp, "\tcmpl $0, %%eax\n\tjne .L%d\n", h);
}

/**
 *  处理while循环
 **/
void handle_while(struct GrammerTreeNode *head, FILE *fp)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	int h= jmp_label ++;
	int t= jmp_label ++;
	int i = 0;

	fprintf(fp, "\tjmp .L%d\n", t);
	list_for_each_tail(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		switch(i)
		{
		case 0:
			fprintf(fp, ".L%d:\n", h);
			build_block(v, fp, NULL);
			break;
		case 2:
			fprintf(fp, ".L%d:\n", t);
			handle_expr(v, fp);
			fprintf(fp, "\tcmpl $0, %%eax\n\tjne .L%d\n", h);
			break;
		}
		i ++;
	}

}

/**
 *  处理if
 * ifelse 处理if-else是跳转的位置，如果大于0有效
 **/
void handle_if(struct GrammerTreeNode *head, FILE *fp, int ifelse)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	int label = jmp_label;
	int i = 0;

	jmp_label ++;

	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		switch(i)
		{
		case 2:
			handle_expr(v, fp);
			fprintf(fp, "\tcmpl $0, %%eax\n\tje .%d\n", label);
			break;
		case 4:
			build_block(v, fp, NULL);
			if(ifelse >= 0)
				fprintf(fp, "\tjmp .%d\n", ifelse);
			fprintf(fp, ".%d:\n", label);
			break;
		}
		i ++;
	}
}

/**
 *  处理if-else
 **/
void handle_if_else(struct GrammerTreeNode *head, FILE *fp)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	int i = 0;
	int jmp = jmp_label;

	jmp_label ++;

	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		switch(i)
		{
		case 0:
			handle_if(v, fp, jmp);
			break;
		case 2:
			build_block(v, fp, NULL);
			fprintf(fp, ".%d:\n", jmp);
			return;
		}
		i ++;
	}
}

/**
 *  处理变量定义
 **/
void handle_variant(struct GrammerTreeNode *head, FILE *fp)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	struct variant_info *vi;
	struct variant_info *vi2;
	struct func_info *fi;
	char type[1024];
	char name[257];
	char name2[257];
	int i = 0;
	int ret;

	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		switch(i)
		{
		case 0:
			_get_type(v, type);
			break;
		case 1:
			node_to_string(v->value, name);
			ret = block_add_var_auto(CURRENT_BLOCK, type, name);
			vi = get_variant_from_block(CURRENT_BLOCK, name);
			if(!vi)
				return;
			/*变量重复定义*/
			if(ret == -1)
			{
				printf("error:\"%s重复定义\"\n", name);
				err_occur = 1;
				return;
			}
			fprintf(fp, "//定义变量:%s\n", name);
			fprintf(fp, "\tsubl $%d, %%esp\n", ALIGN_LONG(vi->type_info->len));
			/*如果是非赋值的变量定义*/
			if(head->cfg == TYPEDEF_NONE_CFG)
			{
				return;
			}
			break;
		case 3:
			/*token = token*/
			if(head->cfg == TYPEDEF_TOKEN_CFG)
			{
				node_to_string(v->value, name2);
				vi2 = search_variant(name2);
				/*定义了变量名*/
				if(vi2)
				{
					if(vi2->global)
					{
						fprintf(fp, "\tmovl %s, %%eax\n", name2);
					}
					else
					{
						fprintf(fp, "\tmovl %d(%%ebp), %%eax\n", vi2->vi_addr);
					}
				}
				/*是否是函数名*/
				else
				{
					if(!(fi = get_func_from_table(func_table, name2)))
					{
						printf("error:\"%s\"变量没有定义\n", name2);
						err_occur = 1;
					}
					/*是函数*/
					printf("Waring:用函数指针\"%s\"赋值\"%s\"\n", name2, name);
					fprintf(fp, "\tmovl %s, %%eax\n", name2);
				}
			}
			else if(head->cfg == TYPEDEF_NUMBER_CFG)
			{
				fprintf(fp, "\tmovl $%d, %d(%%ebp)\n", v->value->value_i, vi->vi_addr);
				return;
			}
			else if(head->cfg == TYPEDEF_CALL_CFG) 
			{
				handle_func_call(v, fp);
			}
			fprintf(fp, "\tmovl %%eax, %d(%%ebp)\n", vi->vi_addr);
			break;
		}
		i ++;
	}
}

static void get_str_name(int index, char *buffer)
{
	if(!buffer)
		return;
	sprintf(buffer, ".JEFF_%d", index);
}

/**
 *  处理赋值语句
 **/
void handle_value(struct GrammerTreeNode *head, FILE *fp)
{
	struct list_head *l;
	struct GrammerTreeNode *v;
	int i = 0;
	struct variant_info *vi;
	char name[256];
	char str[1024];
	int index;
	
	list_for_each(l, &head->childs)
	{
		v = list_entry(l, struct GrammerTreeNode, brother);
		switch(i)
		{
		case 0:
			node_to_string(v->value, name);
			vi = search_variant(name);
			if(!vi)
			{
				printf("error:\"%s\"没有定义的变量\n", name);
				err_occur = 1;
				return;
			}
			break;
		case 2:
			/*表达式和函数调用*/
			if(head->cfg == ASSIGN_EXPR_CFG || head->cfg == ASSIGN_CALL_CFG)
			{
				if(head->cfg == ASSIGN_CALL_CFG)
					handle_func_call(v, fp);
				else
					handle_expr(v, fp);
				if(vi->global)
				{
					fprintf(fp, "\tmovl %%eax, %s\n", vi->vi_name);
				}
				else
				{
					fprintf(fp, "\tmovl %%eax, %d(%%ebp)\n", vi->vi_addr);
				}
				return;
			}
			
			/**/
			break;
		case 3:
			/*赋一个字符串*/
			if(head->cfg == ASSIGN_STR_CFG)
			{
				node_to_string(v->value, str);
				index = (int)get(string_table, str);
				if(index == 0)
				{
					index = string_counter;
					insert(string_table, str, (void*)index);
					string_counter ++;
				}
				get_str_name(index, str);
				fprintf(fp, "\tmovl $%s, %%eax\n", str);
				if(vi->global)
				{
					fprintf(fp, "\tmovl %%eax, %s\n", vi->vi_name);
				}
				else
				{
					fprintf(fp, "\tmovl %%eax, %d(%%ebp)\n", vi->vi_addr);
				}
				return;
			}
			break;
		default:
			break;
		}
		i ++;
	}
}

/**
 *  处理return语句
 **/
void handle_return(struct GrammerTreeNode *head, FILE *fp)
{
	struct list_head *l;
	struct GrammerTreeNode *v;

	if(head->cfg == RETURN_EXPR_CFG)
	{
		list_for_each(l, &head->childs)
		{
			v = list_entry(l, struct GrammerTreeNode, brother);
			handle_expr(v, fp);
		}
	}
	fprintf(fp, "\tleave\n\tret\n");
}

static int str_equal(void *k1, void *k2)
{
	return strcmp((char*)k1, (char*)k2);
}

static void* copy_str(void *src)
{
	return src;
}

static void free_str(void *value)
{
	value;
}

/**
 *  语义分析初始化
 **/
int seman_init()
{
	int ret = function_init();
	if(ret < 0)
		return ret;
	root_block =  create_block(NULL, ROOT);
	func_table = create_func_table();
	string_table = hash_new(10, str_equal, copy_str, free_str);
	if(!root_block || !func_table || !string_table)
		return -1;
	CURRENT_BLOCK = root_block;
	return 0;
}

static void hanle_program(struct GrammerTreeNode *root, FILE *fp)
{
	struct list_head *v;
	struct GrammerTreeNode *node;
	

	list_for_each(v, &root->childs)
	{
		node = list_entry(v, struct GrammerTreeNode, brother);
		/*函数定义*/
		if(node->cfg == FUNC_DEF_CFG)
		{
			build_func(node, fp);
		}
		/*main函数,必须在程序前面*/
		else if(node->cfg == MAIN_CFG)
		{
			handle_main(node, fp);
		}
		/*程序*/
		else if(node->cfg && node->cfg->parent == PROGRAM_CFG)
		{
			hanle_program(node, fp);
		}
		/*函数申明*/
		else if(node->cfg == FUNC_STATE_CFG)
		{
			handle_func_state(node, fp);
		}
		/**/
	}
	
}

/**
 *  来，正式进行语义分析
 **/
int process_seman(struct GrammerTreeNode *root, FILE *fp, char *file_name)
{
	HashIter *iter;
	struct HashNode *hn;
	char name[100];
	
	/*打印文件名*/
	fprintf(fp, "\t.file\t\"%s\"\n\t.text\n", file_name);
	/**/
	hanle_program(root, fp);
	/*输出字符串表*/
	iter = hash_create_iter(string_table);
	if(!iter)
	{
		printf("内部错误\n");
		err_occur = 1;
	}
	fprintf(fp, ".section .rodata\n");
	while((hn = hash_next(iter)))
	{
		get_str_name((int)hn->value, name);
		fprintf(fp, "%s:\n", name);
		fprintf(fp, "\t.string \"%s\"\n", hn->key);
	}
	return err_occur;
}






