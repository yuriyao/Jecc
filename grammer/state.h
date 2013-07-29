/**
 *  语法分析器
 **/
//#include "GT.h"
#ifndef STATE_H
#define STATE_H

enum GI
{
    //移进
    GI_SHIFT = 0,
    //接受
    GI_ACC = 1,
    //出错
    GI_ERR = 2,
    //归约
    GI_REDUCE = 3,
    //是goto表的项
    GI_GOTO = 4,
};

//语法分析器的状态项
struct GrammerItem
{	
    //类型
    int type;
    union
    {
        //转移到的状态
        int _skip;
        //使用的归约的产生式
        struct CFG *_cfg;
    }action;
#define gi_skip action._skip
#define gi_cfg action._cfg
};

//产生式
struct CFG
{
    //产生式的表示
    char *name;
    //处理函数,用于语义分析
    int (*process)(/*struct GrammerTreeNode *root*/);
    //指向父产生式
    struct CFG *parent;
    //产生式的项数,如果是总的产生式，这一项为-1
    int items;
    //goto表中的索引
    int row;
};



/*struct GrammerGoTo
{
    int skip;
    int 
};*/

//语法类型的定义
/*enum GrammerType{
	//表达式
	EXPRESS,
	//函数定义
	FUNCTION,
	//函数申明
	FUNCTION_EXTERN,
	//变量定义
	VARIOUS,
	//变量申明
	VARIOUS_EXTERN,
	FOR,
	WHILE,
	DO_WHILE,
	IF,
	ELSE_IF,
	ELSE,
	SWITCH,
	//参数
	PARAM,
	//参数列表
	PARAM_LIST
};*/

#endif
