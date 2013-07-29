/**
 *  词法分析器
 */
#include <stdio.h>
#include "word_analysis.h"
#include "token.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "hash.h"
#include "tool.h"
 #include <assert.h>

/*关键字表*/
char *kw_table[] =
{
    (char*)"auto", (char*)"break", (char*)"case", (char*)"char",
    (char*)"const", (char*)"continue", (char*)"default", (char*)"do",
    (char*)"double", (char*)"else", (char*)"enum", (char*)"extern",
    (char*)"float", (char*)"for", (char*)"goto", (char*)"if",
    (char*)"int", (char*)"long", (char*)"register", (char*)"return",
    (char*)"short", (char*)"signed", (char*)"sizeof", (char*)"static",
    (char*)"struct", (char*)"switch", (char*)"typedef", (char*)"union",
    (char*)"unsigned", (char*)"void", (char*)"volatile", (char*)"while",
};

/*存储当前状态*/
static int state = S_RE;
/*文件指针*/
static FILE *fp = NULL;
/*缓存的字符*/
static int buffer_c = -1;

/*缓冲区大小*/
#define BUFFER_SIZE 1024
/*缓冲区*/
static char buffer[BUFFER_SIZE];
/*缓冲区指针*/
static int buffer_pointer = 0;
/*行号*/
static int line_no = 1;

static struct HashTable *kw_hash_table;

static void init_kw_hash_table()
{
    int i;
    kw_hash_table = hash_new_str(50);
    for(i = 0; i < sizeof(kw_table) / sizeof(char*); i ++)
        insert_str(kw_hash_table, kw_table[i], kw_table[i]);
}

/*查看是否为关键字*/
static int is_kw(char *kw)
{
    return get_str(kw_hash_table, kw) ? 1 : 0;
}

static int _to_hex(char *str);
static int _to_oct(char *str);

static int _to_char(char *ch)
{
    if(strlen(ch) == 0)
        return 0;
    if(strlen(ch) == 1)
        return ch[0];
    if(ch[0] != '\\' || strlen(ch) > 4)
    {
        printf("非法字符，只取第一个字符, Line %d\n", line_no);
        return ch[0];
    }
    if(strlen(ch) == 2)
    {
        switch(ch[1])
        {
        case 'n':
            return '\n';
        case 'r':
            return '\r';
        case '0':
            return '\0';
        case 't':
            return '\t';
        case 'v':
            return '\v';
        case 'b':
            return '\b';
        case 'f':
            return '\f';
        case 'a':
            return '\a';
        case '\"':
            return '\"';
        case '\'':
            return '\'';
        case '\\':
            return '\\';
        case '\?':
            return '\?';
        default:
            break; 
        }
    }
    if(ch[1] == 'x' || ch[1] == 'X')
        return _to_hex(ch + 2);
    else if(isdigit(ch[1]))
        return _to_oct(ch + 1);
}



/*读取一个字符*/
int read_char()
{
    int val = buffer_c;
    /*缓冲字符有效*/
    if(buffer_c != -1)
    {
        buffer_c = -1;
        return val;
    }
    /*没有缓冲字符,读取文件*/
    val = getc(fp);
    if(val == '\n')
        line_no ++;
    return (val == EOF) ? -1 : val;
}

/*存储一个字符*/
#define store_char(ch) (buffer_c = ch)

static void process_re_space(char ch)
{
    buffer_pointer = 0;
}

/*处理状态的回调函数*/
static void preocess_re_non(char ch)
{
    //exit_with_info("Read with irlegal NonAcsii token, in  ")
    printf("Read with irlegal NonAcsii token, in %d\n", line_no);
    exit(-1);
}

static void process_re_no(char ch)
{
    int type = 0;
    switch(ch)
    {
    case '(':
        type = L_PARENT;
        break;
    case ')':
        type = R_PARENT;
        break;
    case '[':
        type = R_BRACKET;
        break;
    case ']':
        type = L_BRACKET;
        break;
    case '{':
        type = L_BPARENT;
        break;
    case '}':
        type = R_BPARENT;
        break;
    case ';':
        type = SEMICOLON;
        break;
    case '?':
        type = QUESTION;
        break;
    case ':':
        type = COLON;
        break;
    case '*':
        type = STAR;
        break;
    case '/':
        type = DIVIDE;
        break;
    case '%':
        type = MOD;
        break;
    case '^':
        type = XOR;
        break;
    case '~':
        type = NOT;
        break;
    case ',':
        type = COMMA;
        break;
    default:
        return;
    }
    table_add_char(ch, type, line_no);
}

void process_token_all(char ch)
{
    int type = TOKEN;
    store_char(ch);
    buffer[buffer_pointer] = '\0';
    buffer_pointer = 0;
    if(is_kw(buffer))
        type = KEYWORD;
    table_add_string(buffer, type, line_no);

}

void process_token_non(char ch)
{
    preocess_re_non(ch);
}

void _process_string(char *des, char *src)
{
    strcpy(des, src);
}

void process_string_quota(char ch)
{
    char des[1024];
    assert(ch == '\"');
    table_add_char('\"', L_QUOTA, line_no);
    buffer[buffer_pointer] = 0;
    _process_string(des, &buffer[1]);
    table_add_string(des, STRING, line_no);
    table_add_char('\"', R_QUOTA, line_no);
    buffer_pointer = 0;
}

static int _to_hex(char *str)
{
    int i, ret = 0;
    int t;
    for(i = 0; i < strlen(str); i ++)
    {
        t = str[i];
        if(t >= '0' && t <= '9')
            t -= '0';
        else if(t >= 'A' && t <= 'F')
            t -= 'A' - 10;
        else
            t -= 'a' - 10;
        ret = ret * 16 + t;
    }
    return ret;
}

static int _to_oct(char *str)
{
    int mod_oct = 1;
    int i = 0;
    int ret = 0;
    for(; i < strlen(str); i ++)
        if(str[i] > '7')
            mod_oct = 0;
    if(!mod_oct)
        printf("Waring Oct was transfered to Dec in line %d\n", line_no);
    if(mod_oct)
    {
        for(i = 0; i < strlen(str); i ++)
            ret = ret * 8 + str[i] - '0';
        return ret;
    }
    return atoi(str);
}

static int _str_to_int(char *str)
{
    int len, ret;
    if(!str || strlen(str) == 0)
        return 0;
    len = strlen(str);
    if(len == 1 || str[0] != '0')
        return atoi(str);
    if(str[1] != 'x' && str[1] != 'X')
        return _to_oct(str + 1);
    else
        return _to_hex(str + 2);
}

void process_num_all(char ch)
{
    int num;
    int i;
    buffer[buffer_pointer] = '\0';
    buffer_pointer = 0;
    num = _str_to_int(buffer);
    table_add_int(num, line_no);
    store_char(ch);
}

void process_lsquota_all(char ch)
{
    int r;
    table_add_char('\'', L_SQUOTA, line_no);
    buffer[buffer_pointer] = '\0';
    r = _to_char(&buffer[1]);
    if(r == -1)
        exit_with_info("非法字符");
    table_add_char((char)r, CHAR, line_no);
    table_add_char('\'', R_SQUOTA, line_no);
    buffer_pointer = 0;
}

void process_lquota_all(char ch)
{
    table_add_char('\"', L_QUOTA, line_no);
    buffer[buffer_pointer] = '\0';
    table_add_string(&buffer[1], STRING, line_no);
    buffer_pointer = 0;
    table_add_char('\"', R_QUOTA, line_no);
}

void process_plus_all(char ch)
{
    store_char(ch);
    table_add_char('+', PLUS, line_no);
    buffer_pointer = 0;
}

void process_plus_plus(char ch)
{
    table_add_chs((char*)"++", PLUSPLUS, line_no);
    buffer_pointer = 0;
}

/*用来支持+=*/
void process_plus_equal(char ch)
{
    process_plus_all(ch);
}

void process_minus_all(char ch)
{
    store_char(ch);
    table_add_char('-', MINUS, line_no);
    buffer_pointer = 0;
}

void process_minus_minus(char ch)
{
    table_add_chs((char*)"--", MINUSMINUS, line_no);
    buffer_pointer = 0;
}

/*用来支持-=*/
void process_minus_equal(char ch)
{
    process_minus_all(ch);
}

void process_minus_gt(char ch)
{
    assert(ch == '>');
    table_add_chs((char*)"->", POINTER, line_no);
    buffer_pointer = 0;
}

void process_equal_all(char ch)
{
    store_char(ch);
    table_add_char('=', EQUAL, line_no);
    buffer_pointer = 0;
}

void process_equal_equal(char ch)
{
    table_add_chs((char*)"==", EE, line_no);
    buffer_pointer = 0;
}

void process_lg_all(char ch)
{
    store_char(ch);
    table_add_char('<', LG, line_no);
    buffer_pointer = 0;
}

void process_lg_equal(char ch)
{
    assert(ch == '=');
    table_add_chs((char*)"<=", LE, line_no);
    buffer_pointer = 0;
}

void process_lg_lg(char ch)
{
    assert(ch == '<');
    table_add_chs((char*)"<<", L_MOVE, line_no);
    buffer_pointer = 0;
}

/*void process_gt_all(char ch)
{
    store_char(ch);
    table_add_char('>', GT, line_no);
    buffer_pointer = 0;
}

void process_gt_equal(char ch)
{
    assert(ch == '=');
    table_add_chs(">=", GE, line_no);
    buffer_pointer = 0;
}

void process_gt_gt(char ch)
{
    assert(ch == '>');
    table_add_chs(">>", R_MOVE, line_no);
    buffer_pointer = 0;
}*/

static int _get_xx_type(char ch)
{
    int type;
    switch(buffer[0])
    {
    case '<':
        type = LG;
        break;
    case '>':
        type = GT;
        break;
    case '&':
        type = AND;
        break;
    case '|':
        type = OR;
    case '-':
        type = MINUS;
        break;
    case '+':
        type = PLUS;
        break;
    case '=':
        type = EQUAL;
        break;
    case '.':
        type = POINT;
        break;
    default:
        type = -1;
        break;
    }
    return type;
}

static int _get_xx_xx_type(char ch)
{
    int type;
    switch(buffer[0])
    {
    case '<':
        type = L_MOVE;
        break;
    case '>':
        type = R_MOVE;
        break;
    case '&':
        type = ANDAND;
        break;
    case '|':
        type = OROR;
    case '-':
        type = MINUSMINUS;
        break;
    case '+':
        type = PLUSPLUS;
        break;
    case '=':
        type = EE;
        break;
    default:
        type = -1;
        break;
    }
    return type;
}

static int _get_xx_equal_type(char ch)
{
    int type;
    switch(buffer[0])
    {
    case '<':
        type = LE;
        break;
    case '>':
        type = GE;
        break;
    case '&':
        type = ANDEQUAL;
        break;
    case '|':
        type = OREQUAL;
    case '-':
        type = MINUSEQUAL;
        break;
    case '+':
        type = PLUSEQUAL;
        break;
    case '=':
        type = EE;
        break;
    default:
        type = -1;
        break;
    }
    return type;
}

void process_xx_all(char ch)
{
    int type = _get_xx_type(ch);
    store_char(ch);
    if(type == -1)
    {
        buffer_pointer = 0;
        return;
    }
    buffer_pointer = 0;
    table_add_char(buffer[0], type, line_no);
}

void process_xx_xx(char ch)
{
    assert(ch == buffer[0]);
    int type = _get_xx_xx_type(ch);
    char cs[3] = {0};
    if(type == -1)
    {
        buffer_pointer = 0;
        return;
    }
    cs[0] = cs[1] = ch;
    table_add_chs(cs, type, line_no);
}

void process_xx_equal(char ch)
{
    assert(ch == '=');
    int type = _get_xx_equal_type(ch);
    char cs[3] = {0};
    if(type == -1)
    {
        buffer_pointer = 0;
        return;
    }
    cs[0] = buffer[0];
    cs[1] = ch;
    table_add_chs(cs, type, line_no);
}

void process_float_all(char ch)
{
    float f;
    store_char(ch);
    buffer[buffer_pointer] = '\0';
    f = atof(buffer);
    table_add_float(f, line_no);
    buffer_pointer = 0;
}

void process_zero_all(char ch)
{
    store_char(ch);
    table_add_int(0, line_no);
    buffer_pointer = 0;
}

/**
 * 状态控制器
 **/
 //每一个状态
 struct StateNode
 {
    //当前状态
    enum STATE state;
    //当状态转变为RE时调用的处理函数
    void (*process)(char ch);
 };

const struct StateNode state_nodes[S_END] = 
 {
    {S_RE, NULL},
    {S_TOKEN, NULL},
    {S_NUM, NULL},
    {S_STRING, NULL},
    {S_LSQUOTA, NULL},
    {S_LSB, NULL},
    {S_LSW, NULL}, 
    {S_LQUOTA, NULL},
    {S_BACKSLASH, NULL},
    {S_PLUS, NULL},
    {S_MINUS, NULL},
    {S_EQUAL, NULL},
    {S_LG, NULL},
    {S_GT, NULL},
    {S_AND, NULL},
    {S_OR, NULL},
    {S_NUMPOINT, NULL},
    {S_ZERO, NULL},
    {S_SINGALPOINT, NULL},
 };
const struct StateNode state_re_space = {S_RE, process_re_space};
/*正常状态读入一个没有后续影响的字符*/
const struct StateNode state_re_no = {S_RE, process_re_no};
/*正常状态读入一个非ascii字符*/
const struct StateNode state_re_non = {S_RE, preocess_re_non};
/*string to quota*/
const struct StateNode state_string_quota = {S_RE, process_string_quota};
/**/
const struct StateNode state_token_all = {S_RE, process_token_all};
/**/
const struct StateNode state_token_non = {S_RE, process_token_non};
/**/
const struct StateNode state_num_all = {S_RE, process_num_all};
/*不可能发生的状态转移*/
const struct StateNode state_impossible = {S_RE, NULL};
/**/
const struct StateNode state_lsquota_all = {S_RE, process_lsquota_all};
/**/
const struct StateNode state_lquota_all = {S_RE, process_lquota_all};
/*+*/
const struct StateNode state_plus_all = {S_RE, process_plus_all};
/*++*/
struct StateNode state_plus_plus = {S_RE, process_plus_plus};
/*+=*/
struct StateNode state_plus_equal = {S_RE, process_plus_equal};
/*--*/
struct StateNode state_minus_all = {S_RE, process_minus_all};
/*--*/
struct StateNode state_minus_minus = {S_RE, process_minus_minus};
/*-=*/
struct StateNode state_minus_equal = {S_RE, process_minus_equal};
/*->*/
struct StateNode state_minus_gt = {S_RE, process_minus_gt};
/*=*/
struct StateNode state_equal_all = {S_RE, process_equal_all};
/*==*/
struct StateNode state_equal_equal = {S_RE, process_equal_equal};
/*<*/
struct StateNode state_lg_all = {S_RE, process_lg_all};
/*<<*/
struct StateNode state_lg_lg = {S_RE, process_lg_lg};
/*<=*/
struct StateNode state_lg_equal = {S_RE, process_lg_equal};
/**/
const struct StateNode state_xx_all = {S_RE, process_xx_all};
/**/
struct StateNode state_xx_xx = {S_RE, process_xx_xx};
/**/
struct StateNode state_xx_equal = {S_RE, process_xx_equal};
/*float*/
struct StateNode state_float_all = {S_RE, process_float_all};
/*zero*/
struct StateNode state_zero_all = {S_RE, process_zero_all};





static enum TYPE _get_type(char ch)
{
    /**/
    switch(ch)
    {
    case '.':
        return T_POINT;
    case '+':
        return T_PLUS;
    case '-':
        return T_MINUS;
    case '&':
        return T_AND;
    case '|':
        return T_OR;
    case '<':
        return T_LG;
    case '>':
        return T_GT;
    case '=':
        return T_EQUAL;
    case '\"':
        return T_QUOTA;
    case '\'':
        return T_SQUOTA;
    case 'X':
    case 'x':
        return T_X;
    case '0':
        return T_ZERO;
    case '\\':
        return T_BACKSLASH;
    default:
        break;
    }
    if(ch >= '0' && ch <= '9')
        return T_NUM;
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_')
        return T_CHAR;
    if(ch == '\r' || ch == ' ' || ch == '\n' || ch == '\t')
        return T_SPACE;
    if(ch & 0x80)
        return T_NONASCII;
    return T_NOEFFECT;
}

#define _PROCESS()\
do{\
    type = _get_type(ch);\
    node = &(stateTable[state][type]);\
    if(node->state == S_RE && node->process)\
    {\
        node->process(ch);\
    }\
    else\
    {\
        buffer[buffer_pointer ++] = ch;\
    }\
}while(0)

void process(struct StateNode stateTable[S_END][T_END])
{
    int ch;
    enum TYPE type;
    struct StateNode* node;
    while((ch = read_char()) != -1)
    {
        type = _get_type(ch);
        node = &(stateTable[state][type]);
        if(node->state == S_RE && node->process)
        {
            node->process(ch);
        }
        else
        {
            buffer[buffer_pointer ++] = ch; 
        }
        state = node->state;
    }
    /*向状态机发送空格，迫使其处理缓冲区*/
    ch = ' ';
    _PROCESS();
}
  
//#ifndef WORD_ANALYSIS_ONLY
/*从@src中读取源文件，并把词法分析结果写入结果@des*/
void word_analysis(char *src, char *des)
{
    struct StateNode stateTable[S_END][T_END] = {
    {state_nodes[S_TOKEN],          state_nodes[S_NUM], 
     state_nodes[S_SINGALPOINT],    state_nodes[S_PLUS],
     state_nodes[S_MINUS],          state_nodes[S_AND],
     state_nodes[S_OR],             state_nodes[S_LG],
     state_nodes[S_GT],             state_nodes[S_EQUAL],
     state_nodes[S_LQUOTA],         state_nodes[S_LSQUOTA],
     state_re_non,                  state_re_no,
     state_nodes[S_TOKEN],          state_re_space,
     state_nodes[S_ZERO],           state_impossible,
    }/*S_RE*/,

    {state_nodes[S_TOKEN],          state_nodes[S_TOKEN],
     state_token_all,               state_token_all,
     state_token_all,               state_token_all,
     state_token_all,               state_token_all,
     state_token_all,               state_token_all,
     state_token_all,               state_token_all,
     state_token_non,               state_token_all,
     state_nodes[S_TOKEN],          state_token_all,
     state_nodes[S_TOKEN],          state_impossible,
     }/*S_TOKEN*/,

    {state_num_all,                 state_nodes[S_NUM],
     state_nodes[S_NUMPOINT],       state_num_all,
     state_num_all,                 state_num_all,
     state_num_all,                 state_num_all,
     state_num_all,                 state_num_all,
     state_num_all,                 state_num_all,
     state_token_non,               state_num_all,
     state_num_all,                 state_num_all,
     state_nodes[S_NUM],            state_impossible,
    }/*S_NUM*/,

    {state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_string_quota,            state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_BACKSLASH],
    }/*S_STRING*/,

    {state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_lsquota_all,
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSB],
    }/*S_LSQUOTA*/,

    {state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
    }/*S_LSB*/,

    {state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_lsquota_all,
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
     state_nodes[S_LSW],            state_nodes[S_LSW],
    }/*S_LSW*/,

    {state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_lquota_all,              state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_BACKSLASH],         
    }/*S_LQUOTA*/,

    {state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],
     state_nodes[S_STRING],         state_nodes[S_STRING],         
    }/*S_BACKSLASH*/,

    {state_plus_all,                state_plus_all,
     state_plus_all,                state_xx_xx,
     state_plus_all,                state_plus_all,
     state_plus_all,                state_plus_all,
     state_plus_all,                state_xx_equal,
     state_plus_all,                state_plus_all,
     state_plus_all,                state_plus_all,
     state_plus_all,                state_plus_all,
     state_plus_all,                state_impossible,
    }/*S_PLUS*/,

    {state_minus_all,               state_minus_all,
     state_minus_all,               state_minus_all,
     state_xx_xx,                   state_minus_all,
     state_minus_all,               state_minus_all,
     state_minus_gt,                state_xx_equal,
     state_minus_all,               state_minus_all,
     state_minus_all,               state_minus_all,
     state_minus_all,               state_minus_all,
     state_minus_all,               state_minus_all,
    }/*S_MINUS*/,

    {state_equal_all,               state_equal_all,
     state_equal_all,               state_equal_all,
     state_equal_all,               state_equal_all,
     state_equal_all,               state_equal_all,
     state_equal_all,               state_equal_equal,
     state_equal_all,               state_equal_all,
     state_equal_all,               state_equal_all,
     state_equal_all,               state_equal_all,
     state_equal_all,               state_equal_all,
    }/*S_EQUAL*/,

    {state_lg_all,                  state_lg_all,
     state_lg_all,                  state_lg_all,
     state_lg_all,                  state_lg_all,
     state_lg_all,                  state_lg_lg,
     state_lg_all,                  state_lg_equal,
     state_lg_all,                  state_lg_all,
     state_lg_all,                  state_lg_all,
     state_lg_all,                  state_lg_all,
     state_lg_all,                  state_lg_all,
    }/*S_LG*/,

    {state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_xx,                   state_xx_equal,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
    }/*S_GT*/,

    {state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_xx,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_equal,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
    }/*S_AND*/,

    {state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_xx,                   state_xx_all,
     state_xx_all,                  state_xx_equal,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
    }/*S_OR*/,

    {state_float_all,               state_nodes[S_NUMPOINT],
     state_float_all,               state_float_all,
     state_float_all,               state_float_all,
     state_float_all,               state_float_all,
     state_float_all,               state_float_all,
     state_float_all,               state_float_all,
     state_float_all,               state_float_all,
     state_float_all,               state_float_all,
     state_nodes[S_NUMPOINT],       state_float_all,
    }/*S_NUMPOINT*/,

    {state_zero_all,                state_nodes[S_NUM],
     state_nodes[S_NUMPOINT],       state_zero_all,
     state_zero_all,                state_zero_all,
     state_zero_all,                state_zero_all,
     state_zero_all,                state_zero_all,
     state_zero_all,                state_zero_all,
     state_zero_all,                state_zero_all,
     state_nodes[S_NUM],            state_zero_all,
     state_nodes[S_NUM],            state_zero_all,
    }/*S_ZERO*/,

    {state_xx_all,                  state_nodes[S_NUMPOINT],       
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
     state_xx_all,                  state_xx_all,
    }/*S_SINGALPOINT*/,
 };
    FILE *w;
    fp = fopen(src, "r");
    if(!fp)
    {
        printf("Open file %s failed\n", src);
        exit(1);
    }
    w = fopen(des, "w");
    if(!w)
    {
        printf("Open file %s failed\n", des);
        exit(1);
    }
    init_kw_hash_table();
    /*初始化符号表*/
    table_init();
    process(stateTable);
    table_serial(w);
}
//#endif

/*只进行词法分析*/
#ifdef WORD_ANALYSIS_ONLY

int main(int argc, char **argv)
{
    FILE *w;
    if(argc < 3)
    {
        printf("Usage: %s src_file_name des_file_name", argv[0]);
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if(!fp)
    {
        printf("Open file %s failed\n", argv[1]);
        exit(1);
    }
    w = fopen(argv[2], "w");
    if(!w)
    {
        printf("Open file %s failed\n", argv[2]);
        exit(1);
    }
    init_kw_hash_table();
    /*初始化符号表*/
    table_init();
    process();
    table_serial(w);
    return 0;
}
#endif


