/**
 *  gcc -o stack stack.c linear.c ../word_analysis/mm.c -I ../word_analysis
 **/
#include "stack.h"
#include "mm.h"
#include <stdio.h>
/**
 *  创建一个栈
 **/
struct stack* create_stack()
{
	struct stack *stack = (struct stack*)mm_malloc(sizeof(struct stack));
	if(!stack)
		return NULL;
	INIT_LIST_HEAD(&stack->head);
	stack->num = 0;
	return stack;
}

/**
 *  向@stack中压入@data
 *  成功返回0,失败返回-1
 **/
int push(struct stack *stack, void *data)
{
	struct stack_node *node;
	if(!stack)
		return -1;

	node = (struct stack_node*)mm_malloc(sizeof(struct stack));	
	if(!node)
		return -1;

	node->data = data;
	insert_head(&stack->head, &node->link);
	stack->num ++;
	return 0;
}

void* top(struct stack *stack)
{
	struct stack_node *node;
	if(!stack || !stack->num)
		return NULL;
	node = list_entry((stack->head.next), struct stack_node, link);
	return node->data;
}

void* pop(struct stack *stack)
{
	struct list_head *node = del_head(&stack->head);
	struct stack_node *stack_node;
	void *data;
	if(!node)
		return NULL;
	stack_node = list_entry(node, struct stack_node, link);
	stack->num --;
	data = stack_node->data;
	mm_free(stack_node);
	return data;
}

int get_length(struct stack *stack)
{
	if(!stack)
		return -1;
	return stack->num;
}

int is_empty(struct stack *stack)
{
	return (stack->num == 0);
}


#ifdef STACK_DEBUG
int main(int argc, char **argv)
{
	struct stack *stack = create_stack();
	int i = 0;
	for(; i < 10; i ++)
		push(stack, (void*)i);
	for(i = 0; i < 3; i ++)
		printf("Top:%d\n", (int)top(stack));
	for(i = 0; i < 20; i ++)
	{
		printf("The len is %d, empty %d\n", get_length(stack), is_empty(stack));
		printf("%d\n", (int)pop(stack));
	} 
}
#endif