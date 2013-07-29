/**
 *  语法分析生成的语法树
 **/

#ifndef GT_H
#define GT_H
 
#include "token.h"
#include "mm.h"
#include "linear.h"
#include "state.h"


 #define FINAL (-100)
 
//语法树的节点
struct GrammerTreeNode
{
	//语法类型
	int type;
	//父亲节点
	struct GrammerTreeNode *parent;
	//指向儿子节点列表的指针
	struct list_head childs;
	//指向兄弟节点
	struct list_head brother;
	//节点的数据
	struct TokenNode *value;
	//产生式
	struct CFG *cfg;
	
};

/**
 *  将多个子树合成一个树，返回根节点
 *  @num  语法子树的数量
 *  @type 生成的语法树根结点的类型
 *  @value 符号表节点的数据
 *  ...    子树
 **/
struct GrammerTreeNode* to_one_tree(int num, int type, void *value, ...);

struct GrammerTreeNode* to_one_tree2(int num, int type, void *value, struct GrammerTreeNode **trees);

//
struct GrammerTreeNode *create_GTNode(int type, void *value);
//struct 

//广搜
void wfs(FILE *fp, struct GrammerTreeNode *root);

#endif