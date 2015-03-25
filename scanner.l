%{ 

#include "scanner.h"

%}
%option nounput yylineno

%%

[a-zA-Z][_a-zA-Z0-9]*	return IDENTIFIER;
[1-9][0-9]*		return INTEGER;
[0-9]*"."[0-9]+		return REAL;
\'.\'			return CHAR;
\".*\"			return STRING;
[\ \t\n]		;


.+			return ERROR;

%%

int yywrap(void){
	return 1;
}
