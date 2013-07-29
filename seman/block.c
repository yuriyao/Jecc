/**
 *  代码块
 *  gcc -o block -g block.c function.c ../word_analysis/mm.c ../word_analysis/hash.c -I ../word_analysis
 **/
#include "block.h"
#include <assert.h>
#include <stdio.h>

static int var_equal(void *k1, void *k2)
{
	return strcmp((const char*)k1, (const char*)k2);
}

static void* copy_var(void *src)
{
	return src;
}

static void free_var(void *value)
{
	return;
}

struct block_info *current_block;

/**
 *  创建一个代码块
 **/
struct block_info* create_block(struct block_info *parent, int type)
{
	struct block_info* block = (struct block_info*)mm_malloc(sizeof(struct block_info));
	block->var_table = hash_new(10, var_equal, copy_var, free_var);
	if(!block->var_table)
	{
		mm_free(block);
		return NULL;
	}
	block->parent = parent;
	block->type = type;
	if(type == NORMAL)
	{
		block->addr = parent->addr;
	}
	else
		block->addr = -20;
	return block;
}

/**
 *  删除一个代码块
 **/
void del_block(struct block_info* block)
{
	struct HashTable *var_table;
	if(!block)
		return;
	var_table = block->var_table;
	mm_free(block);
	/*清除hash表，没有实现这个函数，忘了！！shit，内存泄露了，shit!!*/
}

struct variant_info* get_variant_from_block(struct block_info *block, char *name)
{
	struct HashTable *type_table;
	if(!block || !name)
		return NULL;
	type_table = block->var_table;
	assert(type_table);
	return (struct variant_info*)get(type_table, name);
}

/**
 *  添加一个变量到@block
 *  block  程序块
 *  type   变量类型
 *  name   变量名
 *  如果变量在这个程序块中已经存在，返回-1,其他错误返回-2,成功返回0
 **/
int block_add_var(struct block_info *block, char *type, char *name, void *addr)
{
	struct variant_info *vi;
	if(!block || !type || !name)
		return -2;
	/*检查是否已经存在这个变量*/
	vi = get_variant_from_block(block, name);
	if(vi)
	{
		return -1;
	}
	/*创建一个变量信息*/
	vi = create_variant_info(type, name);
	if(!vi)
		return -1;
	assert(block->var_table);
	variant_set_addr(vi, addr, block->type == ROOT);
	insert(block->var_table, name, (void*)vi);
	return 0;
}

int block_add_var_var(struct block_info *block, struct variant_info *vi, void *addr)
{
	struct variant_info *vi2;
	if(!block || !vi)
		return -2;

	vi2 = get_variant_from_block(block, vi->vi_name);
	if(vi2)
		return -1;
	variant_set_addr(vi, addr, block->type == ROOT);
	insert(block->var_table, vi->vi_name, (void*)vi);
	return 0; 
}

struct variant_info* search_variant(char *name)
{
	struct block_info *block = current_block;
	struct variant_info *vi;
	while(block)
	{
		vi = get_variant_from_block(block, name);
		if(vi)
			return vi;
		block = block->parent;
	}
	return NULL;
}

/**
 *  添加一个变量到程序块中
 *  变量的地址由程序自动分配
 *  如果变量在这个程序块中已经存在，返回-1,其他错误返回-2,成功返回0
 **/
int block_add_var_var_auto(struct block_info *block, struct variant_info *vi)
{
	struct variant_info *vi2;

	if(!block)
		return -2;
	
	vi2 = get_variant_from_block(block, vi->vi_name);
	if(vi2)
		return -1;
	variant_set_addr(vi, block->addr, 0);
	insert(block->var_table, vi->vi_name, (void*)vi);
	/**/
	block->addr -= ALIGN_LONG(vi->type_info->len);
	return 0; 
}

/**
 * 添加一个变量到程序块中
 * 变量的地址由程序自动分配
 * 如果变量在这个程序块中已经存在，返回-1,其他错误返回-2,成功返回0
 **/
int block_add_var_auto(struct block_info *block, char *type, char *name)
{
	struct variant_info *vi;
	vi = create_variant_info(type, name);
	if(!vi)
		return -2;
	return block_add_var_var_auto(block, vi);

}

#ifdef BLOCK_DEBUG

static void print_type_info(struct type_info *ti)
{
	if(!ti)
	{
		printf("ti:<NULL>\n");
		return;
	}
	printf("is_struct:%d ref:%d pointer_level:%d len %d ", ti->is_struct, ti->ref, ti->pointer_level, ti->len);
	if(ti->is_struct)
	{
		printf("name:%s ", ti->si->name);
	}
	else
		printf("name:%s ", ti->ti_name);
}

static void print_variant_info(struct variant_info *vi)
{
	if(!vi)
	{
		printf("vi:<NULL>\n");
		return ;
	}
	printf("vi_name:%s global:%d ", vi->vi_name, vi->global);
	print_type_info(vi->type_info);
	if(vi->global)
	{
		printf("addr:%s\n", vi->vi_addr_p);
	}
	else
		printf("addr:%d\n", vi->vi_addr);
}



int main(int argc, char **argv)
{
	struct block_info *block = create_block(NULL, ROOT);
	struct variant_info *vi;
	char *types[] = {"struct fuck", "struct bitch**", "int", "void*", "char*", "char*"};
	char *names[] = {"foreya", "alongso", "jeff", "yuri", "foreya", "jeff"};
	char *addrs[] = {".foreya", ".alongso", ".jeff", ".yuri", ".foreya", ".jeff"};
	int i = 0;

	vi = get_variant_from_block(block, "hello");
	printf("%p\n", vi);

	for(i = 0; i < sizeof(addrs) / sizeof(char*); i ++)
	{
		int ret = block_add_var(block, types[i], names[i], addrs[i]);
		printf("%d\n", ret);
	}
	for(i = 0; i < sizeof(addrs) / sizeof(char*); i ++)
	{
		print_variant_info(get_variant_from_block(block, names[i]));
	}
}
#endif