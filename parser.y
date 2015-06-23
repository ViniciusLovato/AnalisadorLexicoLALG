%{
#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.h"
#include "param.h"
#include <string.h>
extern int yylineno;

#define YY_BUF_SIZE 32768

extern int yylex();
extern FILE* yyin;
void yyerror(char *s);
void panic(int* array, int size);

str* symbolTable = NULL;
str* scope = NULL;



%}

%union {char* str;
		int type;
		param* parameter;
	   }
%type <str> variaveis;
%type <str> var_identifier;
%type <str> mais_var;

%type <type> tipo_var;
%type <type> var_numero;

%type <parameter> lista_par;
%type <parameter> mais_par;
%type <parameter> parametros;

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

%%

programa : lalg_program var_identifier lalg_semicolon corpo lalg_period 
	{
		printTable(symbolTable);
	};

corpo : dc lalg_begin comandos lalg_end
	| error 
	{
		printf("corpo error\n");
		int syncArray[] = { lalg_period };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);

	};

dc : dc_c dc_v dc_p dc_f
	| error 
	{
		printf("dc error\n");
		int syncArray[] = { lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);

	};

dc_c : lalg_const var_identifier lalg_equal var_numero lalg_semicolon dc_c 
	{
		if(searchSymbol(symbolTable, $2, 1, scope) == NULL){
			insertSymbol(&symbolTable, $2, 1, $4, NULL, scope);
		}
		else {
			printf("Declaracao de '%s' ja realizada, linha %d\n", $2, yylineno - 1);
		}
	}
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
	{
		char* token = strtok($2, " ");
		while(token)
		{
			if(searchSymbol(symbolTable, token, 1, scope) == NULL){
				insertSymbol(&symbolTable,token, 1, $4, NULL, scope);
			}
			else {
				printf("Declaracao de '%s' ja realizada, linha %d\n", $2, yylineno - 1);
			}
			token = strtok(NULL, " ");
		}	
	}
	| %empty
	| error
	{ 
		printf("dc_v error\n");
		int syncArray[] = { lalg_procedure, lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};


tipo_var : lalg_real 
	{
		$$ = 1;
	}
	| lalg_integer
	{
		$$ = 0;
	}
	| error
	{ 
		printf("tipo_var error\n");
		int syncArray[] = { lalg_semicolon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};


variaveis : var_identifier mais_var
	{
		if($2 == NULL){
			$2 = (char*) calloc(sizeof(char),1);
		}

		$$ = (char*) malloc(sizeof(char) * (strlen($1) + strlen($2) + 2));
		strcpy($$, $1);
		strcat($$, " ");
		strcat($$, $2);
	}
	| error
	{ 
		printf("variaveis error\n");
		int syncArray[] = { lalg_colon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};


mais_var : lalg_comma variaveis 
	{
		$$ = $2;
	}
	| %empty 
	{
		$$ = NULL;
	}
	| error
	{ 
		printf("mais_var error\n");
		int syncArray[] = { lalg_colon, lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 2);
	};



dc_p : lalg_procedure var_identifier parametros  
	{
		// midrule

		if(searchSymbol(symbolTable, $2, 0, scope) == NULL)
		{
			// change the program scope
			scope = insertSymbol(&symbolTable, $2, 0, -1, $3, scope);
		}
		else 
		{
			printf("Procedimento ja declarado %s\n na linha %d", $2, yylineno);
		}
	}	lalg_semicolon corpo_p dc_p
	| %empty
	{
		// restore the original scope (there is no inner declaration for functions)
		scope = NULL;
	}
	| error
	{ 
		printf("procedure error\n");
		int syncArray[] = { lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};



dc_f : lalg_function var_identifier parametros lalg_colon tipo_var  
	{
		if(searchSymbol(symbolTable, $2, 0, scope) == NULL){
			// change the program scope
			scope = insertSymbol(&symbolTable, $2, 0, -1, $3, scope);
		}		
		else
		{
			printf("Procedimento ja declarado %s\n na linha %d", $2, yylineno);
		}
	} lalg_semicolon corpo_p dc_f
	| %empty
	{
		// restore the original scope (there is no inner declaration for functions)
		scope = NULL;
	}
	| error
	{ 
		printf("function error\n");
		int syncArray[] = { lalg_begin };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


parametros : lalg_leftp lista_par lalg_rightp 
	{
		$$ = $2;
	}
	| %empty
	{
		$$ = NULL;
	}
	| error
	{ 
		printf("parametros error\n");
		int syncArray[] = { lalg_semicolon };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


lista_par : variaveis lalg_colon tipo_var mais_par 
	{
		char* token = strtok($1, " ");	
		$$ = NULL;	
		while(token)
		{	
			if(searchParam($$, token) == NULL){
		
				insertParam(&$$, token, $3);	
			}
			else {
				printf("Declaracao de parametro '%s' ja realizada na funcao, linha %d\n", token, yylineno - 1);
			}
			token = strtok(NULL, " ");
		}	
		concatParamList(&$$, $4);
	}
	| error
	{ 
		printf("lista_par error\n");
		int syncArray[] = { lalg_rightp };
		yyclearin;
		yyerrok;
		panic(syncArray, 1);
	};


mais_par : lalg_semicolon lista_par 
	{
		$$ = $2;	
	}
	| %empty
	{
		$$ = NULL;
	}
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
	{

	}
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

var_numero : var_integer 
	{
		$$ = 0;
	}
	| var_real 
	{
		$$ = 1;	
	}
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
	fprintf(stderr, "Parser: %s at line %d, token \'%s\' not expected\n", s, yylineno, yylval.str);
}

int main(int argc, char **argv)
{
	int status;

	// Uncomment this flag to turn debug mode on for the parser
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

	tokenTest = yylex();

	// Keep skipping tokens until you find the syncronization token or the file ends
	while(verifyToken(array, size, tokenTest) < 0 && tokenTest != 0){
		printf("Token skipped: \'%s\' - code: %d\n", yylval.str, tokenTest);
		tokenTest = yylex();
	}

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
