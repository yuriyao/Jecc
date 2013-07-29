/**
 *  用链表实现的stack
 **/
#include "linear.h"

struct stack_node
{
	struct list_head link;
	void *data;
};

struct stack
{
	int num;
	struct list_head head;
};

/**
 *  创建一个栈
 **/
struct stack* create_stack();

/**
 *  向@stack中压入@data
 *  成功返回0,失败返回1
 **/
int push(struct stack *stack, void *data);

void* top(struct stack *stack);

void* pop(struct stack *stack);

int get_length(struct stack *stack);

int is_empty(struct stack *stack);

//#define STACK_DEBUG