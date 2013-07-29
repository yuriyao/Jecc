/**
 * 词法分析器
 **/
#ifndef WORD_ANALYSIS_H
#define WORD_ANALYSIS_H

/*定义各种词法的宏*/
/*符号*/
#define KEYWORD 1 //关键词
#define TOKEN 2    //符号

/*操作符*/
#define PLUS 3     //加
#define MINUS 4    //减
#define MULTI 5    //乘
#define DIVIDE 6   //除
#define PLUSPLUS 7 //加加
#define MINUSMINUS 8//减减
#define MOD 9       //模
#define EQUAL 10    //等号
#define AND 11      //&
#define OR 12       //|
#define XOR 13      //^
#define NOT 14      //~
#define L_MOVE  15  //<<
#define R_MOVE  16  //>>
#define ANDEQUAL 17
#define OREQUAL 18
#define XOREQUAL 19
#define MODEQUAL 20
#define MINUSEQUAL 21
#define PLUSEQUAL 22



/*逻辑符号*/
#define EE 30         //==
#define LG 31         //<
#define GT 32         //>
#define LE 33         //<=
#define GE 34         //>=
#define ANDAND 35     //&&
#define OROR  36      //||

/*结构的符号*/
#define L_PARENT 40     //(
#define R_PARENT 41     //)
#define L_BRACKET 42    //[
#define R_BRACKET 43    //]
#define L_BPARENT 44    //{
#define R_BPARENT 45    //}
#define L_QUOTA 46      //"
#define R_QUOTA 47      //"
#define L_SQUOTA 48     //'
#define R_SQUOTA 49     //'
#define STAR 50         //*
#define SEMICOLON 51    //;
#define QUESTION  52    //?
#define COLON 53        //:
#define POINT 54		//.
#define COMMA 55 		//,
#define POINTER 56		//->

/*常量*/
#define STRING 60       //字符串
#define FLOAT 61        //浮点数
#define INT 62          //整数
#define LONG 63         //长整数
#define CHAR 65         //字符
#define DOUBLE 66		//双精度浮点数

/*定义状态*/
enum STATE{
    S_RE,       //重新开始状态
    S_TOKEN,    //
    S_NUM,      //数字
    S_STRING,   //字符串
    S_LSQUOTA,  //左单引号
    S_LSB,      //左单引号和反斜杠
    S_LSW,      //左单引号和字符
    S_LQUOTA,   //左引号
    S_BACKSLASH,//字符串中出现的反斜杠
    S_PLUS,     //读到一个加
    S_MINUS,    //读到一个减
    S_EQUAL,    //读到一个等号
    S_LG,       //读到一个小于号
    S_GT,       //读到一个大于号
    S_AND,      //读到一个与号
    S_OR,       //读到一个或号
    S_NUMPOINT, //读到一个浮点数的小数点
    S_ZERO,     //读到第一个0
    S_SINGALPOINT,//只读到一个小数点
    S_END,
};

/*定义字符类别*/
enum TYPE
{
    T_CHAR,     //字符
    T_NUM,      //数字
    T_POINT,    //小数点
    T_PLUS,     //加号
    T_MINUS,    //减号
    T_AND,      //与号
    T_OR,       //或号
    T_LG,       //小于号
    T_GT,       //大于号
    T_EQUAL,    //等号
    T_QUOTA,    //引号
    T_SQUOTA,   //单引号
    T_NONASCII, //非ASCII字符
    T_NOEFFECT, //对后续状态没有影响的符号 
    T_X,
    T_SPACE,
    T_ZERO,
    T_BACKSLASH,
    T_END,
};

#ifndef WORD_ANALYSIS_ONLY
void word_analysis(char *src, char *des);
#endif

#endif 