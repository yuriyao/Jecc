/**
 *  c的通用双向循环链表,有表头
 *  Author:Jeff yao,IBM TC
 **/
#ifndef LINEAR_H
#define LINEAR_H
struct list_head
{
	struct list_head *next;
	struct list_head *prev;
};

#define contain_of(ptr, type, member)\
	((type*)((unsigned long)(ptr) - (unsigned long)&(((type*)0)->member)))

#define INIT_LIST_HEAD(lhp)\
do{\
	(lhp)->next = (lhp);\
	(lhp)->prev = (lhp);\
}while(0)

int insert_next(struct list_head *node, struct list_head *new);

int insert_prev(struct list_head *node, struct list_head *new);

int insert_head(struct list_head *head, struct list_head *new);

int insert_tail(struct list_head *head, struct list_head *new);

struct list_head* list_del(struct list_head *node);

struct list_head* del_head(struct list_head *head);

struct list_head* del_tail(struct list_head *head);

#define list_for_each(t, head)\
	for(t = (head)->next; t != (head); t = t->next)

#define list_entry(ptr, type, member)\
		contain_of(ptr, type, member)

//从后向前遍历
#define list_for_each_tail(t, head)\
	for(t = (head)->prev; t != head; t = t->prev)
//#define LINEAR_DEBUG
#endif