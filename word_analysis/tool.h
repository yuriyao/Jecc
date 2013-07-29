/**
 *  工具
 **/
#ifndef TOOL_H
#define TOOL_H
#include <stdio.h>
#include <stdlib.h>

/*打印信息并且退出*/
#define exit_with_info(info)\
do{\
    printf("%s\n", info);\
    exit(-1);\
}while(0)

/*申请内存失败*/
#define exit_for_nomem() exit_with_info("申请内存失败")

//条件成立就退出，并打印调试信息
#define debug_on(condition)\
do{\
	if(condition)\
	{\
		printf("DEBUG ERROR line %d, file %s\n", __LINE__, __FILE__);\
		exit(-1);\
	}\
}while(0)


#endif