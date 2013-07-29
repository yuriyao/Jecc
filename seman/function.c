/**
 *  类型系统和函数系统
 *  gcc -o function function.c ../word_analysis/mm.c ../word_analysis/hash.c -I ../word_analysis
 **/
#include "function.h"
#include "hash.h"
#include "mm.h"
#include <stdio.h>
#include <string.h>

/*保存和用于快速检索类型信息的哈希表*/
static struct HashTable *type_hash;
/*保存用于函数信息快速检索的哈希表*/
static struct HashTable* func_hash;
/**/
static struct type_info* _create_type_info(int is_struct, char *name, int pointer_level, int len, char *full_name);
/*比较两种类型是否相同*/
int type_equal(struct type_info *t1, struct type_info *t2)
{
	if(t1 == NULL || t2 == NULL)
	{
		printf("Waring:Compare two null type pointer\n");
		return -1;
	}
	//比较两个指针
	if(t1 == t2)
		return 0;
	/*指针的元数必须相等*/
	if(t1->pointer_level != t1->pointer_level)
		return -1;
	//比较指针的内容
	/*是结构体类型*/
	if(t1->is_struct && t2->is_struct)
	{
		if(t1->si && t2->si)
		{
			if(strcmp(t1->si->name, t2->si->name) == 0)
				return 0;
		}
	}
	/*是普通的类型*/
	else if(!t1->is_struct && !t2->is_struct)
	{
		if(strcmp(t1->ti_name, t1->ti_name) == 0)
			return 0;
	}
	return -1;
}

static int _type_equal(void *t1, void *t2)
{
	return strcmp((char*)t1, (char*)t2);
}

static void* _copy_type(void *src)
{
	return src;
}

static void free_type(void *value)
{
	value;
	return;
}

struct type_info* create_type_info(char *_name, int len)
{
	char buffer[260];
	char *name = buffer;
	char *chr;
	int level = 0;
	int is_struct;
	struct type_info *t;
	if(!_name)
		return NULL;
	/*检查是否已经存在这种类型*/
	if((t = (struct type_info*)get(type_hash, _name)))
	{
		/*增加引用计数*/
		t->ref ++;
		return t;
	}

	strcpy(name, _name);
	chr = strchr(name, ' ');
	if(!chr)
	{
		is_struct = 0;
	}
	else
	{
		if(chr[1] == '*')
			is_struct = 0;
		else
		{
			is_struct = 1;
			name = ++ chr;
		}
	}
	chr = strchr(name, '*');
	if(chr)
	{
		while(*chr == '*')
		{
			chr[-1] = '\0';
			chr += 2;
			level ++;
		}
	}
	return _create_type_info(is_struct, name, level, len, _name);
}

static struct type_info* _create_type_info(int is_struct, char *name, int pointer_level, int len, char *full_name)
{
	struct type_info *ret;
	char *_name;
	if(!name)
		return NULL;

	ret = (struct type_info*)mm_malloc(sizeof(struct type_info));
	if(!ret)
		return NULL;
	_name = (char *)mm_malloc(sizeof(char) * (strlen(name) + 1));
	if(!_name)
	{
		mm_free(ret);
		return NULL;
	}
	strcpy(_name, name);

	is_struct = is_struct ? 1 : 0;

	if(is_struct)
	{
		ret->si = (struct struct_info*)mm_malloc(sizeof(struct struct_info));
		if(!ret->si)
		{
			mm_free(ret);
			mm_free(_name);
			return NULL;
		}
		ret->si->name = _name;
	}
	else
	{
		ret->ti_name = _name;
	}
	ret->is_struct = is_struct;
	ret->pointer_level = pointer_level;
	ret->len = len;
	ret->ref = 1;
	/*插入到hash表*/
	insert(type_hash, full_name, (void*)ret);
	return ret;
}

struct type_info* get_type(char *name)
{
	return (struct type_info*)get(type_hash, name);
}

int calculate_type_len(char *name)
{
	struct type_info* type = get_type(name);
	if(type)
	{
		return type->len;
	}
	/*需要进一步完善*/
	return sizeof(long);
}

struct type_info* create_type_info_no_len(char *name)
{
	return create_type_info(name, calculate_type_len(name));
}


int type_init()
{
	/*防止多次初始化*/
	/*没有初始化或者初始化失败可以进行初始化*/
	static int init = 0;
	if(init == 1)
		return 0;
	init = 1;
	type_hash = hash_new(20, _type_equal, _copy_type, free_type);
	
	if(!type_hash)
	{
		init = -1;
		return init;
	}
	/*初始化内置的类型*/
	create_type_info("int", sizeof(int));
	create_type_info("char", sizeof(char));
	create_type_info("short", sizeof(short));
	create_type_info("long", sizeof(long));
	create_type_info("unsigned", sizeof(unsigned));
	create_type_info("char *", sizeof(char*));
	create_type_info("void *", sizeof(void*));
	return 0;
}

/*******************函数信息部分*********************/
static int func_equal(void *k1, void *k2)
{
	return strcmp((char*)k1, (char*)k2);
}

static void* func_copy(void *src)
{
	return src;
}

static void free_func(void *value)
{
	;
}
/**
 *  函数系统初始化
 **/
int function_init()
{
	/*防止多次初始化*/
	/*没有初始化或者初始化失败可以进行初始化*/
	static int init = 0;
	if(init == 1)
		return 0;
	init = 1;
	/*创建函数信息的哈希表*/
	func_hash = hash_new(20, func_equal, func_copy, free_func);
	if(!func_hash)
	{
		init = -1;
		return init;
	}
	/*初始化类型信息系统*/
	if(type_init() < 0)
	{
		init = -1;
		return init;
	}
	return 0;
}

/*计算参数的个数*/
static int calculate_param_num(const char *param_list)
{
	int number = 0;
	int i = 0;
	if(*param_list == '\0' || strcmp(param_list, "void") == 0)
		return 0;
	for(i = 0; param_list[i]; i ++)
	{
		if(param_list[i] == ',')
			number ++;
	}
	number ++;
	return number;
}


static struct param_info* create_param_info(char *param_list)
{
	struct param_info* pi;
	struct variant_info *vi;
	int num = calculate_param_num(param_list);
	int i = 0;
	int k = 0;
	char *t, *v;
	if(num == 0)
	{
		pi = (struct param_info*)mm_malloc(sizeof(struct param_info));
		if(!pi)
			goto error1;
		pi->param_num = num;
		return pi;
	}
	/*申请内存*/
	pi = (struct param_info*)mm_malloc(sizeof(struct param_info));
	if(!pi)
		goto error1;
	vi = (struct variant_info*)mm_malloc(sizeof(struct variant_info) * num);
	if(!vi)
		goto error2;
	/*设置函数参数的具体信息*/
	for(i = 0; i < num; i ++)
	{
		/*分割出每一个参数*/
		t = strchr(param_list, ',');
		if(t)
		{
			t ++;
			*(t - 2) = '\0';
		}
		v = strrchr(param_list, ' ');
		if(v)
			*v = '\0';
		vi[i].type_info = create_type_info_no_len(param_list);
		if(!vi[i].type_info)
			goto error3;
		if(v)
		{
			v ++;
			vi[i].vi_name = (char*)mm_malloc(sizeof(char) * (strlen(v) + 1));
			if(!vi[i].vi_name)
				goto error4;
			strcpy(vi[i].vi_name, v);
		}
		if(t)
			param_list = t + 1;
	}
	pi->param_num = num;
	pi->type_info = vi;
	return pi;
error4:
	for(k = 0; k < i; k ++)
	{
		mm_free(vi[k].vi_name);
	}
error3:
	mm_free(vi);
error2:
	mm_free(pi);
error1:
	return NULL;
}

/**
 *  创建函数信息的hash表
 **/
struct HashTable* create_func_table()
{
	return hash_new(20, func_equal, func_copy, free_func);
}

/**
 *  添加函数信息到哈希表
 *  如果已经存在这样的函数，返回-1,其他错误返回-2,否则返回0
 **/
int insert_func_table(struct HashTable* func_table, struct func_info* func)
{
	struct func_info *t;
	if(!func_table || !func)
	{
		return -2;
	}
	t = get(func_table, func->fi_name);
	if(t)
		return -1;
	insert(func_table, func->fi_name, (void*)func);
	return 0;
}

/**
 *  从哈希表中获得指定@name的函数信息
 **/
struct func_info* get_func_from_table(struct HashTable *func_table, char *name)
{
	if(!func_table || !name)
		return NULL;
	return (struct func_info*)get(func_table, name);
}

/**
 * 根据函数原型名@name创建一个函数信息
 **/
struct func_info* create_func_info(char *type, char *name, char *param_list)
{	
	struct func_info *fi;
	struct type_info *ti;
	char *_name;
	char *_param_list;
	struct param_info *pi;


	/*参数检查*/
	if(!type || !name || !param_list)
		return NULL;

	/*各东东申请内存*/
	fi = (struct func_info*)mm_malloc(sizeof(struct func_info));
	if(!fi)
		goto error1;
	_name = (char*)mm_malloc(sizeof(char) * (strlen(name) + 1));
	if(!_name)
		goto error2;
	strcpy(_name, name);
	_param_list = (char*)mm_malloc(sizeof(char) * (strlen(param_list) + 1));
	if(!_param_list)
		goto error3;
	strcpy(_param_list, param_list);
	/*创建函数的返回值的类型信息*/
	ti = create_type_info_no_len(type);
	if(!ti)
		goto error4;
	/*创建函数的参数列表信息*/
	pi = create_param_info(_param_list);
	if(!pi)
		goto error4;
	/*初始化*/
	fi->ret_info = ti;
	fi->fi_name = _name;
	fi->param_info = pi;
	return fi;
error4:
	mm_free(_param_list);
error3:
	mm_free(_name);
error2:
	mm_free(fi);
error1:
	return NULL;
}

struct variant_info* create_variant_info(char *type, char *name)
{
	struct variant_info *vi;
	char *_name;
	if(!type || !name)
		return NULL;

	vi = (struct variant_info*)mm_malloc(sizeof(struct variant_info));
	if(!vi)
		goto error1;
	_name = (char*)mm_malloc(sizeof(char) * (strlen(name) + 1));
	if(!_name)
		goto error2;
	vi->type_info = create_type_info_no_len(type);
	if(!vi->type_info)
		goto error3;
	strcpy(_name, name);
	vi->vi_name = _name;
	return vi;
error3:
	mm_free(_name);
error2:
	mm_free(vi);
error1:
	return NULL;
}

void variant_set_addr(struct variant_info* vi, void *addr, int global)
{
	char *addr_p;
	if(!vi)
		return ;
	vi->global = global;
	if(global)
	{
		if(!addr)
			return ;
		addr_p = (char*)mm_malloc((strlen((char*)addr) + 1) * sizeof(char));
		strcpy(addr_p, (char*)addr);
		vi->vi_addr_p = addr_p;
	}
	else
	{
		vi->vi_addr = (int)addr;
	}
}

#ifdef FUNCTION_DEBUG

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
		printf("name:%s\n", ti->si->name);
	}
	else
		printf("name:%s\n", ti->ti_name);
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


static void print_param_info(struct param_info *info)
{
	int i = 0;
	if(!info)
	{
		printf("Param_list:<NULL>\n");
		return;
	}
	printf("----------------param_info:---------\n");
	for(i = 0; i < info->param_num; i ++)
	{
		print_variant_info(info->type_info + i);
	}
	printf("------------------------------------\n");
}

int main(int argc, char **argv)
{
	struct type_info *type;
	char *bi[] = {"int", "short", "char", "void *"};
	char *bi2[] = {"struct hello", "struct ok", "struct hello", "struct hello *", "struct you", "struct fuck",
		"struct muni", "struct fuck_you_foreya"};
	int i = 0;
	struct func_info *fi;
	struct variant_info *vi;
	char *types[] = {"int", "struct hello", "struct pointrt", "struct he", "int * *"};
	char  *names[] = {"k", "j", "fuck", "you", "doc"};
	char *param_list[] = {"char * hua , int hello", "void", "", "void * hello", "void * type , struct hello * * fuck , int k"};
	char *name;
	struct HashTable *func_table;

	type_init();

	for(i = 0; i < sizeof(bi) / sizeof(char*); i ++)
	{
		type = get_type(bi[i]);
		printf("full_name:%s, name:%s, level:%d, len:%d, is_struct:%d\n", 
			bi[i], type->ti_name, type->pointer_level, type->len, type->is_struct);
	}
	for(i = 0; i < sizeof(bi2)/ sizeof(char*); i ++)
	{
		type = create_type_info(bi2[i], i + 1);
	}
	for(i = 0; i < sizeof(bi2) / sizeof(char*); i ++)
	{
		type = get_type(bi2[i]);
		printf("Full name:%s, name %s, level %d, len %d, is_struct %d, ref %d\n", 
			bi2[i], type->si->name, type->pointer_level, type->len, type->is_struct, type->ref);
	}
	/*测试函数信息*/
	function_init();
	func_table = create_func_table();
	printf("--------------function------------------------\n");
	for(i = 0; i < sizeof(types) / sizeof(char*); i ++)
	{
		fi = create_func_info(types[i], names[i], param_list[i]);
		printf("%d\n", insert_func_table(func_table, fi));
	}
	for(i = 0; i < sizeof(types) / sizeof(char*); i ++)
	{
		fi = get_func_from_table(func_table, names[i]);
		printf("Full-name:%s, param_num:%d, name:%s\n", names[i], fi->param_info->param_num, fi->fi_name);
		print_type_info(fi->ret_info);
		print_param_info(fi->param_info);
	}
	printf("---------------------------------------------\n");
	for(i = 0; i < sizeof(types) / sizeof(char*); i ++)
	{
		vi = create_variant_info(types[i], names[i]);
		if(vi->type_info->is_struct)
			name = vi->type_info->si->name;
		else
			name = vi->type_info->ti_name;
		printf("full-name:%s, type_name:%s, real_name:%s, ref:%d\n", names[i], name, vi->vi_name, vi->type_info->ref);
	}

	return 0;
}
#endif