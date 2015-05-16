%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
extern int buffer_counter;

#define YY_BUF_SIZE 32768

extern int yylex();
extern FILE* yyin;
void yyerror(char *s);
void panic(int* array, int size);

%}

%union {char* str;}
%start programa

%token var_identifier
%token var_real
%token var_integer
%token var_char
%token var_string

%token lalg_integer
%token lalg_real
%token lalg_char
%token lalg_string

%token lalg_add
%token lalg_sub
%token lalg_mul
%token lalg_div

%token lalg_equal
%token lalg_n_equal
%token lalg_g_than
%token lalg_l_than

%token lalg_ge_than
%token lalg_le_than
%token lalg_assignment

%token lalg_leftp
%token lalg_rightp
%token lalg_colon
%token lalg_semicolon
%token lalg_period
%token lalg_comma

%token lalg_program
%token lalg_procedure
%token lalg_function
%token lalg_begin
%token lalg_end
%token lalg_const
%token lalg_var

%token lalg_read
%token lalg_write
%token lalg_while
%token lalg_do
%token lalg_for
%token lalg_to
%token lalg_if
%token lalg_then
%token lalg_else

%debug
%%

programa : lalg_program var_identifier lalg_semicolon corpo lalg_period;

corpo : dc lalg_begin comandos lalg_end;

dc : dc_c dc_v dc_p dc_f;

dc_c : lalg_const var_identifier lalg_equal var_numero lalg_semicolon dc_c 
	| %empty 
	| lalg_const error 
	{ 
		int syncArray[] = { lalg_var, lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};

dc_v : lalg_var variaveis lalg_colon tipo_var lalg_semicolon dc_v | %empty; 

tipo_var : lalg_real | lalg_integer;

variaveis : var_identifier mais_var;

mais_var : lalg_comma variaveis | %empty;

dc_p : lalg_procedure var_identifier parametros lalg_semicolon corpo_p dc_p | %empty;

dc_f : lalg_function var_identifier parametros lalg_colon tipo_var corpo_p dc_f | %empty;

parametros : lalg_leftp lista_par lalg_rightp | %empty;

lista_par : variaveis lalg_colon tipo_var mais_par;

mais_par : lalg_semicolon lista_par | %empty;

corpo_p : dc_loc lalg_begin comandos lalg_end lalg_semicolon;

dc_loc : dc_v;

lista_arg : lalg_leftp argumentos lalg_rightp | %empty;

argumentos : var_identifier mais_ident;

mais_ident : lalg_semicolon argumentos | %empty;

pfalsa : lalg_else cmd | %empty

comandos : cmd lalg_semicolon comandos | %empty;

cmd : lalg_read lalg_leftp variaveis lalg_rightp 
	| lalg_write lalg_leftp variaveis lalg_rightp 
	| lalg_while lalg_leftp condicao lalg_rightp lalg_do cmd
	| lalg_for var_identifier lalg_assignment expressao lalg_to expressao lalg_do cmd
	| lalg_if condicao lalg_then cmd pfalsa
	| var_identifier lalg_assignment expressao
	| var_identifier lista_arg 
	| lalg_begin comandos lalg_end

condicao : expressao relacao expressao;

relacao : lalg_equal | lalg_n_equal | lalg_g_than |lalg_l_than | lalg_ge_than | lalg_le_than;

expressao : termo outros_termos;

op_un : lalg_add | lalg_sub | %empty;

outros_termos : op_ad termo outros_termos | %empty;

op_ad : lalg_add | lalg_sub;

termo : op_un fator mais_fatores;

mais_fatores : op_mul fator mais_fatores | %empty;

op_mul : lalg_mul | lalg_div;

fator : var_identifier | var_numero | lalg_leftp expressao lalg_rightp

var_numero : var_integer | var_real;

%%

#define lalg_EOF 0

int syncArrayProgram[] = { lalg_EOF };
int syncArrayCorpo[] = { lalg_period };
int syncArrayDc[] = { lalg_begin };
int syncArrayDcc[] = { lalg_var, lalg_begin };
int syncArrayDcv[] = { lalg_procedure, lalg_begin };
int syncArrayTipoVar[] = { lalg_semicolon, lalg_rightp };
int syncArrayVariaveis[] = { lalg_colon, lalg_rightp };
int syncArrayMaisVar[] = { lalg_colon, lalg_rightp };
int syncArrayDcp[] = { lalg_begin };

void yyerror(char *s)
{
        fprintf(stderr, "Parser: erro %s na linha %d, token \'%s\' nao esperado\n", s, yylineno, yylval.str);
}

int main(int argc, char **argv)
{
	//yydebug = 1;
	if(argc == 2)
		yyin = fopen(argv[1], "r");

	initBuffers();
	return yyparse();
}

// Function that verifies if a token belongs to the syncArray
int verifyToken(int* syncArray, int size, int token)
{
	int i;
	for(i = 0; i < size; i++)
	{
                printf("Tokens eval: %d\n", syncArray[i]);
		if(token == syncArray[i])
		{
			return i;
		}
	}

	return(-1);
}

void panic(int* array, int size)
{
        int tokenTest = 0;

        printf("** Entering in panic mode **\n");
        tokenTest = yylex();

        while(verifyToken(array, size, tokenTest) && tokenTest != 0){
                printf("Tokens skipped: %d\n", tokenTest);
                tokenTest = yylex();
        }

        printf("** antes push **\n");
	//yypush_buffer_state(yy_scan_string(yylval.str));
	yy_switch_to_buffer(yy_scan_string(yylval.str));
	++buffer_counter;

	printf("** Exiting in panic mode **\n");
}
