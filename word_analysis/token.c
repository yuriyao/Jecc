/**
 * 符号表
 * 测试:gcc -o token token.c
 **/
#include "token.h"
#include "word_analysis.h"
#include "mm.h"
#include "tool.h"

#include <string.h>
#include <assert.h>

/*有表头*/
static struct TokenNode* table_head;
static struct TokenNode* table_tail;

/*没有申请成功内存，直接退出，调用函数不用检查返回值*/
struct TokenNode* MALLOC_AND_INIT(int line, int type)
{
	struct TokenNode *_ret = (struct TokenNode*)mm_malloc(sizeof(struct TokenNode));
	if(!_ret) exit_for_nomem();
	_ret->type = (int)type;
	_ret->lineno = (int)line;
	_ret->next = (struct TokenNode*)0;
	return _ret;
}

/*增加一个节点到末尾*/
#define ADD_TO_TAIL(p) \
do{\
	table_tail->next = p;\
	table_tail = p;\
}while(0)

void table_init()
{
	table_head = MALLOC_AND_INIT(0, 0);
	table_tail = table_head;
}


void table_add_int(int i, int line)
{
	struct TokenNode *t = MALLOC_AND_INIT(line, INT);
	t->value_i = i;
	ADD_TO_TAIL(t);
}

void table_add_char(char ch, int type, int line)
{
	struct TokenNode *t = MALLOC_AND_INIT(line, type);
	t->value_c = ch;
	ADD_TO_TAIL(t);
}

void table_add_float(float f, int line)
{
	struct TokenNode *t = MALLOC_AND_INIT(line, FLOAT);
	t->value_f = f;
	ADD_TO_TAIL(t);
}

void table_add_string(char *cp, int type, int line)
{
	debug_on(!cp);
	struct TokenNode *t = MALLOC_AND_INIT(line, type);
	char *cp2 = (char*)mm_malloc(strlen(cp) + 1);
	strcpy(cp2, cp);
	t->value_p = cp2;
	ADD_TO_TAIL(t);
}

void table_add_double(double d, int line)
{
	struct TokenNode *t = MALLOC_AND_INIT(line, DOUBLE);
	t->value_d = d;
	ADD_TO_TAIL(t);
}

void table_add_chs(char *chs, int type, int line)
{
	struct TokenNode *t = MALLOC_AND_INIT(line, type);
	t->value_chs[0] = chs[0];
	t->value_chs[1] = chs[1];
	ADD_TO_TAIL(t);
}


struct TokenNode* create_iter()
{
    return table_head;
}

struct TokenNode* next(struct TokenNode **iter)
{
    struct TokenNode *v = (struct TokenNode*)0;
    assert(*iter);
    if((*iter)->next)
    {
        *iter = (*iter)->next;
        v = *iter;
    }
    return v;
}

/*struct TokenNode* prev(iter)
{
    struct TokenNode *v = (struct TableNode*)0;
    assert(iter);
    if(iter != table_head)

}*/

void print_token(FILE *fp, struct TokenNode *t)
{
	switch(t->type)
	{
		case KEYWORD:
		case TOKEN:
		case STRING:
			fprintf(fp, "(%d_%d, %s) ", t->type, strlen(t->value_p), t->value_p);
			break;
		case CHAR:
		case PLUS:
		case MINUS:
		case MULTI:
		case DIVIDE:
		case MOD:
		case EQUAL:
		case AND:
		case OR:
		case XOR:
		case NOT:
		case L_PARENT:
		case R_PARENT:
		case L_BRACKET:
		case R_BRACKET:
		case L_BPARENT:
		case R_BPARENT:
		case L_QUOTA:
		case R_QUOTA:
		case LG:
		case GT:
		case L_SQUOTA:
		case R_SQUOTA:
		case STAR:
		case SEMICOLON:
		case QUESTION:
		case COLON:
		case POINT:
		case COMMA:
			fprintf(fp, "(%d, %c) ", t->type, t->value_c);
			break;
		case INT:
			fprintf(fp, "(%d, %d) ", t->type, t->value_i);
			break;
		case FLOAT:
			fprintf(fp, "(%d, %f) ", t->type, t->value_f);
			break;
		case DOUBLE:
			fprintf(fp, "(%d, %lf) ", t->type, t->value_d);
			break;
		default:
			fprintf(fp, "(%d, %c%c) ", t->type, t->value_chs[0], t->value_chs[1]);
			break;
	}
}

/*输出到文件*/
void table_serial(FILE *fp)
{
	struct TokenNode* t = table_head->next;
	int line = 0;
	while(t)
	{
		if(line != t->lineno)
		{
			line = t->lineno;
			fprintf(fp, "\nline %d:", line);
		}
		switch(t->type)
		{
		case KEYWORD:
		case TOKEN:
		case STRING:
			fprintf(fp, "(%d_%d, %s),", t->type, strlen(t->value_p), t->value_p);
			break;
		case CHAR:
		case PLUS:
		case MINUS:
		case MULTI:
		case DIVIDE:
		case MOD:
		case EQUAL:
		case AND:
		case OR:
		case XOR:
		case NOT:
		case L_PARENT:
		case R_PARENT:
		case L_BRACKET:
		case R_BRACKET:
		case L_BPARENT:
		case R_BPARENT:
		case L_QUOTA:
		case R_QUOTA:
		case LG:
		case GT:
		case L_SQUOTA:
		case R_SQUOTA:
		case STAR:
		case SEMICOLON:
		case QUESTION:
		case COLON:
		case POINT:
		case COMMA:
			fprintf(fp, "(%d, %c),", t->type, t->value_c);
			break;
		case INT:
			fprintf(fp, "(%d, %d),", t->type, t->value_i);
			break;
		case FLOAT:
			fprintf(fp, "(%d, %f),", t->type, t->value_f);
			break;
		case DOUBLE:
			fprintf(fp, "(%d, %lf),", t->type, t->value_d);
			break;
		default:
			fprintf(fp, "(%d, %c%c),", t->type, t->value_chs[0], t->value_chs[1]);
			break;
		}
		t = t->next;
	}
}


int node_to_string(struct TokenNode *t, char *buffer)
{
	switch(t->type)
	{
		case KEYWORD:
		case TOKEN:
		case STRING:
			sprintf(buffer, "%s", t->value_p);
			break;
		case CHAR:
		case PLUS:
		case MINUS:
		case MULTI:
		case DIVIDE:
		case MOD:
		case EQUAL:
		case AND:
		case OR:
		case XOR:
		case NOT:
		case L_PARENT:
		case R_PARENT:
		case L_BRACKET:
		case R_BRACKET:
		case L_BPARENT:
		case R_BPARENT:
		case L_QUOTA:
		case R_QUOTA:
		case LG:
		case GT:
		case L_SQUOTA:
		case R_SQUOTA:
		case STAR:
		case SEMICOLON:
		case QUESTION:
		case COLON:
		case POINT:
		case COMMA:
			sprintf(buffer, "%c", t->value_c);
			break;
		case INT:
			sprintf(buffer, "%d", t->value_i);
			break;
		case FLOAT:
			sprintf(buffer, "%f", t->value_f);
			break;
		case DOUBLE:
			sprintf(buffer, "%lf", t->value_d);
			break;
		default:
			sprintf(buffer, "%c%c", t->value_chs[0], t->value_chs[1]);
			break;
	}
	return strlen(buffer);
}

/*从文件中解析出符号表*/
void table_load(FILE *fp)
{

}

//#define TOKEN_DEBUG

#ifdef TOKEN_DEBUG
int main(int argc, char **argv)
{
	FILE *f = fopen("token.txt", "w");
	table_init();
	table_add_int(10, 1);
	table_add_int(20, 2);
	table_add_string("HELLO_WORLD", TOKEN, 2);
	table_add_string("I am ", KEYWORD, 3);
	table_serial(f);
}
#endif

