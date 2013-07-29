/**
 *  函数信息
 **/

struct struct_info
{
	char *name;
};

/*类型*/
struct type_info
{
	/*是否是结构体*/
	int is_struct;
	union
	{
		//is_struct为1时，指向结构体的信息
		struct struct_info *_si;
		//不是结构体时，指向类型名
		char *_ti_name;
	}value;
#define si value._si
#define ti_name value._ti_name
	/*多少元指针*/
	int pointer_level;
	/*引用计数*/
	int ref;
	/*类型的长度*/
	int len;
};

/*变量信息*/
struct variant_info
{
	struct type_info *type_info;
	char *vi_name;
	/*是否是全局变量*/
	int global;
	/*变量的地址*/ 
	union
	{
		/*如果是局部变量，是相对于ebp的偏移*/
		int _addr;
		/*如果是全局变量，则是其标记符*/
		char *_addr_p;
	}value;
#define vi_addr value._addr
#define vi_addr_p value._addr_p

};

/*参数信息*/
struct param_info
{
	/*参数个数*/
	int param_num;
	/*函数参数类型信息列表*/
	struct variant_info *type_info;
};

/*函数信息*/
struct func_info
{
	/*返回值信息*/
	struct type_info *ret_info;
	/*函数名*/
	char *fi_name;
	/*参数信息*/
	struct param_info *param_info;
};

#define LONG_LEN (sizeof(unsigned long))
/*和整型对齐*/
#define ALIGN_LONG(len) (((len) + LONG_LEN - 1) & (~(LONG_LEN - 1)))
/*类型的长度*/
#define TYPE_LEN(type) (type->len)
/*类型指针的元数*/
#define POINTER_LEVEL(type) (type->level)
/*是否是指针*/
#define IS_POINTER(type) (type->pointer_level >= 1)

/*类型操作的函数*/
/**
 *  初始化类型系统
 *  必须在调用下面的函数之前调用它，进行初始化
 *  返回0表示初始化成功
 **/
int type_init();

/**
 * 创建一个@_name的类型信息
 * _name,为类型的名字,比如"struct hello***", "int*", "int"(注意空格)
 * len是该类型的长度
 **/
struct type_info* create_type_info(char *_name, int len);

/**
 *  创建一个@name的类型信息
 *  类型的长度由计算获得
 **/
struct type_info* create_type_info_no_len(char *name);

/**
 *  比较@t1和@t2是否是相同的类型
 *  如果两种类型相同返回0
 **/
int type_equal(struct type_info *t1, struct type_info *t2);

/**
 *  由类型名@name获得该类型信息
 *  如果已经创建过，则返回相应的类型
 *	否则返回NULL
 **/
struct type_info* get_type(char *name);

/**
 *  计算类型名@name的长度
 **/
int calculate_type_len(char *name);

/*函数操作的函数*/
/**
 *  函数系统初始化
 **/
int function_init();
/**
 * 根据函数原型名@name,返回类型@type和参数列表@param_list创建一个函数信息
 **/
struct func_info* create_func_info(char *type, char *name, char *param_list);

/**
 *  创建函数信息的hash表
 **/
struct HashTable* create_func_table();

/**
 *  添加函数信息到哈希表
 *  如果已经存在这样的函数，返回-1,其他错误返回-2,否则返回0
 **/
int insert_func_table(struct HashTable* func_table, struct func_info* func);

/**
 *  从哈希表中获得指定@name的函数信息
 **/
struct func_info* get_func_from_table(struct HashTable *func_table, char *name);

/**
 *  创建变量信息
 *  type  变量类型
 *  name  变量名
 **/
struct variant_info* create_variant_info(char *type, char *name);

/**
 *  设置变量@vi的地址
 *  vi  变量信息
 *  addr 地址，如果是局部变量(global == 0),那么就是addr就是相对于ebp的偏移;否则addr指向一个字符串，比如".LCD0"
 *  global  是否是全局变量
 **/
void variant_set_addr(struct variant_info* vi, void *addr, int global);

//#define FUNCTION_DEBUG