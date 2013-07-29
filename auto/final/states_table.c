/**
*  本代码由自动生成工具生成
*  作者:姚逢靖
*  版权所有,免费使用,但是，使用前
*  如果是男生,请默念，我愿意包养靖哥哥一天
*  如果是女生，请默念，“亲爱的靖哥哥”
**/

#include "states_table.h"
#include <stdio.h>
/************所有的产生式*************/
const struct CFG cfg0 =
{
	.name = "Funcstate->extern Type token ( Paramlist ) seperate",
	.process = NULL,
	.parent = NULL,
	.items = 7,
	.row = 31
};
const struct CFG cfg1 =
{
	.name = "Typedef-> Type token seperate | Type token = token seperate | Type token = number seperate | Type token = Funccall seperate ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 34
};
const struct CFG cfg2 =
{
	.name = "Typedef->Type token seperate",
	.process = NULL,
	.parent = &cfg1,
	.items = 3,
	.row = 34
};
const struct CFG cfg3 =
{
	.name = "Typedef->Type token = token seperate",
	.process = NULL,
	.parent = &cfg1,
	.items = 5,
	.row = 34
};
const struct CFG cfg4 =
{
	.name = "Typedef->Type token = number seperate",
	.process = NULL,
	.parent = &cfg1,
	.items = 5,
	.row = 34
};
const struct CFG cfg5 =
{
	.name = "Typedef->Type token = Funccall seperate",
	.process = NULL,
	.parent = &cfg1,
	.items = 5,
	.row = 34
};
const struct CFG cfg6 =
{
	.name = "Struct->struct token { Typedefs } seperate",
	.process = NULL,
	.parent = NULL,
	.items = 6,
	.row = 49
};
const struct CFG cfg7 =
{
	.name = "For->for ( Statement Statement Statement ) Block",
	.process = NULL,
	.parent = NULL,
	.items = 7,
	.row = 43
};
const struct CFG cfg8 =
{
	.name = "Program-> int main ( ) Block | Funcdef Program | Funcstate Program | Struct Program",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 28
};
const struct CFG cfg9 =
{
	.name = "Program->int main ( ) Block",
	.process = NULL,
	.parent = &cfg8,
	.items = 5,
	.row = 28
};
const struct CFG cfg10 =
{
	.name = "Program->Funcdef Program",
	.process = NULL,
	.parent = &cfg8,
	.items = 2,
	.row = 28
};
const struct CFG cfg11 =
{
	.name = "Program->Funcstate Program",
	.process = NULL,
	.parent = &cfg8,
	.items = 2,
	.row = 28
};
const struct CFG cfg12 =
{
	.name = "Program->Struct Program",
	.process = NULL,
	.parent = &cfg8,
	.items = 2,
	.row = 28
};
const struct CFG cfg13 =
{
	.name = "Ifelse->If else Block",
	.process = NULL,
	.parent = NULL,
	.items = 3,
	.row = 42
};
const struct CFG cfg14 =
{
	.name = "Realparam-> void | Realparam' ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 35
};
const struct CFG cfg15 =
{
	.name = "Realparam->void",
	.process = NULL,
	.parent = &cfg14,
	.items = 1,
	.row = 35
};
const struct CFG cfg16 =
{
	.name = "Realparam->Realparam'",
	.process = NULL,
	.parent = &cfg14,
	.items = 1,
	.row = 35
};
const struct CFG cfg17 =
{
	.name = "S'->Program",
	.process = NULL,
	.parent = NULL,
	.items = 1,
	.row = -1
};
const struct CFG cfg18 =
{
	.name = "Return-> return | return Expr ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 51
};
const struct CFG cfg19 =
{
	.name = "Return->return",
	.process = NULL,
	.parent = &cfg18,
	.items = 1,
	.row = 51
};
const struct CFG cfg20 =
{
	.name = "Return->return Expr",
	.process = NULL,
	.parent = &cfg18,
	.items = 2,
	.row = 51
};
const struct CFG cfg21 =
{
	.name = "Funccall->token ( Realparam )",
	.process = NULL,
	.parent = NULL,
	.items = 4,
	.row = 37
};
const struct CFG cfg22 =
{
	.name = "Type-> simple_type | int | Type * | void | struct token ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 32
};
const struct CFG cfg23 =
{
	.name = "Type->simple_type",
	.process = NULL,
	.parent = &cfg22,
	.items = 1,
	.row = 32
};
const struct CFG cfg24 =
{
	.name = "Type->int",
	.process = NULL,
	.parent = &cfg22,
	.items = 1,
	.row = 32
};
const struct CFG cfg25 =
{
	.name = "Type->Type *",
	.process = NULL,
	.parent = &cfg22,
	.items = 2,
	.row = 32
};
const struct CFG cfg26 =
{
	.name = "Type->void",
	.process = NULL,
	.parent = &cfg22,
	.items = 1,
	.row = 32
};
const struct CFG cfg27 =
{
	.name = "Type->struct token",
	.process = NULL,
	.parent = &cfg22,
	.items = 2,
	.row = 32
};
const struct CFG cfg28 =
{
	.name = "Realparam'-> Expr | Realparam' , Expr ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 36
};
const struct CFG cfg29 =
{
	.name = "Realparam'->Expr",
	.process = NULL,
	.parent = &cfg28,
	.items = 1,
	.row = 36
};
const struct CFG cfg30 =
{
	.name = "Realparam'->Realparam' , Expr",
	.process = NULL,
	.parent = &cfg28,
	.items = 3,
	.row = 36
};
const struct CFG cfg31 =
{
	.name = "Typedefs-> Typedef | Typedefs Typedef ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 50
};
const struct CFG cfg32 =
{
	.name = "Typedefs->Typedef",
	.process = NULL,
	.parent = &cfg31,
	.items = 1,
	.row = 50
};
const struct CFG cfg33 =
{
	.name = "Typedefs->Typedefs Typedef",
	.process = NULL,
	.parent = &cfg31,
	.items = 2,
	.row = 50
};
const struct CFG cfg34 =
{
	.name = "Paramlist-> void | Paramlist' ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 29
};
const struct CFG cfg35 =
{
	.name = "Paramlist->void",
	.process = NULL,
	.parent = &cfg34,
	.items = 1,
	.row = 29
};
const struct CFG cfg36 =
{
	.name = "Paramlist->Paramlist'",
	.process = NULL,
	.parent = &cfg34,
	.items = 1,
	.row = 29
};
const struct CFG cfg37 =
{
	.name = "Funcdef->Type token ( Paramlist ) Block",
	.process = NULL,
	.parent = NULL,
	.items = 6,
	.row = 33
};
const struct CFG cfg38 =
{
	.name = "Expr-> number | token | ( Expr + Expr ) | ( Expr - Expr ) | ( Expr * Expr ) | ( Expr / Expr ) ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 47
};
const struct CFG cfg39 =
{
	.name = "Expr->number",
	.process = NULL,
	.parent = &cfg38,
	.items = 1,
	.row = 47
};
const struct CFG cfg40 =
{
	.name = "Expr->token",
	.process = NULL,
	.parent = &cfg38,
	.items = 1,
	.row = 47
};
const struct CFG cfg41 =
{
	.name = "Expr->( Expr + Expr )",
	.process = NULL,
	.parent = &cfg38,
	.items = 5,
	.row = 47
};
const struct CFG cfg42 =
{
	.name = "Expr->( Expr - Expr )",
	.process = NULL,
	.parent = &cfg38,
	.items = 5,
	.row = 47
};
const struct CFG cfg43 =
{
	.name = "Expr->( Expr * Expr )",
	.process = NULL,
	.parent = &cfg38,
	.items = 5,
	.row = 47
};
const struct CFG cfg44 =
{
	.name = "Expr->( Expr / Expr )",
	.process = NULL,
	.parent = &cfg38,
	.items = 5,
	.row = 47
};
const struct CFG cfg45 =
{
	.name = "Statement-> Typedef | Funccall seperate | seperate  | Expr seperate | Assign seperate | Return seperate ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 39
};
const struct CFG cfg46 =
{
	.name = "Statement->Typedef",
	.process = NULL,
	.parent = &cfg45,
	.items = 1,
	.row = 39
};
const struct CFG cfg47 =
{
	.name = "Statement->Funccall seperate",
	.process = NULL,
	.parent = &cfg45,
	.items = 2,
	.row = 39
};
const struct CFG cfg48 =
{
	.name = "Statement->seperate",
	.process = NULL,
	.parent = &cfg45,
	.items = 1,
	.row = 39
};
const struct CFG cfg49 =
{
	.name = "Statement->Expr seperate",
	.process = NULL,
	.parent = &cfg45,
	.items = 2,
	.row = 39
};
const struct CFG cfg50 =
{
	.name = "Statement->Assign seperate",
	.process = NULL,
	.parent = &cfg45,
	.items = 2,
	.row = 39
};
const struct CFG cfg51 =
{
	.name = "Statement->Return seperate",
	.process = NULL,
	.parent = &cfg45,
	.items = 2,
	.row = 39
};
const struct CFG cfg52 =
{
	.name = "Paramlist'-> Type token | Paramlist' , Type token ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 30
};
const struct CFG cfg53 =
{
	.name = "Paramlist'->Type token",
	.process = NULL,
	.parent = &cfg52,
	.items = 2,
	.row = 30
};
const struct CFG cfg54 =
{
	.name = "Paramlist'->Paramlist' , Type token",
	.process = NULL,
	.parent = &cfg52,
	.items = 4,
	.row = 30
};
const struct CFG cfg55 =
{
	.name = "While->while ( Expr ) Block",
	.process = NULL,
	.parent = NULL,
	.items = 5,
	.row = 44
};
const struct CFG cfg56 =
{
	.name = "Assign-> token = Funccall | token = Expr | token = ldquota string rdquota ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 48
};
const struct CFG cfg57 =
{
	.name = "Assign->token = Funccall",
	.process = NULL,
	.parent = &cfg56,
	.items = 3,
	.row = 48
};
const struct CFG cfg58 =
{
	.name = "Assign->token = Expr",
	.process = NULL,
	.parent = &cfg56,
	.items = 3,
	.row = 48
};
const struct CFG cfg59 =
{
	.name = "Assign->token = ldquota string rdquota",
	.process = NULL,
	.parent = &cfg56,
	.items = 5,
	.row = 48
};
const struct CFG cfg60 =
{
	.name = "Block->{ Block' }",
	.process = NULL,
	.parent = NULL,
	.items = 3,
	.row = 38
};
const struct CFG cfg61 =
{
	.name = "Block'-> Statement | Block' Statement | If | Block' If  | While | Block' While  |  For | Block' For | Ifelse | Block' Ifelse ",
	.process = NULL,
	.parent = NULL,
	.items = -1, 
	.row = 46
};
const struct CFG cfg62 =
{
	.name = "Block'->Statement",
	.process = NULL,
	.parent = &cfg61,
	.items = 1,
	.row = 46
};
const struct CFG cfg63 =
{
	.name = "Block'->Block' Statement",
	.process = NULL,
	.parent = &cfg61,
	.items = 2,
	.row = 46
};
const struct CFG cfg64 =
{
	.name = "Block'->If",
	.process = NULL,
	.parent = &cfg61,
	.items = 1,
	.row = 46
};
const struct CFG cfg65 =
{
	.name = "Block'->Block' If",
	.process = NULL,
	.parent = &cfg61,
	.items = 2,
	.row = 46
};
const struct CFG cfg66 =
{
	.name = "Block'->While",
	.process = NULL,
	.parent = &cfg61,
	.items = 1,
	.row = 46
};
const struct CFG cfg67 =
{
	.name = "Block'->Block' While",
	.process = NULL,
	.parent = &cfg61,
	.items = 2,
	.row = 46
};
const struct CFG cfg68 =
{
	.name = "Block'->For",
	.process = NULL,
	.parent = &cfg61,
	.items = 1,
	.row = 46
};
const struct CFG cfg69 =
{
	.name = "Block'->Block' For",
	.process = NULL,
	.parent = &cfg61,
	.items = 2,
	.row = 46
};
const struct CFG cfg70 =
{
	.name = "Block'->Ifelse",
	.process = NULL,
	.parent = &cfg61,
	.items = 1,
	.row = 46
};
const struct CFG cfg71 =
{
	.name = "Block'->Block' Ifelse",
	.process = NULL,
	.parent = &cfg61,
	.items = 2,
	.row = 46
};
const struct CFG cfg72 =
{
	.name = "If->if ( Expr ) Block",
	.process = NULL,
	.parent = NULL,
	.items = 5,
	.row = 41
};
/***********************************/
/*错误状态*/
const struct GrammerItem gi_error =
{
	.type = GI_ERR
};
/*接受状态*/
const struct GrammerItem gi_accept =
{
	.type = GI_ACC
};
/************GOTO************/
const struct GrammerItem gi_goto1 =
{
	.type = GI_GOTO,
	.gi_skip = 1
};
const struct GrammerItem gi_goto2 =
{
	.type = GI_GOTO,
	.gi_skip = 2
};
const struct GrammerItem gi_goto3 =
{
	.type = GI_GOTO,
	.gi_skip = 3
};
const struct GrammerItem gi_goto4 =
{
	.type = GI_GOTO,
	.gi_skip = 4
};
const struct GrammerItem gi_goto5 =
{
	.type = GI_GOTO,
	.gi_skip = 5
};
const struct GrammerItem gi_goto11 =
{
	.type = GI_GOTO,
	.gi_skip = 11
};
const struct GrammerItem gi_goto14 =
{
	.type = GI_GOTO,
	.gi_skip = 14
};
const struct GrammerItem gi_goto15 =
{
	.type = GI_GOTO,
	.gi_skip = 15
};
const struct GrammerItem gi_goto16 =
{
	.type = GI_GOTO,
	.gi_skip = 16
};
const struct GrammerItem gi_goto26 =
{
	.type = GI_GOTO,
	.gi_skip = 26
};
const struct GrammerItem gi_goto27 =
{
	.type = GI_GOTO,
	.gi_skip = 27
};
const struct GrammerItem gi_goto28 =
{
	.type = GI_GOTO,
	.gi_skip = 28
};
const struct GrammerItem gi_goto32 =
{
	.type = GI_GOTO,
	.gi_skip = 32
};
const struct GrammerItem gi_goto33 =
{
	.type = GI_GOTO,
	.gi_skip = 33
};
const struct GrammerItem gi_goto34 =
{
	.type = GI_GOTO,
	.gi_skip = 34
};
const struct GrammerItem gi_goto38 =
{
	.type = GI_GOTO,
	.gi_skip = 38
};
const struct GrammerItem gi_goto39 =
{
	.type = GI_GOTO,
	.gi_skip = 39
};
const struct GrammerItem gi_goto42 =
{
	.type = GI_GOTO,
	.gi_skip = 42
};
const struct GrammerItem gi_goto44 =
{
	.type = GI_GOTO,
	.gi_skip = 44
};
const struct GrammerItem gi_goto46 =
{
	.type = GI_GOTO,
	.gi_skip = 46
};
const struct GrammerItem gi_goto48 =
{
	.type = GI_GOTO,
	.gi_skip = 48
};
const struct GrammerItem gi_goto49 =
{
	.type = GI_GOTO,
	.gi_skip = 49
};
const struct GrammerItem gi_goto50 =
{
	.type = GI_GOTO,
	.gi_skip = 50
};
const struct GrammerItem gi_goto51 =
{
	.type = GI_GOTO,
	.gi_skip = 51
};
const struct GrammerItem gi_goto52 =
{
	.type = GI_GOTO,
	.gi_skip = 52
};
const struct GrammerItem gi_goto53 =
{
	.type = GI_GOTO,
	.gi_skip = 53
};
const struct GrammerItem gi_goto54 =
{
	.type = GI_GOTO,
	.gi_skip = 54
};
const struct GrammerItem gi_goto55 =
{
	.type = GI_GOTO,
	.gi_skip = 55
};
const struct GrammerItem gi_goto56 =
{
	.type = GI_GOTO,
	.gi_skip = 56
};
const struct GrammerItem gi_goto57 =
{
	.type = GI_GOTO,
	.gi_skip = 57
};
const struct GrammerItem gi_goto58 =
{
	.type = GI_GOTO,
	.gi_skip = 58
};
const struct GrammerItem gi_goto59 =
{
	.type = GI_GOTO,
	.gi_skip = 59
};
const struct GrammerItem gi_goto71 =
{
	.type = GI_GOTO,
	.gi_skip = 71
};
const struct GrammerItem gi_goto77 =
{
	.type = GI_GOTO,
	.gi_skip = 77
};
const struct GrammerItem gi_goto78 =
{
	.type = GI_GOTO,
	.gi_skip = 78
};
const struct GrammerItem gi_goto79 =
{
	.type = GI_GOTO,
	.gi_skip = 79
};
const struct GrammerItem gi_goto80 =
{
	.type = GI_GOTO,
	.gi_skip = 80
};
const struct GrammerItem gi_goto81 =
{
	.type = GI_GOTO,
	.gi_skip = 81
};
const struct GrammerItem gi_goto86 =
{
	.type = GI_GOTO,
	.gi_skip = 86
};
const struct GrammerItem gi_goto95 =
{
	.type = GI_GOTO,
	.gi_skip = 95
};
const struct GrammerItem gi_goto97 =
{
	.type = GI_GOTO,
	.gi_skip = 97
};
const struct GrammerItem gi_goto103 =
{
	.type = GI_GOTO,
	.gi_skip = 103
};
const struct GrammerItem gi_goto109 =
{
	.type = GI_GOTO,
	.gi_skip = 109
};
const struct GrammerItem gi_goto110 =
{
	.type = GI_GOTO,
	.gi_skip = 110
};
const struct GrammerItem gi_goto111 =
{
	.type = GI_GOTO,
	.gi_skip = 111
};
const struct GrammerItem gi_goto112 =
{
	.type = GI_GOTO,
	.gi_skip = 112
};
const struct GrammerItem gi_goto117 =
{
	.type = GI_GOTO,
	.gi_skip = 117
};
const struct GrammerItem gi_goto118 =
{
	.type = GI_GOTO,
	.gi_skip = 118
};
const struct GrammerItem gi_goto121 =
{
	.type = GI_GOTO,
	.gi_skip = 121
};
const struct GrammerItem gi_goto125 =
{
	.type = GI_GOTO,
	.gi_skip = 125
};
const struct GrammerItem gi_goto126 =
{
	.type = GI_GOTO,
	.gi_skip = 126
};
const struct GrammerItem gi_goto127 =
{
	.type = GI_GOTO,
	.gi_skip = 127
};
const struct GrammerItem gi_goto128 =
{
	.type = GI_GOTO,
	.gi_skip = 128
};
const struct GrammerItem gi_goto129 =
{
	.type = GI_GOTO,
	.gi_skip = 129
};
const struct GrammerItem gi_goto130 =
{
	.type = GI_GOTO,
	.gi_skip = 130
};
const struct GrammerItem gi_goto131 =
{
	.type = GI_GOTO,
	.gi_skip = 131
};
const struct GrammerItem gi_goto133 =
{
	.type = GI_GOTO,
	.gi_skip = 133
};
const struct GrammerItem gi_goto137 =
{
	.type = GI_GOTO,
	.gi_skip = 137
};
const struct GrammerItem gi_goto140 =
{
	.type = GI_GOTO,
	.gi_skip = 140
};
const struct GrammerItem gi_goto141 =
{
	.type = GI_GOTO,
	.gi_skip = 141
};
const struct GrammerItem gi_goto142 =
{
	.type = GI_GOTO,
	.gi_skip = 142
};
const struct GrammerItem gi_goto143 =
{
	.type = GI_GOTO,
	.gi_skip = 143
};
const struct GrammerItem gi_goto144 =
{
	.type = GI_GOTO,
	.gi_skip = 144
};
const struct GrammerItem gi_goto151 =
{
	.type = GI_GOTO,
	.gi_skip = 151
};
const struct GrammerItem gi_goto154 =
{
	.type = GI_GOTO,
	.gi_skip = 154
};
const struct GrammerItem gi_goto157 =
{
	.type = GI_GOTO,
	.gi_skip = 157
};
const struct GrammerItem gi_goto170 =
{
	.type = GI_GOTO,
	.gi_skip = 170
};
const struct GrammerItem gi_goto171 =
{
	.type = GI_GOTO,
	.gi_skip = 171
};
const struct GrammerItem gi_goto172 =
{
	.type = GI_GOTO,
	.gi_skip = 172
};
const struct GrammerItem gi_goto173 =
{
	.type = GI_GOTO,
	.gi_skip = 173
};
const struct GrammerItem gi_goto174 =
{
	.type = GI_GOTO,
	.gi_skip = 174
};
const struct GrammerItem gi_goto180 =
{
	.type = GI_GOTO,
	.gi_skip = 180
};
const struct GrammerItem gi_goto188 =
{
	.type = GI_GOTO,
	.gi_skip = 188
};
const struct GrammerItem gi_goto189 =
{
	.type = GI_GOTO,
	.gi_skip = 189
};
const struct GrammerItem gi_goto190 =
{
	.type = GI_GOTO,
	.gi_skip = 190
};
const struct GrammerItem gi_goto191 =
{
	.type = GI_GOTO,
	.gi_skip = 191
};
const struct GrammerItem gi_goto192 =
{
	.type = GI_GOTO,
	.gi_skip = 192
};
const struct GrammerItem gi_goto193 =
{
	.type = GI_GOTO,
	.gi_skip = 193
};
const struct GrammerItem gi_goto194 =
{
	.type = GI_GOTO,
	.gi_skip = 194
};
const struct GrammerItem gi_goto196 =
{
	.type = GI_GOTO,
	.gi_skip = 196
};
const struct GrammerItem gi_goto201 =
{
	.type = GI_GOTO,
	.gi_skip = 201
};
const struct GrammerItem gi_goto202 =
{
	.type = GI_GOTO,
	.gi_skip = 202
};
const struct GrammerItem gi_goto203 =
{
	.type = GI_GOTO,
	.gi_skip = 203
};
const struct GrammerItem gi_goto204 =
{
	.type = GI_GOTO,
	.gi_skip = 204
};
const struct GrammerItem gi_goto205 =
{
	.type = GI_GOTO,
	.gi_skip = 205
};
const struct GrammerItem gi_goto206 =
{
	.type = GI_GOTO,
	.gi_skip = 206
};
const struct GrammerItem gi_goto207 =
{
	.type = GI_GOTO,
	.gi_skip = 207
};
const struct GrammerItem gi_goto208 =
{
	.type = GI_GOTO,
	.gi_skip = 208
};
const struct GrammerItem gi_goto209 =
{
	.type = GI_GOTO,
	.gi_skip = 209
};
const struct GrammerItem gi_goto210 =
{
	.type = GI_GOTO,
	.gi_skip = 210
};
const struct GrammerItem gi_goto233 =
{
	.type = GI_GOTO,
	.gi_skip = 233
};
const struct GrammerItem gi_goto234 =
{
	.type = GI_GOTO,
	.gi_skip = 234
};
/*************SHIFT***********/
const struct GrammerItem gi_shift6 =
{
	.type = GI_SHIFT,
	.gi_skip = 6
};
const struct GrammerItem gi_shift7 =
{
	.type = GI_SHIFT,
	.gi_skip = 7
};
const struct GrammerItem gi_shift8 =
{
	.type = GI_SHIFT,
	.gi_skip = 8
};
const struct GrammerItem gi_shift9 =
{
	.type = GI_SHIFT,
	.gi_skip = 9
};
const struct GrammerItem gi_shift10 =
{
	.type = GI_SHIFT,
	.gi_skip = 10
};
const struct GrammerItem gi_shift12 =
{
	.type = GI_SHIFT,
	.gi_skip = 12
};
const struct GrammerItem gi_shift13 =
{
	.type = GI_SHIFT,
	.gi_skip = 13
};
const struct GrammerItem gi_shift17 =
{
	.type = GI_SHIFT,
	.gi_skip = 17
};
const struct GrammerItem gi_shift18 =
{
	.type = GI_SHIFT,
	.gi_skip = 18
};
const struct GrammerItem gi_shift19 =
{
	.type = GI_SHIFT,
	.gi_skip = 19
};
const struct GrammerItem gi_shift20 =
{
	.type = GI_SHIFT,
	.gi_skip = 20
};
const struct GrammerItem gi_shift21 =
{
	.type = GI_SHIFT,
	.gi_skip = 21
};
const struct GrammerItem gi_shift22 =
{
	.type = GI_SHIFT,
	.gi_skip = 22
};
const struct GrammerItem gi_shift23 =
{
	.type = GI_SHIFT,
	.gi_skip = 23
};
const struct GrammerItem gi_shift24 =
{
	.type = GI_SHIFT,
	.gi_skip = 24
};
const struct GrammerItem gi_shift25 =
{
	.type = GI_SHIFT,
	.gi_skip = 25
};
const struct GrammerItem gi_shift29 =
{
	.type = GI_SHIFT,
	.gi_skip = 29
};
const struct GrammerItem gi_shift30 =
{
	.type = GI_SHIFT,
	.gi_skip = 30
};
const struct GrammerItem gi_shift31 =
{
	.type = GI_SHIFT,
	.gi_skip = 31
};
const struct GrammerItem gi_shift35 =
{
	.type = GI_SHIFT,
	.gi_skip = 35
};
const struct GrammerItem gi_shift36 =
{
	.type = GI_SHIFT,
	.gi_skip = 36
};
const struct GrammerItem gi_shift37 =
{
	.type = GI_SHIFT,
	.gi_skip = 37
};
const struct GrammerItem gi_shift40 =
{
	.type = GI_SHIFT,
	.gi_skip = 40
};
const struct GrammerItem gi_shift41 =
{
	.type = GI_SHIFT,
	.gi_skip = 41
};
const struct GrammerItem gi_shift43 =
{
	.type = GI_SHIFT,
	.gi_skip = 43
};
const struct GrammerItem gi_shift45 =
{
	.type = GI_SHIFT,
	.gi_skip = 45
};
const struct GrammerItem gi_shift47 =
{
	.type = GI_SHIFT,
	.gi_skip = 47
};
const struct GrammerItem gi_shift60 =
{
	.type = GI_SHIFT,
	.gi_skip = 60
};
const struct GrammerItem gi_shift61 =
{
	.type = GI_SHIFT,
	.gi_skip = 61
};
const struct GrammerItem gi_shift62 =
{
	.type = GI_SHIFT,
	.gi_skip = 62
};
const struct GrammerItem gi_shift63 =
{
	.type = GI_SHIFT,
	.gi_skip = 63
};
const struct GrammerItem gi_shift64 =
{
	.type = GI_SHIFT,
	.gi_skip = 64
};
const struct GrammerItem gi_shift65 =
{
	.type = GI_SHIFT,
	.gi_skip = 65
};
const struct GrammerItem gi_shift66 =
{
	.type = GI_SHIFT,
	.gi_skip = 66
};
const struct GrammerItem gi_shift67 =
{
	.type = GI_SHIFT,
	.gi_skip = 67
};
const struct GrammerItem gi_shift68 =
{
	.type = GI_SHIFT,
	.gi_skip = 68
};
const struct GrammerItem gi_shift69 =
{
	.type = GI_SHIFT,
	.gi_skip = 69
};
const struct GrammerItem gi_shift70 =
{
	.type = GI_SHIFT,
	.gi_skip = 70
};
const struct GrammerItem gi_shift72 =
{
	.type = GI_SHIFT,
	.gi_skip = 72
};
const struct GrammerItem gi_shift73 =
{
	.type = GI_SHIFT,
	.gi_skip = 73
};
const struct GrammerItem gi_shift74 =
{
	.type = GI_SHIFT,
	.gi_skip = 74
};
const struct GrammerItem gi_shift75 =
{
	.type = GI_SHIFT,
	.gi_skip = 75
};
const struct GrammerItem gi_shift76 =
{
	.type = GI_SHIFT,
	.gi_skip = 76
};
const struct GrammerItem gi_shift82 =
{
	.type = GI_SHIFT,
	.gi_skip = 82
};
const struct GrammerItem gi_shift83 =
{
	.type = GI_SHIFT,
	.gi_skip = 83
};
const struct GrammerItem gi_shift84 =
{
	.type = GI_SHIFT,
	.gi_skip = 84
};
const struct GrammerItem gi_shift85 =
{
	.type = GI_SHIFT,
	.gi_skip = 85
};
const struct GrammerItem gi_shift87 =
{
	.type = GI_SHIFT,
	.gi_skip = 87
};
const struct GrammerItem gi_shift88 =
{
	.type = GI_SHIFT,
	.gi_skip = 88
};
const struct GrammerItem gi_shift89 =
{
	.type = GI_SHIFT,
	.gi_skip = 89
};
const struct GrammerItem gi_shift90 =
{
	.type = GI_SHIFT,
	.gi_skip = 90
};
const struct GrammerItem gi_shift91 =
{
	.type = GI_SHIFT,
	.gi_skip = 91
};
const struct GrammerItem gi_shift92 =
{
	.type = GI_SHIFT,
	.gi_skip = 92
};
const struct GrammerItem gi_shift93 =
{
	.type = GI_SHIFT,
	.gi_skip = 93
};
const struct GrammerItem gi_shift94 =
{
	.type = GI_SHIFT,
	.gi_skip = 94
};
const struct GrammerItem gi_shift96 =
{
	.type = GI_SHIFT,
	.gi_skip = 96
};
const struct GrammerItem gi_shift98 =
{
	.type = GI_SHIFT,
	.gi_skip = 98
};
const struct GrammerItem gi_shift99 =
{
	.type = GI_SHIFT,
	.gi_skip = 99
};
const struct GrammerItem gi_shift100 =
{
	.type = GI_SHIFT,
	.gi_skip = 100
};
const struct GrammerItem gi_shift101 =
{
	.type = GI_SHIFT,
	.gi_skip = 101
};
const struct GrammerItem gi_shift102 =
{
	.type = GI_SHIFT,
	.gi_skip = 102
};
const struct GrammerItem gi_shift104 =
{
	.type = GI_SHIFT,
	.gi_skip = 104
};
const struct GrammerItem gi_shift105 =
{
	.type = GI_SHIFT,
	.gi_skip = 105
};
const struct GrammerItem gi_shift106 =
{
	.type = GI_SHIFT,
	.gi_skip = 106
};
const struct GrammerItem gi_shift107 =
{
	.type = GI_SHIFT,
	.gi_skip = 107
};
const struct GrammerItem gi_shift108 =
{
	.type = GI_SHIFT,
	.gi_skip = 108
};
const struct GrammerItem gi_shift113 =
{
	.type = GI_SHIFT,
	.gi_skip = 113
};
const struct GrammerItem gi_shift114 =
{
	.type = GI_SHIFT,
	.gi_skip = 114
};
const struct GrammerItem gi_shift115 =
{
	.type = GI_SHIFT,
	.gi_skip = 115
};
const struct GrammerItem gi_shift116 =
{
	.type = GI_SHIFT,
	.gi_skip = 116
};
const struct GrammerItem gi_shift119 =
{
	.type = GI_SHIFT,
	.gi_skip = 119
};
const struct GrammerItem gi_shift120 =
{
	.type = GI_SHIFT,
	.gi_skip = 120
};
const struct GrammerItem gi_shift122 =
{
	.type = GI_SHIFT,
	.gi_skip = 122
};
const struct GrammerItem gi_shift123 =
{
	.type = GI_SHIFT,
	.gi_skip = 123
};
const struct GrammerItem gi_shift124 =
{
	.type = GI_SHIFT,
	.gi_skip = 124
};
const struct GrammerItem gi_shift132 =
{
	.type = GI_SHIFT,
	.gi_skip = 132
};
const struct GrammerItem gi_shift134 =
{
	.type = GI_SHIFT,
	.gi_skip = 134
};
const struct GrammerItem gi_shift135 =
{
	.type = GI_SHIFT,
	.gi_skip = 135
};
const struct GrammerItem gi_shift136 =
{
	.type = GI_SHIFT,
	.gi_skip = 136
};
const struct GrammerItem gi_shift138 =
{
	.type = GI_SHIFT,
	.gi_skip = 138
};
const struct GrammerItem gi_shift139 =
{
	.type = GI_SHIFT,
	.gi_skip = 139
};
const struct GrammerItem gi_shift145 =
{
	.type = GI_SHIFT,
	.gi_skip = 145
};
const struct GrammerItem gi_shift146 =
{
	.type = GI_SHIFT,
	.gi_skip = 146
};
const struct GrammerItem gi_shift147 =
{
	.type = GI_SHIFT,
	.gi_skip = 147
};
const struct GrammerItem gi_shift148 =
{
	.type = GI_SHIFT,
	.gi_skip = 148
};
const struct GrammerItem gi_shift149 =
{
	.type = GI_SHIFT,
	.gi_skip = 149
};
const struct GrammerItem gi_shift150 =
{
	.type = GI_SHIFT,
	.gi_skip = 150
};
const struct GrammerItem gi_shift152 =
{
	.type = GI_SHIFT,
	.gi_skip = 152
};
const struct GrammerItem gi_shift153 =
{
	.type = GI_SHIFT,
	.gi_skip = 153
};
const struct GrammerItem gi_shift155 =
{
	.type = GI_SHIFT,
	.gi_skip = 155
};
const struct GrammerItem gi_shift156 =
{
	.type = GI_SHIFT,
	.gi_skip = 156
};
const struct GrammerItem gi_shift158 =
{
	.type = GI_SHIFT,
	.gi_skip = 158
};
const struct GrammerItem gi_shift159 =
{
	.type = GI_SHIFT,
	.gi_skip = 159
};
const struct GrammerItem gi_shift160 =
{
	.type = GI_SHIFT,
	.gi_skip = 160
};
const struct GrammerItem gi_shift161 =
{
	.type = GI_SHIFT,
	.gi_skip = 161
};
const struct GrammerItem gi_shift162 =
{
	.type = GI_SHIFT,
	.gi_skip = 162
};
const struct GrammerItem gi_shift163 =
{
	.type = GI_SHIFT,
	.gi_skip = 163
};
const struct GrammerItem gi_shift164 =
{
	.type = GI_SHIFT,
	.gi_skip = 164
};
const struct GrammerItem gi_shift165 =
{
	.type = GI_SHIFT,
	.gi_skip = 165
};
const struct GrammerItem gi_shift166 =
{
	.type = GI_SHIFT,
	.gi_skip = 166
};
const struct GrammerItem gi_shift167 =
{
	.type = GI_SHIFT,
	.gi_skip = 167
};
const struct GrammerItem gi_shift168 =
{
	.type = GI_SHIFT,
	.gi_skip = 168
};
const struct GrammerItem gi_shift169 =
{
	.type = GI_SHIFT,
	.gi_skip = 169
};
const struct GrammerItem gi_shift175 =
{
	.type = GI_SHIFT,
	.gi_skip = 175
};
const struct GrammerItem gi_shift176 =
{
	.type = GI_SHIFT,
	.gi_skip = 176
};
const struct GrammerItem gi_shift177 =
{
	.type = GI_SHIFT,
	.gi_skip = 177
};
const struct GrammerItem gi_shift178 =
{
	.type = GI_SHIFT,
	.gi_skip = 178
};
const struct GrammerItem gi_shift179 =
{
	.type = GI_SHIFT,
	.gi_skip = 179
};
const struct GrammerItem gi_shift181 =
{
	.type = GI_SHIFT,
	.gi_skip = 181
};
const struct GrammerItem gi_shift182 =
{
	.type = GI_SHIFT,
	.gi_skip = 182
};
const struct GrammerItem gi_shift183 =
{
	.type = GI_SHIFT,
	.gi_skip = 183
};
const struct GrammerItem gi_shift184 =
{
	.type = GI_SHIFT,
	.gi_skip = 184
};
const struct GrammerItem gi_shift185 =
{
	.type = GI_SHIFT,
	.gi_skip = 185
};
const struct GrammerItem gi_shift186 =
{
	.type = GI_SHIFT,
	.gi_skip = 186
};
const struct GrammerItem gi_shift187 =
{
	.type = GI_SHIFT,
	.gi_skip = 187
};
const struct GrammerItem gi_shift195 =
{
	.type = GI_SHIFT,
	.gi_skip = 195
};
const struct GrammerItem gi_shift197 =
{
	.type = GI_SHIFT,
	.gi_skip = 197
};
const struct GrammerItem gi_shift198 =
{
	.type = GI_SHIFT,
	.gi_skip = 198
};
const struct GrammerItem gi_shift199 =
{
	.type = GI_SHIFT,
	.gi_skip = 199
};
const struct GrammerItem gi_shift200 =
{
	.type = GI_SHIFT,
	.gi_skip = 200
};
const struct GrammerItem gi_shift211 =
{
	.type = GI_SHIFT,
	.gi_skip = 211
};
const struct GrammerItem gi_shift212 =
{
	.type = GI_SHIFT,
	.gi_skip = 212
};
const struct GrammerItem gi_shift213 =
{
	.type = GI_SHIFT,
	.gi_skip = 213
};
const struct GrammerItem gi_shift214 =
{
	.type = GI_SHIFT,
	.gi_skip = 214
};
const struct GrammerItem gi_shift215 =
{
	.type = GI_SHIFT,
	.gi_skip = 215
};
const struct GrammerItem gi_shift216 =
{
	.type = GI_SHIFT,
	.gi_skip = 216
};
const struct GrammerItem gi_shift217 =
{
	.type = GI_SHIFT,
	.gi_skip = 217
};
const struct GrammerItem gi_shift218 =
{
	.type = GI_SHIFT,
	.gi_skip = 218
};
const struct GrammerItem gi_shift219 =
{
	.type = GI_SHIFT,
	.gi_skip = 219
};
const struct GrammerItem gi_shift220 =
{
	.type = GI_SHIFT,
	.gi_skip = 220
};
const struct GrammerItem gi_shift221 =
{
	.type = GI_SHIFT,
	.gi_skip = 221
};
const struct GrammerItem gi_shift222 =
{
	.type = GI_SHIFT,
	.gi_skip = 222
};
const struct GrammerItem gi_shift223 =
{
	.type = GI_SHIFT,
	.gi_skip = 223
};
const struct GrammerItem gi_shift224 =
{
	.type = GI_SHIFT,
	.gi_skip = 224
};
const struct GrammerItem gi_shift225 =
{
	.type = GI_SHIFT,
	.gi_skip = 225
};
const struct GrammerItem gi_shift226 =
{
	.type = GI_SHIFT,
	.gi_skip = 226
};
const struct GrammerItem gi_shift227 =
{
	.type = GI_SHIFT,
	.gi_skip = 227
};
const struct GrammerItem gi_shift228 =
{
	.type = GI_SHIFT,
	.gi_skip = 228
};
const struct GrammerItem gi_shift229 =
{
	.type = GI_SHIFT,
	.gi_skip = 229
};
const struct GrammerItem gi_shift230 =
{
	.type = GI_SHIFT,
	.gi_skip = 230
};
const struct GrammerItem gi_shift231 =
{
	.type = GI_SHIFT,
	.gi_skip = 231
};
const struct GrammerItem gi_shift232 =
{
	.type = GI_SHIFT,
	.gi_skip = 232
};
const struct GrammerItem gi_shift235 =
{
	.type = GI_SHIFT,
	.gi_skip = 235
};
const struct GrammerItem gi_shift236 =
{
	.type = GI_SHIFT,
	.gi_skip = 236
};
const struct GrammerItem gi_shift237 =
{
	.type = GI_SHIFT,
	.gi_skip = 237
};
const struct GrammerItem gi_shift238 =
{
	.type = GI_SHIFT,
	.gi_skip = 238
};
const struct GrammerItem gi_shift239 =
{
	.type = GI_SHIFT,
	.gi_skip = 239
};
/**************REDUCE***********/
const struct GrammerItem gi_reduce0 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg0
};
const struct GrammerItem gi_reduce2 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg2
};
const struct GrammerItem gi_reduce3 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg3
};
const struct GrammerItem gi_reduce4 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg4
};
const struct GrammerItem gi_reduce5 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg5
};
const struct GrammerItem gi_reduce6 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg6
};
const struct GrammerItem gi_reduce7 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg7
};
const struct GrammerItem gi_reduce9 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg9
};
const struct GrammerItem gi_reduce10 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg10
};
const struct GrammerItem gi_reduce11 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg11
};
const struct GrammerItem gi_reduce12 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg12
};
const struct GrammerItem gi_reduce13 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg13
};
const struct GrammerItem gi_reduce15 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg15
};
const struct GrammerItem gi_reduce16 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg16
};
const struct GrammerItem gi_reduce19 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg19
};
const struct GrammerItem gi_reduce20 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg20
};
const struct GrammerItem gi_reduce21 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg21
};
const struct GrammerItem gi_reduce23 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg23
};
const struct GrammerItem gi_reduce24 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg24
};
const struct GrammerItem gi_reduce25 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg25
};
const struct GrammerItem gi_reduce26 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg26
};
const struct GrammerItem gi_reduce27 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg27
};
const struct GrammerItem gi_reduce29 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg29
};
const struct GrammerItem gi_reduce30 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg30
};
const struct GrammerItem gi_reduce32 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg32
};
const struct GrammerItem gi_reduce33 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg33
};
const struct GrammerItem gi_reduce35 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg35
};
const struct GrammerItem gi_reduce36 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg36
};
const struct GrammerItem gi_reduce37 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg37
};
const struct GrammerItem gi_reduce39 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg39
};
const struct GrammerItem gi_reduce40 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg40
};
const struct GrammerItem gi_reduce41 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg41
};
const struct GrammerItem gi_reduce42 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg42
};
const struct GrammerItem gi_reduce43 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg43
};
const struct GrammerItem gi_reduce44 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg44
};
const struct GrammerItem gi_reduce46 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg46
};
const struct GrammerItem gi_reduce47 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg47
};
const struct GrammerItem gi_reduce48 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg48
};
const struct GrammerItem gi_reduce49 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg49
};
const struct GrammerItem gi_reduce50 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg50
};
const struct GrammerItem gi_reduce51 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg51
};
const struct GrammerItem gi_reduce53 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg53
};
const struct GrammerItem gi_reduce54 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg54
};
const struct GrammerItem gi_reduce55 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg55
};
const struct GrammerItem gi_reduce57 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg57
};
const struct GrammerItem gi_reduce58 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg58
};
const struct GrammerItem gi_reduce59 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg59
};
const struct GrammerItem gi_reduce60 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg60
};
const struct GrammerItem gi_reduce62 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg62
};
const struct GrammerItem gi_reduce63 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg63
};
const struct GrammerItem gi_reduce64 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg64
};
const struct GrammerItem gi_reduce65 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg65
};
const struct GrammerItem gi_reduce66 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg66
};
const struct GrammerItem gi_reduce67 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg67
};
const struct GrammerItem gi_reduce68 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg68
};
const struct GrammerItem gi_reduce69 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg69
};
const struct GrammerItem gi_reduce70 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg70
};
const struct GrammerItem gi_reduce71 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg71
};
const struct GrammerItem gi_reduce72 =
{
	.type = GI_REDUCE,
	.gi_cfg = &cfg72
};
/**************好大一只状态表*************/
const struct GrammerItem* lr1_table[TABLE_COLUMNS][TABLE_ROWS] = {
/*状态0的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,    &gi_shift7,    &gi_shift8,
	     &gi_error,     &gi_error,     &gi_error,    &gi_shift9,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_goto1,     &gi_error,
	     &gi_error,     &gi_goto2,     &gi_goto3,     &gi_goto4,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_goto5,
	     &gi_error,     &gi_error,
	},
/*状态1的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_accept,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态2的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,    &gi_shift7,    &gi_shift8,
	     &gi_error,     &gi_error,     &gi_error,    &gi_shift9,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,    &gi_goto11,     &gi_error,
	     &gi_error,     &gi_goto2,     &gi_goto3,     &gi_goto4,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_goto5,
	     &gi_error,     &gi_error,
	},
/*状态3的行*/
	{
	     &gi_error,     &gi_error,   &gi_shift12,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift13,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态4的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,    &gi_shift7,    &gi_shift8,
	     &gi_error,     &gi_error,     &gi_error,    &gi_shift9,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,    &gi_goto14,     &gi_error,
	     &gi_error,     &gi_goto2,     &gi_goto3,     &gi_goto4,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_goto5,
	     &gi_error,     &gi_error,
	},
/*状态5的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,    &gi_shift7,    &gi_shift8,
	     &gi_error,     &gi_error,     &gi_error,    &gi_shift9,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,    &gi_goto15,     &gi_error,
	     &gi_error,     &gi_goto2,     &gi_goto3,     &gi_goto4,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_goto5,
	     &gi_error,     &gi_error,
	},
/*状态6的行*/
	{
	     &gi_error,     &gi_error,  &gi_reduce23,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce23,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态7的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto16,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态8的行*/
	{
	     &gi_error,     &gi_error,  &gi_reduce24,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	   &gi_shift19,     &gi_error,  &gi_reduce24,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态9的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift20,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态10的行*/
	{
	     &gi_error,     &gi_error,  &gi_reduce26,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce26,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态11的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce11,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态12的行*/
	{
	     &gi_error,     &gi_error,  &gi_reduce25,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce25,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态13的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift21,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态14的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce10,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态15的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce12,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态16的行*/
	{
	     &gi_error,     &gi_error,   &gi_shift12,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift22,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态17的行*/
	{
	     &gi_error,     &gi_error,  &gi_reduce24,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce24,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态18的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift23,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态19的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift24,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态20的行*/
	{
	     &gi_error,     &gi_error,  &gi_reduce27,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift25,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce27,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态21的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift29,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_goto26,
	    &gi_goto27,     &gi_error,    &gi_goto28,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态22的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift30,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态23的行*/
	{
	     &gi_error,     &gi_error,  &gi_reduce27,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce27,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态24的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift31,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态25的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto32,     &gi_error,    &gi_goto33,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	    &gi_goto34,     &gi_error,
	},
/*状态26的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift35,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态27的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce36,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	   &gi_shift36,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态28的行*/
	{
	     &gi_error,     &gi_error,   &gi_shift12,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift37,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态29的行*/
	{
	     &gi_error,     &gi_error,  &gi_reduce26,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce35,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce26,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态30的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift29,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_goto38,
	    &gi_goto27,     &gi_error,    &gi_goto28,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态31的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift40,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,    &gi_goto39,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态32的行*/
	{
	     &gi_error,     &gi_error,   &gi_shift12,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift41,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态33的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce32,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce32,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce32,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce32,  &gi_reduce32,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态34的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_shift43,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto32,     &gi_error,    &gi_goto42,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态35的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift45,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,    &gi_goto44,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态36的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto46,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态37的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce53,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_reduce53,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态38的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift47,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态39的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_reduce9,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态40的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift62,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,   &gi_shift64,     &gi_error,   &gi_shift65,
	   &gi_shift66,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto48,     &gi_error,    &gi_goto49,
	     &gi_error,     &gi_error,    &gi_goto50,     &gi_error,    &gi_goto51,
	     &gi_error,    &gi_goto52,    &gi_goto53,    &gi_goto54,    &gi_goto55,
	     &gi_error,    &gi_goto56,    &gi_goto57,    &gi_goto58,     &gi_error,
	     &gi_error,    &gi_goto59,
	},
/*状态41的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift68,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift69,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态42的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce33,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce33,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce33,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce33,  &gi_reduce33,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态43的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift70,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态44的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce37,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce37,  &gi_reduce37,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce37,  &gi_reduce37,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态45的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift62,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,   &gi_shift64,     &gi_error,   &gi_shift65,
	   &gi_shift66,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto48,     &gi_error,    &gi_goto49,
	     &gi_error,     &gi_error,    &gi_goto50,     &gi_error,    &gi_goto51,
	     &gi_error,    &gi_goto52,    &gi_goto53,    &gi_goto54,    &gi_goto55,
	     &gi_error,    &gi_goto71,    &gi_goto57,    &gi_goto58,     &gi_error,
	     &gi_error,    &gi_goto59,
	},
/*状态46的行*/
	{
	     &gi_error,     &gi_error,   &gi_shift12,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift72,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态47的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift73,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态48的行*/
	{
	     &gi_error,     &gi_error,   &gi_shift12,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift74,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态49的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce46,
	  &gi_reduce46,  &gi_reduce46,     &gi_error,     &gi_error,  &gi_reduce46,
	     &gi_error,  &gi_reduce46,  &gi_reduce46,     &gi_error,  &gi_reduce46,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce46,  &gi_reduce46,
	     &gi_error,     &gi_error,  &gi_reduce46,     &gi_error,  &gi_reduce46,
	  &gi_reduce46,  &gi_reduce46,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态50的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift75,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态51的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce62,
	  &gi_reduce62,  &gi_reduce62,     &gi_error,     &gi_error,  &gi_reduce62,
	     &gi_error,  &gi_reduce62,  &gi_reduce62,     &gi_error,  &gi_reduce62,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce62,  &gi_reduce62,
	     &gi_error,     &gi_error,  &gi_reduce62,     &gi_error,  &gi_reduce62,
	  &gi_reduce62,  &gi_reduce62,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态52的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce64,
	  &gi_reduce64,  &gi_reduce64,     &gi_error,     &gi_error,  &gi_reduce64,
	     &gi_error,  &gi_reduce64,  &gi_reduce64,     &gi_error,  &gi_reduce64,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce64,  &gi_reduce64,
	     &gi_error,     &gi_error,  &gi_reduce64,   &gi_shift76,  &gi_reduce64,
	  &gi_reduce64,  &gi_reduce64,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态53的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce70,
	  &gi_reduce70,  &gi_reduce70,     &gi_error,     &gi_error,  &gi_reduce70,
	     &gi_error,  &gi_reduce70,  &gi_reduce70,     &gi_error,  &gi_reduce70,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce70,  &gi_reduce70,
	     &gi_error,     &gi_error,  &gi_reduce70,     &gi_error,  &gi_reduce70,
	  &gi_reduce70,  &gi_reduce70,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态54的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce68,
	  &gi_reduce68,  &gi_reduce68,     &gi_error,     &gi_error,  &gi_reduce68,
	     &gi_error,  &gi_reduce68,  &gi_reduce68,     &gi_error,  &gi_reduce68,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce68,  &gi_reduce68,
	     &gi_error,     &gi_error,  &gi_reduce68,     &gi_error,  &gi_reduce68,
	  &gi_reduce68,  &gi_reduce68,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态55的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce66,
	  &gi_reduce66,  &gi_reduce66,     &gi_error,     &gi_error,  &gi_reduce66,
	     &gi_error,  &gi_reduce66,  &gi_reduce66,     &gi_error,  &gi_reduce66,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce66,  &gi_reduce66,
	     &gi_error,     &gi_error,  &gi_reduce66,     &gi_error,  &gi_reduce66,
	  &gi_reduce66,  &gi_reduce66,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态56的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,   &gi_shift82,
	     &gi_error,   &gi_shift62,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,   &gi_shift64,     &gi_error,   &gi_shift65,
	   &gi_shift66,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto48,     &gi_error,    &gi_goto49,
	     &gi_error,     &gi_error,    &gi_goto50,     &gi_error,    &gi_goto77,
	     &gi_error,    &gi_goto78,    &gi_goto79,    &gi_goto80,    &gi_goto81,
	     &gi_error,     &gi_error,    &gi_goto57,    &gi_goto58,     &gi_error,
	     &gi_error,    &gi_goto59,
	},
/*状态57的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift83,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态58的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift84,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态59的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift85,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态60的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce39,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态61的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	   &gi_shift87,   &gi_shift88,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift89,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto86,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态62的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce48,
	  &gi_reduce48,  &gi_reduce48,     &gi_error,     &gi_error,  &gi_reduce48,
	     &gi_error,  &gi_reduce48,  &gi_reduce48,     &gi_error,  &gi_reduce48,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce48,  &gi_reduce48,
	     &gi_error,     &gi_error,  &gi_reduce48,     &gi_error,  &gi_reduce48,
	  &gi_reduce48,  &gi_reduce48,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态63的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift90,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce40,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift91,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态64的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift92,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态65的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift93,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态66的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift94,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态67的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce19,   &gi_shift96,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto95,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态68的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce2,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce2,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce2,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce2,   &gi_reduce2,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态69的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	   &gi_shift98,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift99,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto97,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态70的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce6,   &gi_reduce6,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce6,   &gi_reduce6,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态71的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,  &gi_shift100,
	     &gi_error,   &gi_shift62,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,   &gi_shift64,     &gi_error,   &gi_shift65,
	   &gi_shift66,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto48,     &gi_error,    &gi_goto49,
	     &gi_error,     &gi_error,    &gi_goto50,     &gi_error,    &gi_goto77,
	     &gi_error,    &gi_goto78,    &gi_goto79,    &gi_goto80,    &gi_goto81,
	     &gi_error,     &gi_error,    &gi_goto57,    &gi_goto58,     &gi_error,
	     &gi_error,    &gi_goto59,
	},
/*状态72的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce54,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_reduce54,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态73的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce0,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce0,   &gi_reduce0,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce0,   &gi_reduce0,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态74的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift101,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift102,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态75的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce47,
	  &gi_reduce47,  &gi_reduce47,     &gi_error,     &gi_error,  &gi_reduce47,
	     &gi_error,  &gi_reduce47,  &gi_reduce47,     &gi_error,  &gi_reduce47,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce47,  &gi_reduce47,
	     &gi_error,     &gi_error,  &gi_reduce47,     &gi_error,  &gi_reduce47,
	  &gi_reduce47,  &gi_reduce47,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态76的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,  &gi_shift104,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,   &gi_goto103,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态77的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce63,
	  &gi_reduce63,  &gi_reduce63,     &gi_error,     &gi_error,  &gi_reduce63,
	     &gi_error,  &gi_reduce63,  &gi_reduce63,     &gi_error,  &gi_reduce63,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce63,  &gi_reduce63,
	     &gi_error,     &gi_error,  &gi_reduce63,     &gi_error,  &gi_reduce63,
	  &gi_reduce63,  &gi_reduce63,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态78的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce65,
	  &gi_reduce65,  &gi_reduce65,     &gi_error,     &gi_error,  &gi_reduce65,
	     &gi_error,  &gi_reduce65,  &gi_reduce65,     &gi_error,  &gi_reduce65,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce65,  &gi_reduce65,
	     &gi_error,     &gi_error,  &gi_reduce65,   &gi_shift76,  &gi_reduce65,
	  &gi_reduce65,  &gi_reduce65,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态79的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce71,
	  &gi_reduce71,  &gi_reduce71,     &gi_error,     &gi_error,  &gi_reduce71,
	     &gi_error,  &gi_reduce71,  &gi_reduce71,     &gi_error,  &gi_reduce71,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce71,  &gi_reduce71,
	     &gi_error,     &gi_error,  &gi_reduce71,     &gi_error,  &gi_reduce71,
	  &gi_reduce71,  &gi_reduce71,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态80的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce69,
	  &gi_reduce69,  &gi_reduce69,     &gi_error,     &gi_error,  &gi_reduce69,
	     &gi_error,  &gi_reduce69,  &gi_reduce69,     &gi_error,  &gi_reduce69,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce69,  &gi_reduce69,
	     &gi_error,     &gi_error,  &gi_reduce69,     &gi_error,  &gi_reduce69,
	  &gi_reduce69,  &gi_reduce69,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态81的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce67,
	  &gi_reduce67,  &gi_reduce67,     &gi_error,     &gi_error,  &gi_reduce67,
	     &gi_error,  &gi_reduce67,  &gi_reduce67,     &gi_error,  &gi_reduce67,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce67,  &gi_reduce67,
	     &gi_error,     &gi_error,  &gi_reduce67,     &gi_error,  &gi_reduce67,
	  &gi_reduce67,  &gi_reduce67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态82的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce60,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态83的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce49,
	  &gi_reduce49,  &gi_reduce49,     &gi_error,     &gi_error,  &gi_reduce49,
	     &gi_error,  &gi_reduce49,  &gi_reduce49,     &gi_error,  &gi_reduce49,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce49,  &gi_reduce49,
	     &gi_error,     &gi_error,  &gi_reduce49,     &gi_error,  &gi_reduce49,
	  &gi_reduce49,  &gi_reduce49,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态84的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce50,
	  &gi_reduce50,  &gi_reduce50,     &gi_error,     &gi_error,  &gi_reduce50,
	     &gi_error,  &gi_reduce50,  &gi_reduce50,     &gi_error,  &gi_reduce50,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce50,  &gi_reduce50,
	     &gi_error,     &gi_error,  &gi_reduce50,     &gi_error,  &gi_reduce50,
	  &gi_reduce50,  &gi_reduce50,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态85的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce51,
	  &gi_reduce51,  &gi_reduce51,     &gi_error,     &gi_error,  &gi_reduce51,
	     &gi_error,  &gi_reduce51,  &gi_reduce51,     &gi_error,  &gi_reduce51,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce51,  &gi_reduce51,
	     &gi_error,     &gi_error,  &gi_reduce51,     &gi_error,  &gi_reduce51,
	  &gi_reduce51,  &gi_reduce51,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态86的行*/
	{
	  &gi_shift105,  &gi_shift106,  &gi_shift107,  &gi_shift108,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态87的行*/
	{
	  &gi_reduce39,  &gi_reduce39,  &gi_reduce39,  &gi_reduce39,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态88的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	   &gi_shift87,   &gi_shift88,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift89,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto109,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态89的行*/
	{
	  &gi_reduce40,  &gi_reduce40,  &gi_reduce40,  &gi_reduce40,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态90的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift113,  &gi_shift114,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift115,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_shift116,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	   &gi_goto110,   &gi_goto111,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto112,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态91的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift119,     &gi_error,     &gi_error,
	  &gi_shift120,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto117,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto118,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态92的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto121,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态93的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift132,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto125,     &gi_error,   &gi_goto126,
	     &gi_error,     &gi_error,   &gi_goto127,     &gi_error,   &gi_goto128,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto129,   &gi_goto130,     &gi_error,
	     &gi_error,   &gi_goto131,
	},
/*状态94的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto133,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态95的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce20,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态96的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce40,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态97的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift134,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态98的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift135,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态99的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift90,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift136,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态100的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce60,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce60,  &gi_reduce60,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce60,  &gi_reduce60,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态101的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce2,
	   &gi_reduce2,   &gi_reduce2,     &gi_error,     &gi_error,   &gi_reduce2,
	     &gi_error,   &gi_reduce2,   &gi_reduce2,     &gi_error,   &gi_reduce2,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce2,   &gi_reduce2,
	     &gi_error,     &gi_error,   &gi_reduce2,     &gi_error,   &gi_reduce2,
	   &gi_reduce2,   &gi_reduce2,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态102的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift138,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift139,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto137,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态103的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce13,
	  &gi_reduce13,  &gi_reduce13,     &gi_error,     &gi_error,  &gi_reduce13,
	     &gi_error,  &gi_reduce13,  &gi_reduce13,     &gi_error,  &gi_reduce13,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce13,  &gi_reduce13,
	     &gi_error,     &gi_error,  &gi_reduce13,     &gi_error,  &gi_reduce13,
	  &gi_reduce13,  &gi_reduce13,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态104的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift62,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,   &gi_shift64,     &gi_error,   &gi_shift65,
	   &gi_shift66,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto48,     &gi_error,    &gi_goto49,
	     &gi_error,     &gi_error,    &gi_goto50,     &gi_error,    &gi_goto51,
	     &gi_error,    &gi_goto52,    &gi_goto53,    &gi_goto54,    &gi_goto55,
	     &gi_error,   &gi_goto140,    &gi_goto57,    &gi_goto58,     &gi_error,
	     &gi_error,    &gi_goto59,
	},
/*状态105的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto141,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态106的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto142,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态107的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto143,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态108的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto144,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态109的行*/
	{
	  &gi_shift145,  &gi_shift146,  &gi_shift147,  &gi_shift148,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态110的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift149,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态111的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce16,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift150,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态112的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce29,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_reduce29,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态113的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce39,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_reduce39,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态114的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	   &gi_shift87,   &gi_shift88,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift89,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto151,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态115的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce40,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_reduce40,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态116的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce15,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态117的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce57,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态118的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce58,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态119的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift90,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce40,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态120的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift152,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态121的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift153,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态122的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce39,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态123的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	   &gi_shift87,   &gi_shift88,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_shift89,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto154,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态124的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce40,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态125的行*/
	{
	     &gi_error,     &gi_error,   &gi_shift12,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift155,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态126的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce46,
	  &gi_reduce46,  &gi_reduce46,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce46,  &gi_reduce46,     &gi_error,  &gi_reduce46,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce46,  &gi_reduce46,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce46,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态127的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift156,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态128的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift132,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto125,     &gi_error,   &gi_goto126,
	     &gi_error,     &gi_error,   &gi_goto127,     &gi_error,   &gi_goto157,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto129,   &gi_goto130,     &gi_error,
	     &gi_error,   &gi_goto131,
	},
/*状态129的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift158,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态130的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift159,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态131的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift160,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态132的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce48,
	  &gi_reduce48,  &gi_reduce48,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce48,  &gi_reduce48,     &gi_error,  &gi_reduce48,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce48,  &gi_reduce48,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce48,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态133的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift161,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态134的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce5,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce5,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce5,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce5,   &gi_reduce5,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态135的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce4,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce4,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce4,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce4,   &gi_reduce4,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态136的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce3,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce3,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce3,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce3,   &gi_reduce3,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态137的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift162,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态138的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift163,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态139的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift90,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift164,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态140的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,  &gi_shift165,
	     &gi_error,   &gi_shift62,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,   &gi_shift64,     &gi_error,   &gi_shift65,
	   &gi_shift66,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto48,     &gi_error,    &gi_goto49,
	     &gi_error,     &gi_error,    &gi_goto50,     &gi_error,    &gi_goto77,
	     &gi_error,    &gi_goto78,    &gi_goto79,    &gi_goto80,    &gi_goto81,
	     &gi_error,     &gi_error,    &gi_goto57,    &gi_goto58,     &gi_error,
	     &gi_error,    &gi_goto59,
	},
/*状态141的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift166,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态142的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift167,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态143的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift168,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态144的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift169,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态145的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto170,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态146的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto171,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态147的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto172,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态148的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto173,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态149的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce21,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态150的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift113,  &gi_shift114,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift115,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto174,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态151的行*/
	{
	  &gi_shift175,  &gi_shift176,  &gi_shift177,  &gi_shift178,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态152的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift179,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态153的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,  &gi_shift181,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,   &gi_goto180,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态154的行*/
	{
	  &gi_shift182,  &gi_shift183,  &gi_shift184,  &gi_shift185,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态155的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift186,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift187,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态156的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce47,
	  &gi_reduce47,  &gi_reduce47,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce47,  &gi_reduce47,     &gi_error,  &gi_reduce47,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce47,  &gi_reduce47,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce47,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态157的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift195,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto188,     &gi_error,   &gi_goto189,
	     &gi_error,     &gi_error,   &gi_goto190,     &gi_error,   &gi_goto191,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto192,   &gi_goto193,     &gi_error,
	     &gi_error,   &gi_goto194,
	},
/*状态158的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce49,
	  &gi_reduce49,  &gi_reduce49,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce49,  &gi_reduce49,     &gi_error,  &gi_reduce49,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce49,  &gi_reduce49,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce49,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态159的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce50,
	  &gi_reduce50,  &gi_reduce50,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce50,  &gi_reduce50,     &gi_error,  &gi_reduce50,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce50,  &gi_reduce50,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce50,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态160的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce51,
	  &gi_reduce51,  &gi_reduce51,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce51,  &gi_reduce51,     &gi_error,  &gi_reduce51,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce51,  &gi_reduce51,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce51,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态161的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,  &gi_shift104,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,   &gi_goto196,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态162的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce5,
	   &gi_reduce5,   &gi_reduce5,     &gi_error,     &gi_error,   &gi_reduce5,
	     &gi_error,   &gi_reduce5,   &gi_reduce5,     &gi_error,   &gi_reduce5,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce5,   &gi_reduce5,
	     &gi_error,     &gi_error,   &gi_reduce5,     &gi_error,   &gi_reduce5,
	   &gi_reduce5,   &gi_reduce5,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态163的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce4,
	   &gi_reduce4,   &gi_reduce4,     &gi_error,     &gi_error,   &gi_reduce4,
	     &gi_error,   &gi_reduce4,   &gi_reduce4,     &gi_error,   &gi_reduce4,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce4,   &gi_reduce4,
	     &gi_error,     &gi_error,   &gi_reduce4,     &gi_error,   &gi_reduce4,
	   &gi_reduce4,   &gi_reduce4,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态164的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce3,
	   &gi_reduce3,   &gi_reduce3,     &gi_error,     &gi_error,   &gi_reduce3,
	     &gi_error,   &gi_reduce3,   &gi_reduce3,     &gi_error,   &gi_reduce3,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce3,   &gi_reduce3,
	     &gi_error,     &gi_error,   &gi_reduce3,     &gi_error,   &gi_reduce3,
	   &gi_reduce3,   &gi_reduce3,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态165的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce60,
	  &gi_reduce60,  &gi_reduce60,     &gi_error,     &gi_error,  &gi_reduce60,
	     &gi_error,  &gi_reduce60,  &gi_reduce60,     &gi_error,  &gi_reduce60,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce60,  &gi_reduce60,
	     &gi_error,     &gi_error,  &gi_reduce60,     &gi_error,  &gi_reduce60,
	  &gi_reduce60,  &gi_reduce60,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态166的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce41,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态167的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce42,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态168的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce43,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态169的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce44,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态170的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift197,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态171的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift198,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态172的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift199,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态173的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift200,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态174的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce30,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_reduce30,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态175的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto201,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态176的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto202,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态177的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto203,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态178的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto204,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态179的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_reduce59,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态180的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce72,
	  &gi_reduce72,  &gi_reduce72,     &gi_error,     &gi_error,  &gi_reduce72,
	     &gi_error,  &gi_reduce72,  &gi_reduce72,     &gi_error,  &gi_reduce72,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce72,  &gi_reduce72,
	     &gi_error,     &gi_error,  &gi_reduce72,  &gi_reduce72,  &gi_reduce72,
	  &gi_reduce72,  &gi_reduce72,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态181的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift62,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,   &gi_shift64,     &gi_error,   &gi_shift65,
	   &gi_shift66,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto48,     &gi_error,    &gi_goto49,
	     &gi_error,     &gi_error,    &gi_goto50,     &gi_error,    &gi_goto51,
	     &gi_error,    &gi_goto52,    &gi_goto53,    &gi_goto54,    &gi_goto55,
	     &gi_error,   &gi_goto205,    &gi_goto57,    &gi_goto58,     &gi_error,
	     &gi_error,    &gi_goto59,
	},
/*状态182的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto206,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态183的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto207,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态184的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto208,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态185的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift122,  &gi_shift123,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift124,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto209,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态186的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce2,
	   &gi_reduce2,   &gi_reduce2,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_reduce2,   &gi_reduce2,     &gi_error,   &gi_reduce2,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce2,   &gi_reduce2,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_reduce2,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态187的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift211,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift212,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto210,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态188的行*/
	{
	     &gi_error,     &gi_error,   &gi_shift12,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift213,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态189的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce46,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态190的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift214,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态191的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift215,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态192的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift216,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态193的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift217,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态194的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift218,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态195的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce48,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态196的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce55,
	  &gi_reduce55,  &gi_reduce55,     &gi_error,     &gi_error,  &gi_reduce55,
	     &gi_error,  &gi_reduce55,  &gi_reduce55,     &gi_error,  &gi_reduce55,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce55,  &gi_reduce55,
	     &gi_error,     &gi_error,  &gi_reduce55,     &gi_error,  &gi_reduce55,
	  &gi_reduce55,  &gi_reduce55,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态197的行*/
	{
	  &gi_reduce41,  &gi_reduce41,  &gi_reduce41,  &gi_reduce41,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态198的行*/
	{
	  &gi_reduce42,  &gi_reduce42,  &gi_reduce42,  &gi_reduce42,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态199的行*/
	{
	  &gi_reduce43,  &gi_reduce43,  &gi_reduce43,  &gi_reduce43,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态200的行*/
	{
	  &gi_reduce44,  &gi_reduce44,  &gi_reduce44,  &gi_reduce44,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态201的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift219,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态202的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift220,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态203的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift221,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态204的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift222,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态205的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,    &gi_shift6,
	   &gi_shift60,   &gi_shift61,     &gi_error,     &gi_error,  &gi_shift223,
	     &gi_error,   &gi_shift62,   &gi_shift63,     &gi_error,   &gi_shift17,
	     &gi_error,     &gi_error,     &gi_error,   &gi_shift18,   &gi_shift10,
	     &gi_error,     &gi_error,   &gi_shift64,     &gi_error,   &gi_shift65,
	   &gi_shift66,   &gi_shift67,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,    &gi_goto48,     &gi_error,    &gi_goto49,
	     &gi_error,     &gi_error,    &gi_goto50,     &gi_error,    &gi_goto77,
	     &gi_error,    &gi_goto78,    &gi_goto79,    &gi_goto80,    &gi_goto81,
	     &gi_error,     &gi_error,    &gi_goto57,    &gi_goto58,     &gi_error,
	     &gi_error,    &gi_goto59,
	},
/*状态206的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift224,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态207的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift225,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态208的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift226,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态209的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift227,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态210的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift228,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态211的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift229,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态212的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift90,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift230,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态213的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift231,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift232,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态214的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce47,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态215的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,  &gi_shift104,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,   &gi_goto233,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态216的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce49,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态217的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce50,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态218的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce51,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态219的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce41,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_reduce41,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态220的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce42,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_reduce42,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态221的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce43,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_reduce43,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态222的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce44,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_reduce44,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态223的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,  &gi_reduce60,
	  &gi_reduce60,  &gi_reduce60,     &gi_error,     &gi_error,  &gi_reduce60,
	     &gi_error,  &gi_reduce60,  &gi_reduce60,     &gi_error,  &gi_reduce60,
	     &gi_error,     &gi_error,     &gi_error,  &gi_reduce60,  &gi_reduce60,
	     &gi_error,     &gi_error,  &gi_reduce60,  &gi_reduce60,  &gi_reduce60,
	  &gi_reduce60,  &gi_reduce60,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态224的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce41,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态225的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce42,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态226的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce43,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态227的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_reduce44,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态228的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce5,
	   &gi_reduce5,   &gi_reduce5,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_reduce5,   &gi_reduce5,     &gi_error,   &gi_reduce5,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce5,   &gi_reduce5,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_reduce5,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态229的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce4,
	   &gi_reduce4,   &gi_reduce4,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_reduce4,   &gi_reduce4,     &gi_error,   &gi_reduce4,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce4,   &gi_reduce4,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_reduce4,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态230的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce3,
	   &gi_reduce3,   &gi_reduce3,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_reduce3,   &gi_reduce3,     &gi_error,   &gi_reduce3,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce3,   &gi_reduce3,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_reduce3,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态231的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_reduce2,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态232的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	  &gi_shift235,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,  &gi_shift236,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_goto234,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态233的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,   &gi_reduce7,
	   &gi_reduce7,   &gi_reduce7,     &gi_error,     &gi_error,   &gi_reduce7,
	     &gi_error,   &gi_reduce7,   &gi_reduce7,     &gi_error,   &gi_reduce7,
	     &gi_error,     &gi_error,     &gi_error,   &gi_reduce7,   &gi_reduce7,
	     &gi_error,     &gi_error,   &gi_reduce7,     &gi_error,   &gi_reduce7,
	   &gi_reduce7,   &gi_reduce7,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态234的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift237,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态235的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift238,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态236的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,   &gi_shift90,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,  &gi_shift239,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态237的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_reduce5,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态238的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_reduce4,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
/*状态239的行*/
	{
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,   &gi_reduce3,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,     &gi_error,     &gi_error,     &gi_error,
	     &gi_error,     &gi_error,
	},
};
