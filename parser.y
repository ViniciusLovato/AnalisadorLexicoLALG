%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;

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
	| error 
	{ 
		printf("dc_c error\n");
		int syncArray[] = { lalg_var, lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};

dc_v : lalg_var variaveis lalg_colon tipo_var lalg_semicolon dc_v 
	| %empty
	| error
	{ 
		printf("dc_v error\n");
		int syncArray[] = { lalg_procedure, lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};


tipo_var : lalg_real | lalg_integer
	| error
	{ 
		printf("tipo_var error\n");
		int syncArray[] = { lalg_semicolon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};


variaveis : var_identifier mais_var
	| error
	{ 
		printf("variaveis error\n");
		int syncArray[] = { lalg_colon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};


mais_var : lalg_comma variaveis | %empty
	| error
	{ 
		printf("mais_var error\n");
		int syncArray[] = { lalg_colon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};



dc_p : lalg_procedure var_identifier parametros lalg_semicolon corpo_p dc_p | %empty
	| error
	{ 
		printf("procedure error\n");
		int syncArray[] = { lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};



dc_f : lalg_function var_identifier parametros lalg_colon tipo_var corpo_p dc_f | %empty
	| error
	{ 
		printf("function error\n");
		int syncArray[] = { lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


parametros : lalg_leftp lista_par lalg_rightp | %empty
	| error
	{ 
		printf("parametros error\n");
		int syncArray[] = { lalg_semicolon };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


lista_par : variaveis lalg_colon tipo_var mais_par
	| error
	{ 
		printf("lista_par error\n");
		int syncArray[] = { lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


mais_par : lalg_semicolon lista_par | %empty
	| error
	{ 
		printf("mais_par error\n");
		int syncArray[] = { lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


corpo_p : dc_loc lalg_begin comandos lalg_end lalg_semicolon
	| error
	{ 
		printf("corpo error\n");
		int syncArray[] = { lalg_procedure, lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};

dc_loc : dc_v;


lista_arg : lalg_leftp argumentos lalg_rightp | %empty
	| error
	{ 
		printf("lista_arg error\n");
		int syncArray[] = { lalg_semicolon };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


argumentos : var_identifier mais_ident
	| error
	{ 
		printf("argumentos error\n");
		int syncArray[] = { lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};

mais_ident : lalg_semicolon argumentos | %empty
	| error
	{ 
		printf("mais_ident error\n");
		int syncArray[] = { lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


pfalsa : lalg_else cmd | %empty
	| error
	{ 
		printf("pfalsa error\n");
		int syncArray[] = { lalg_semicolon };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


comandos : cmd lalg_semicolon comandos | %empty
	| error
	{ 
		printf("comandos error\n");
		int syncArray[] = { lalg_end };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


cmd : lalg_read lalg_leftp variaveis lalg_rightp 
	| lalg_write lalg_leftp variaveis lalg_rightp 
	| lalg_while lalg_leftp condicao lalg_rightp lalg_do cmd
	| lalg_for var_identifier lalg_assignment expressao lalg_to expressao lalg_do cmd
	| lalg_if condicao lalg_then cmd pfalsa
	| var_identifier lalg_assignment expressao
	| var_identifier lista_arg 
	| lalg_begin comandos lalg_end
	| error
	{ 
		printf("cmd error\n");
		int syncArray[] = { lalg_semicolon };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};



condicao : expressao relacao expressao
	| error
	{ 
		printf("condicao error\n");
		int syncArray[] = { lalg_rightp, lalg_then };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};


relacao : lalg_equal | lalg_n_equal | lalg_g_than |lalg_l_than | lalg_ge_than | lalg_le_than
	| error
	{ 
		printf("relacao error\n");
		int syncArray[] = { lalg_add, lalg_sub, var_identifier, var_real, var_integer, lalg_leftp };
		yyclearin;
		yyerrok;
		panic(syncArray, 6);
	};


expressao : termo outros_termos
	| error
	{ 
		printf("expressao error\n");
		int syncArray[] = { lalg_semicolon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};


op_un : lalg_add | lalg_sub | %empty
	| error
	{ 
		printf("op_un error\n");
		int syncArray[] = { var_identifier, var_real, var_integer, lalg_leftp };
		yyclearin;
		yyerrok;
		panic(syncArray, 4);
	};


outros_termos : op_ad termo outros_termos | %empty
	| error
	{ 
		printf("outros_termos error\n");
		int syncArray[] = { lalg_colon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};


op_ad : lalg_add | lalg_sub
	| error
	{ 
		printf("op_ad error\n");
		int syncArray[] = { lalg_add, lalg_sub, var_identifier, var_real, var_integer };
		yyclearin;
		yyerrok;
		panic(syncArray, 5);
	};


termo : op_un fator mais_fatores
	| error
	{ 
		printf("termo error\n");
		int syncArray[] = { lalg_semicolon, lalg_rightp, lalg_add, lalg_sub, var_identifier, var_real, var_integer, lalg_leftp };
		yyclearin;
		yyerrok;
		panic(syncArray, 8);
	};

mais_fatores : op_mul fator mais_fatores | %empty
	| error
	{ 
		printf("mais_fatores error\n");
		int syncArray[] = { lalg_semicolon, lalg_rightp, lalg_add, lalg_sub };
		yyclearin;
		yyerrok;
		panic(syncArray, 4);
	};


op_mul : lalg_mul | lalg_div
	| error
	{ 
		printf("op_mul error\n");
		int syncArray[] = { var_identifier, var_real, var_integer, lalg_leftp};
		yyclearin;
		yyerrok;
		panic(syncArray, 4);
	};


fator : var_identifier | var_numero | lalg_leftp expressao lalg_rightp
	| error
	{ 
		printf("fator error\n");
		int syncArray[] = { lalg_mul, lalg_div, lalg_add, var_identifier, var_real, var_integer, lalg_leftp};
		yyclearin;
		yyerrok;
		panic(syncArray, 7);
	};

var_numero : var_integer | var_real
	| error
	{ 
		printf("var_numero error\n");
		int syncArray[] = { var_identifier, var_real, var_integer, lalg_leftp};
		yyclearin;
		yyerrok;
		panic(syncArray, 5);
	};
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

// Function that prints the error message
void yyerror(char *s)
{
	fprintf(stderr, "Parser: %s na linha %d, token \'%s\' nao esperado\n", s, yylineno, yylval.str);
}

int main(int argc, char **argv)
{
	int status;

	// Uncomment his flag to turn debug mode on for the parser
	//yydebug = 1;

	// Checks if the program has 1 argument and pass it as a program to be analized
	if(argc == 2)
		yyin = fopen(argv[1], "r");

	// Creating the init buffer and pushing it into flex internal stack
	createInitBuffer();
	// Parsing the file and saving the status 
	status = yyparse();

	return (status);
}

// Function that verifies if a token belongs to the syncArray
int verifyToken(int* syncArray, int size, int token)
{
	int i;
	for(i = 0; i < size; i++)
	{
		//printf("looping: token: %d syncarray[i]: %d\n", token, syncArray[i]);
		if(token == syncArray[i])
		{
			return i;
		}
	}

	return(-1);
}

// Function that implements the panic mode error recovery
void panic(int* array, int size)
{
        int tokenTest = 0;
	
        printf("** Entering in panic mode **\n");

	// Keep skipping tokens until you find the syncronization token or the file ends
	do{
                tokenTest = yylex();
                printf("Token skipped: \'%s\' - code: %d\n", yylval.str, tokenTest);
        }while(verifyToken(array, size, tokenTest) < 0 && tokenTest != 0);
	// Pushing the string into flex intenal stack
	if(tokenTest != 0)
	{
		pushBuffer(yylval.str);
	}
	else
	{
		yyerror("Fim de arquivo nao esperado");
		exit(1);
	}

	printf("** Exiting panic mode **\n");
}
