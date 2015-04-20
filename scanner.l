%{ 

#include "scanner.h"

%}
%option nounput yylineno

%%

[a-zA-Z][_a-zA-Z0-9]{30,}	return ERROR_LONG_ID;
[a-zA-Z][_a-zA-Z0-9]*	return IDENTIFIER;
[1-9][0-9]*		return INTEGER;
[0-9]*"."[0-9]+		return REAL;
\'.\'			return CHAR;
\".*\"			return STRING;
[\ \t\n]		;
":"			return COLON;
";"			return SEMICOLON;
","			return COMMA;
"."			return PERIOD;

"+"			return ADD;
"-"			return SUB;
"*"			return MUL;
"/"			return DIV;

"="			return EQUAL;
"<>"			return N_EQUAL;
">"			return G_THAN;
"<"			return L_THAN;
">="			return GE_THAN;
"<="			return LE_THAN;
":="			return ASSIGNMENT;

"("			return LEFT_P;
")"			return RIGHT_P;

"{".*"}"		;

[^a-zA-Z\d\s\n\t\{\}\:\;\,\.\+\-\*\\/\(\)\=\+\-\"\'\>\<]+		return ERROR_NON_ALPHANUMERIC;

%%

int yywrap(void){
	return 1;
}
