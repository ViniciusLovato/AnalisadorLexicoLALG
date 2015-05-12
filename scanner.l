%{ 

#include "y.tab.h"

#define ERROR_LONG_ID 501
#define ERROR_LONG_NUMBER 502
#define ERROR_INVALID_IDENTIFIER 503
#define ERROR_INVALID_NUMBER 504
#define ERROR_NON_ALPHANUMERIC 505

%}
%option nounput yylineno

%%

"program" return lalg_program;
"begin" return lalg_begin;
"end" return lalg_end;

"const" return lalg_const;
"var" return lalg_var;
"real" return lalg_real;
"integer" return lalg_integer;
"char" return lalg_char;

"procedure" return lalg_procedure;
"function" return lalg_function;
"read" return lalg_read;
"write" return lalg_write;
"while" return lalg_while;
"do" return lalg_do;
"for" return lalg_for;
"to"|"downto" return lalg_to;
"if" return lalg_if;
"then" return lalg_then;
"else" return lalg_else;


[a-zA-Z][_a-zA-Z0-9]{30,}	return ERROR_LONG_ID;
[a-zA-Z][_a-zA-Z0-9]*	return var_identifier;
[1-9][0-9]{10,}		return ERROR_LONG_NUMBER;;
[0-9]*			return var_integer;
[0-9]*"."[0-9]+		return var_real;
\'.\'			return var_char;
\".*\"			return var_string;
[\ \t\n]		;
":"			return lalg_colon;
";"			return lalg_semicolon;
","			return lalg_comma;
"."			return lalg_period;

"+"			return lalg_add;
"-"			return lalg_sub;
"*"			return lalg_mul;
"/"			return lalg_div;

"="			return lalg_equal;
"<>"			return lalg_n_equal;
">"			return lalg_g_than;
"<"			return lalg_l_than;
">="			return lalg_ge_than;
"<="			return lalg_le_than;
":="			return lalg_assignment;

"("			return lalg_leftp;
")"			return lalg_rightp;

"{".*"}"		;

[a-zA-Z]+([^a-zA-Z0-9_\d\n\t\{\}\:\;\,\.\+\-\*\\/\(\)\=\+\-\"\'\>\< ]+[a-zA-Z0-9_]*)*		return ERROR_INVALID_IDENTIFIER;
[0-9]+(".")[0-9]*([^0-9\t\{\}\:\;\,\.\+\-\*\\/\(\)\=\+\-\"\'\>\< ]+[0-9]*)*	return ERROR_INVALID_NUMBER;
[^a-zA-Z0-9\d\n\t\{\}\:\;\,\.\+\-\*\\/\(\)\=\+\-\"\'\>\< ]+		return ERROR_NON_ALPHANUMERIC;

%%

int yywrap(void){
	return 1;
}
