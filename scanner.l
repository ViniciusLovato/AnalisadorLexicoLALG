%{ 

#include "y.tab.h"

#define ERROR_LONG_ID 501
#define ERROR_LONG_NUMBER 502
#define ERROR_INVALID_IDENTIFIER 503
#define ERROR_INVALID_NUMBER 504
#define ERROR_NON_ALPHANUMERIC 505

int buffer_counter;
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

// Function that pushes the yyin buffer in the stack
void createInitBuffer()
{
	buffer_counter = 1;
	// Initializing the buffer
	init_buffer = yy_create_buffer(yyin, YY_BUF_SIZE);
	// Pushing the buffer into the stack
	yypush_buffer_state(init_buffer);
}

void pushBuffer(char *str)
{
	// Saving the current buffer
	YY_BUFFER_STATE current = YY_CURRENT_BUFFER;
	// Creating the string buffer (side effect: it automatic switches to this buffer)
	YY_BUFFER_STATE string = yy_scan_string(str);
	// Returning to the current buffer
	yy_switch_to_buffer(current);
	// Pushing the string buffer in the stack
	yypush_buffer_state(string);
}

// Function that destroy the init buffer 
void destroyInitBuffer()
{
	yy_delete_buffer(init_buffer);
}

// Function that decides what to do when you reach the end of a file
int yywrap(void){

	// decreases buffer counter
	--buffer_counter;
	// pop the buffer state
	yypop_buffer_state();

	// if there is only one buffer stop concatenating files
	if(buffer_counter <= 1)
	{
		
		return 1;
	}
	else
	{
		// send a signal to concatenate next buffer 
		return 0;
	}
}
