/**
 *  符号表管理
 */ 
#ifndef TOKEN_H
#define TOKEN_H
#include <stdio.h>

/*符号表节点*/
struct TokenNode
{
    //符号表类型
    int type;
    //符号表数据
    union
    {
        int i;
        float f;
        char c;
        char* p;
        double d;
        char chs[2];
    } value;
#define value_i value.i
#define value_f value.f
#define value_c value.c
#define value_p value.p
#define value_d value.d
#define value_chs value.chs

    //行号
    int lineno;
    //下一个节点
    struct TokenNode *next;
};

void table_add_int(int i, int line);

void table_add_char(char ch, int type, int line);

void table_add_float(float, int line);

void table_add_string(char*, int type, int line);

void table_add_double(double, int line);

void table_add_chs(char *chs, int type, int line);

/*输出到文件*/
void table_serial(FILE *fp);

/*从文件中解析出符号表*/
void table_load(FILE *fp);

/*创建一个遍历节点的迭代器*/
struct TokenNode* create_iter();

/*获得下一个节点*/
struct TokenNode* next(struct TokenNode **iter);
/**/
int node_to_string(struct TokenNode *node, char *buffer);
/*回退一个节点*/
//struct TokenNode* prev(struct TokenNode *iter);

void table_init();

void print_token(FILE *fp, struct TokenNode *t);

#endif
