/**
 *  程序块
 **/
#include "hash.h"
#include "function.h"

/**
 *  代码块
 **/
struct block_info
{
	/*局部变量名表*/
	struct HashTable *var_table;
	struct block_info *parent;
	/*用于分配栈的地址*/
	int addr;
	/*代码块的类型*/
	int type;
/*代码块的类型*/
//函数
#define FUNCTION 0
//根
#define ROOT 1
//普通的代码块
#define NORMAL 2
};
extern struct block_info * current_block;
/*当前正在处理的代码块*/
#define CURRENT_BLOCK current_block
/*转换当前的代码块*/
#define change_block(current) (current_block = current)

/**
 *  创建一个代码块
 **/
struct block_info* create_block(struct block_info *parent, int type);
/**
 *  删除一个代码块
 **/
void del_block(struct block_info* block);

/**
 *  添加一个变量到@block
 *  block  程序块
 *  type   变量类型
 *  name   变量名
 *  如果变量在这个程序块中已经存在，返回-1,其他错误返回-2,成功返回0
 **/
int block_add_var(struct block_info *block, char *type, char *name, void *addr);

/**
 *  添加一个变量到@block
 *  如果变量在这个程序块中已经存在，返回-1,其他错误返回-2,成功返回0
 **/
int block_add_var_var(struct block_info *block, struct variant_info *vi, void *addr);

/**
 *  添加一个变量到程序块中
 *  变量的地址由程序自动分配
 **/
int block_add_var_var_auto(struct block_info *block, struct variant_info *vi);

/**
 * 添加一个变量到程序块中
 * 变量的地址由程序自动分配
 **/
int block_add_var_auto(struct block_info *block, char *type, char *name);
/**
 *  从代码块@block中获得@name的变量信息
 *  block  代码块
 *  name   变量名
 **/
struct variant_info* get_variant_from_block(struct block_info *block, char *name);

/**
 *  从当前的程序块开始，搜索变量名
 **/
struct variant_info* search_variant(char *name);



//#define BLOCK_DEBUG

