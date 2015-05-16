%{ 

#include "y.tab.h"

#define ERROR_LONG_ID 501
#define ERROR_LONG_NUMBER 502
#define ERROR_INVALID_IDENTIFIER 503
#define ERROR_INVALID_NUMBER 504
#define ERROR_NON_ALPHANUMERIC 505

void printInitBufferStatus();
void printBufferStatus();
int buffer_counter = 1;
YY_BUFFER_STATE init_buffer;

%}

%option nounput yylineno
%option stack

%%

"program" { yylval.str = strdup(yytext); return lalg_program;};
"begin" { yylval.str = strdup(yytext); return lalg_begin;};
"end" { yylval.str = strdup(yytext); return lalg_end;};

"const" { yylval.str = strdup(yytext); return lalg_const;};
"var" { yylval.str = strdup(yytext); return lalg_var;};
"real" { yylval.str = strdup(yytext); return lalg_real;};
"integer" { yylval.str = strdup(yytext); return lalg_integer;};
"char" { yylval.str = strdup(yytext); return lalg_char;};

"procedure" { yylval.str = strdup(yytext); return lalg_procedure;};
"function" { yylval.str = strdup(yytext); return lalg_function;};
"read" { yylval.str = strdup(yytext); return lalg_read;};
"write" { yylval.str = strdup(yytext); return lalg_write;};
"while" { yylval.str = strdup(yytext); return lalg_while;};
"do" { yylval.str = strdup(yytext); return lalg_do;};
"for" { yylval.str = strdup(yytext); return lalg_for;};
"to"|"downto" { yylval.str = strdup(yytext); return lalg_to;};
"if" { yylval.str = strdup(yytext); return lalg_if;};
"then" { yylval.str = strdup(yytext); return lalg_then;};
"else" { yylval.str = strdup(yytext); return lalg_else;};


[a-zA-Z][_a-zA-Z0-9]{30,}	return ERROR_LONG_ID;
[a-zA-Z][_a-zA-Z0-9]*	{ yylval.str = strdup(yytext); return var_identifier;};
[1-9][0-9]{10,}		return ERROR_LONG_NUMBER;;
[0-9]*			return var_integer;
[0-9]*"."[0-9]+		{ yylval.str = strdup(yytext); return var_real;};
\'.\'			{ yylval.str = strdup(yytext); return var_char;};
\".*\"			{ yylval.str = strdup(yytext); return var_string;};
[\ \t\n]		;
":"			{ yylval.str = strdup(yytext); return lalg_colon;};
";"			{ yylval.str = strdup(yytext); return lalg_semicolon;};
","			{ yylval.str = strdup(yytext); return lalg_comma;};
"."			{ yylval.str = strdup(yytext); return lalg_period;};

"+"			{ yylval.str = strdup(yytext); return lalg_add;};
"-"			{ yylval.str = strdup(yytext); return lalg_sub;};
"*"			{ yylval.str = strdup(yytext); return lalg_mul;};
"/"			{ yylval.str = strdup(yytext); return lalg_div;};

"="			{ yylval.str = strdup(yytext); return lalg_equal;};
"<>"			{ yylval.str = strdup(yytext); return lalg_n_equal;};
">"			{ yylval.str = strdup(yytext); return lalg_g_than;};
"<"			{ yylval.str = strdup(yytext); return lalg_l_than;};
">="			{ yylval.str = strdup(yytext); return lalg_ge_than;};
"<="			{ yylval.str = strdup(yytext); return lalg_le_than;};
":="			{ yylval.str = strdup(yytext); return lalg_assignment;};

"("			{ yylval.str = strdup(yytext); return lalg_leftp;};
")"			{ yylval.str = strdup(yytext); return lalg_rightp;};

"{".*"}"		;

<<EOF>> {
			if(buffer_counter == 0)
				return 0;
		};

[a-zA-Z]+([^a-zA-Z0-9_\d\n\t\{\}\:\;\,\.\+\-\*\\/\(\)\=\+\-\"\'\>\< ]+[a-zA-Z0-9_]*)*		return ERROR_INVALID_IDENTIFIER;
[0-9]+(".")[0-9]*([^0-9\t\{\}\:\;\,\.\+\-\*\\/\(\)\=\+\-\"\'\>\< ]+[0-9]*)*	return ERROR_INVALID_NUMBER;
[^a-zA-Z0-9\d\n\t\{\}\:\;\,\.\+\-\*\\/\(\)\=\+\-\"\'\>\< ]+		return ERROR_NON_ALPHANUMERIC;

%%

void initBuffers()
{
	// starting the stack
	init_buffer = yy_create_buffer(yyin, YY_BUF_SIZE);
	yypush_buffer_state(init_buffer);
}

void printInitBufferStatus()
{
	printf("**********************************************\n");
	printf("INIT BUFFER STATUS\n");
	printf("**********************************************\n");
 	printf("%s\n", init_buffer->yy_ch_buf);
	printf("**********************************************\n");
	printf("CURRENT POSITION: %s\n", init_buffer->yy_buf_pos);
	printf("**********************************************\n");
	printf("**********************************************\n\n\n");
}

void printBufferStatus()
{
	printf("**********************************************\n");
	printf("BUFFER STATUS\n");
	printf("**********************************************\n");
 	printf("%s\n", YY_CURRENT_BUFFER->yy_ch_buf);
	printf("**********************************************\n");
	printf("CURRENT POSITION: %s\n", YY_CURRENT_BUFFER->yy_buf_pos);
	printf("**********************************************\n");
	printf("**********************************************\n\n\n");
}

int yywrap1(void)
{
	return 1;
}

int yywrap(void){

	--buffer_counter;
	yy_switch_to_buffer(init_buffer);

	printf("BC: %d\n", buffer_counter);
	if(buffer_counter <= 1)
	{
		
		printf("terminated\n");
		return 1;
		yyterminate();
		//yypop_buffer_state();
	}
	else
	{
		return 0;
	}
}
