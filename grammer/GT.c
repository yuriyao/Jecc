/**
 *  gcc -o GT GT.c ../datastruct/linear.c ../word_analysis/token.c ../word_analysis/mm.c -I ../datastruct/ -I ../word_analysis
 **/

#include "GT.h"
#include <stdarg.h>

struct GrammerTreeNode *create_GTNode(int type, void *value)
{
	struct GrammerTreeNode *v = (struct GrammerTreeNode*)mm_malloc(sizeof(struct GrammerTreeNode));
	if(!v)
		return NULL;
	//memset(v, 0, sizeof(*v));
	v->type = type;
	if(type == FINAL)
		v->value = (struct TokenNode*)value;
	else
		v->cfg = (struct CFG*)value;
	v->parent = NULL;
	INIT_LIST_HEAD(&v->childs);
	INIT_LIST_HEAD(&v->brother);
	return v;
}

struct GrammerTreeNode* to_one_tree(int num, int type, void *value, ...)
{
	struct GrammerTreeNode *v = create_GTNode(type, value);
	int i = 0;
	struct GrammerTreeNode *t;
	va_list va;
	if(!v)
		return NULL;
	va_start(va, value);
	for(i = 0; i < num; i ++)
	{
		t = va_arg(va, struct GrammerTreeNode*);
		insert_tail(&v->childs, &t->brother);
		t->parent = v;
	}
	va_end(va);
	return v;
}

struct GrammerTreeNode* to_one_tree2(int num, int type, void *value, struct GrammerTreeNode **trees)
{
	struct GrammerTreeNode *v = create_GTNode(type, value);
	int i = 0;
	struct GrammerTreeNode *t;

	if(!v)
		return NULL;

	for(i = 0; i < num; i ++)
	{
		t = trees[i];
		insert_tail(&v->childs, &t->brother);
		t->parent = v;
	}

	return v;
}

//用于广度优先搜索的节点
struct wfs_type
{
	struct GrammerTreeNode *node;
	struct list_head list;
	int new_line;
};


static void wfs_begin(FILE *fp, struct list_head *list)
{
	struct list_head *v = del_head(list);
	//struct list_head temp;
	struct wfs_type *w;
	struct wfs_type *t = NULL;
	struct list_head *l;
	//
	struct GrammerTreeNode *c;
	//处理队列头
	if(!v)
		return;
	w = list_entry(v, struct wfs_type, list);
	if(w->node->type != FINAL)
	{
		if(!w->node->cfg)
			fprintf(fp, "(type-%d) ", w->node->type);
		else
			fprintf(fp, "(%s) ", w->node->cfg->name);
	}
	else
		print_token(fp, w->node->value);
	if(w->new_line)
		fprintf(fp, "\n");
	//将队列头的孩子节点加入列表头
	//INIT_LIST_HEAD(&temp);
	list_for_each(l, &w->node->childs)
	{
		c = list_entry(l, struct GrammerTreeNode, brother);
		t = (struct wfs_type*)mm_malloc(sizeof(struct wfs_type));
		t->new_line = 0;
		t->node = c;
		if(!t)
			return;
		insert_tail(list, &t->list);
	}
	if(t)
		t->new_line = 1;
	//if()
	mm_free(w);
	wfs_begin(fp, list);
}

void wfs(FILE *fp, struct GrammerTreeNode *root)
{
	struct list_head list;
	struct wfs_type *node;
	INIT_LIST_HEAD(&list);
	node = (struct wfs_type*)mm_malloc(sizeof(struct wfs_type));
	if(!node)
		return;
	node->node = root;
	node->new_line = 1;
	insert_head(&list, &node->list);
	wfs_begin(fp, &list);
}

//#define GT_DEBUG

#ifdef GT_DEBUG
#include "word_analysis.h"
int main(int argc, char **argv)
{
	int i = 0;
	struct GrammerTreeNode *v[20];
	struct GrammerTreeNode *head;
	struct TokenNode *node = (struct TokenNode*)mm_malloc(sizeof(struct TokenNode));
	node->type = KEYWORD;
	node->value_p = "int";
	FILE *fp = fopen("hello", "w");
	if(!fp)
		return 0;
	for(i = 0; i < 20; i ++)
	{
		v[i] = create_GTNode(i, NULL);
	}
	v[2]->type = FINAL;
	v[2]->value = node;
	head = to_one_tree(5, 0, NULL, v[0], v[1], v[2], v[3], v[4]);
	head = to_one_tree(5, 0, NULL, head, v[5], v[6], v[7], v[8]);
	head = to_one_tree(5, 0, NULL, head, v[9], v[10], v[11], v[12]);
	v[13] = head;
	head = to_one_tree2(5, 0, NULL, v + 13);
	wfs(fp, head);
	return 0;
}
#endif


