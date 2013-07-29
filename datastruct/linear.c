/**
 *  gcc -o linear linear.c
 **/
#include "linear.h"
#include <stdlib.h>

int insert_next(struct list_head *node, struct list_head *new)
{
	if(!node || !new)
		return 0;
	node->next->prev = new;
	new->next = node->next;
	node->next = new;
	new->prev = node;
	return 1;
}

int insert_prev(struct list_head *node, struct list_head *new)
{
	return insert_next(node->prev, new);
}

int insert_head(struct list_head *head, struct list_head *new)
{
	return insert_next(head, new);
}

int insert_tail(struct list_head *head, struct list_head *new)
{
	return insert_prev(head, new);
}

struct list_head* list_del(struct list_head *node)
{
	if(!node)
		return NULL;
	node->next->prev = node->prev;
	node->prev->next = node->next;
	return node;
}

struct list_head* del_head(struct list_head *head)
{
	if(!head || head->next == head)
		return NULL;
	return list_del(head->next);
}

struct list_head* del_tail(struct list_head *head)
{
	if(!head || head->next == head)
		return NULL;
	return list_del(head->prev);
}

#ifdef LINEAR_DEBUG
#include <stdio.h>
struct test
{
	int a;
	int b;
	char *c;
};

struct Demo
{
	int val;
	struct list_head next;
};

int main(int argc, char **argv)
{
	struct test *vs;
	struct test test = {1, 2, "123"};
	int i = 0;

	struct Demo head;
	struct Demo *v;
	struct list_head *list;

	INIT_LIST_HEAD(&head.next);
	for(i = 0; i < 10; i ++)
	{
		v = (struct Demo*)malloc(sizeof(struct Demo));
		v->val = i;
		insert_head(&head.next, &v->next);
	}
	for(i = 21; i < 30; i ++)
	{
		v = (struct Demo*)malloc(sizeof(struct Demo));
		v->val = i;
		insert_tail(&head.next, &v->next);
	}
	list_for_each(list, &head.next)
	{
		v = list_entry(list, struct Demo, next);
		printf("%d ", v->val);
	}	
	printf("\n");
	for(i = 0; i < 5; i ++)
		del_head(&head.next);

	list_for_each(list, &head.next)
	{
		v = list_entry(list, struct Demo, next);
		printf("%d ", v->val);
	}
	printf("\n");
	for(i = 0; i < 5; i ++)
		del_tail(&head.next);

	list_for_each(list, &head.next)
	{
		v = list_entry(list, struct Demo, next);
		printf("%d ", v->val);
	}
	printf("\n");
	return 0;
}
#endif