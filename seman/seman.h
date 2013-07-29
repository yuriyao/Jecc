/**
 *  语义分析
 **/
#include "block.h"
#include "GT.h"
#include <stdio.h>

/*cfg信息*/
 /*函数*/
extern struct CFG cfg37;
extern struct CFG cfg21;
extern struct CFG cfg0;
/*类型*/
extern struct CFG cfg22;
extern struct CFG cfg23;
extern struct CFG cfg24;
extern struct CFG cfg25;
extern struct CFG cfg26;
extern struct CFG cfg27;
/*Paramlist*/
extern struct CFG cfg34;
extern struct CFG cfg52;
/*Program*/
extern struct CFG cfg8;
extern struct CFG cfg9;
/*Block*/
extern struct CFG cfg60;
extern struct CFG cfg61;
/*Statement*/
extern struct CFG cfg45;
/*If*/
extern struct CFG cfg72;
/*for*/
extern struct CFG cfg7;
/*while*/
extern struct CFG cfg55;
/*if else*/
extern struct CFG cfg13;
/*实参*/
extern struct CFG cfg15;
extern struct CFG cfg28;
/*expr*/
extern struct CFG cfg38;
extern struct CFG cfg39;
extern struct CFG cfg40;
extern struct CFG cfg41;
extern struct CFG cfg42;
extern struct CFG cfg43;
extern struct CFG cfg44;
/*Typedef*/
extern struct CFG cfg1;
extern struct CFG cfg2;
extern struct CFG cfg3;
extern struct CFG cfg4;
extern struct CFG cfg5;
/*Assign*/
extern struct CFG cfg56;
extern struct CFG cfg57;
extern struct CFG cfg58;
extern struct CFG cfg59;
/*Return*/
extern struct CFG cfg18;
extern struct CFG cfg19;
extern struct CFG cfg20;

/*函数定义*/
#define FUNC_DEF_CFG (&cfg37) 
/*函数调用*/
#define FUNC_CALL_CFG (&cfg21)
/*函数声明*/
#define FUNC_STATE_CFG (&cfg0)
/*函数列表*/
#define PARAM_LIST_CFG (&cfg34)
/*函数列表'*/
#define PARAM_LIST1_CFG (&cfg52)
/*类型*/
#define TYPE_CFG (&cfg22)
#define TYPE_STRUCT_CFG (&cfg27)
/*Program*/
#define PROGRAM_CFG (&cfg8)
#define MAIN_CFG (&cfg9)
/*Block*/
#define BLOCK_CFG (&cfg60)
#define BLOCK1_CFG (&cfg61)
/*statement*/
#define STATEMENT_CFG (&cfg45)
/*if*/
#define IF_CFG (&cfg72)
/*for*/
#define FOR_CFG (&cfg7)
/*while*/
#define WHILE_CFG (&cfg55)
/*ifelse*/
#define IF_ELSE_CFG (&cfg13) 
/*实参*/
#define RP_VOID_CFG (&cfg15)
#define RP1_CFG (&cfg28)
/*expr*/
#define EXPR_CFG (&cfg38)
#define EXPR_NUMBER_CFG (&cfg39)
#define EXPR_TOKEN_CFG (&cfg40)
#define EXPR_ADD_CFG (&cfg41)
#define EXPR_SUB_CFG (&cfg42)
#define EXPR_MULTI_CFG (&cfg43)
#define EXPR_DIV_CFG (&cfg44)
/*Typedef*/
#define TYPEDEF_CFG (&cfg1)
#define TYPEDEF_NONE_CFG (&cfg2)
#define TYPEDEF_TOKEN_CFG (&cfg3)
#define TYPEDEF_NUMBER_CFG (&cfg4)
#define TYPEDEF_CALL_CFG (&cfg5)
/*Assign*/
#define ASSIGN_CFG (&cfg56)
#define ASSIGN_CALL_CFG (&cfg57)
#define ASSIGN_EXPR_CFG (&cfg58)
#define ASSIGN_STR_CFG (&cfg59)
/*Return*/
#define RETURN_CFG (&cfg18)
#define RETURN_NONE_CFG (&cfg19)
#define RETURN_EXPR_CFG (&cfg20)

/**
 *  获得有严谨格式的类型字符串
 **/
//void get_type(struct GrammerTreeNode *head, char *buffer);

