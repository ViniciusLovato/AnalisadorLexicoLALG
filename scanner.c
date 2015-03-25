#include <stdio.h>
#include <string.h>


#include "scanner.h"

extern int yylex(); 
extern int yylineno;
extern char *yytext;

int hash(char *identifier)
{
	printf("Keyword: %s\n", yytext);
	return(0);
}

int main(void){

	int ntoken, vtoken;

	ntoken = yylex();
	while(ntoken){
		if(ntoken == IDENTIFIER){
			printf("Identifier: %s\n", yytext);
		}
		else if(ntoken == INTEGER){
			printf("Integer: %s\n", yytext);
		}
		else if(ntoken == REAL){ 
			printf("Real: %s\n", yytext);
		}
 		else if(ntoken == CHAR){ 
			printf("Char: %s\n", yytext);
		}
		else if(ntoken == STRING){
			printf("String: %s\n", yytext);
		} 
		else if(ntoken == ADD){
			printf("Add: %s\n", yytext);
		} 
		else if(ntoken == SUB){
			printf("Sub: %s\n", yytext);
		}
		else if(ntoken == MUL){
			printf("Mul: %s\n", yytext);
		}
		else if(ntoken == DIV){
			printf("Div: %s\n", yytext);
		}
		else if(ntoken == EQUAL){
			printf("Equal: %s\n", yytext);
		}
		else if(ntoken == N_EQUAL){
			printf("Not Equal: %s\n", yytext);
		}
		else if(ntoken == G_THAN){
			printf("Greater than: %s\n", yytext);
		} 
		else if(ntoken == L_THAN){
			printf("Less than: %s\n", yytext);
		} 
		else if(ntoken == GE_THAN){
			printf("Greater or Equal than: %s\n", yytext);
		} 
		else if(ntoken == LE_THAN){
			printf("Less or Equal than: %s\n", yytext);
		} 
		else if(ntoken == LEFT_P){
			printf("Left Parenthesis: %s\n", yytext);
		} 
		else if(ntoken == RIGHT_P){
			printf("Right Parenthesis: %s\n", yytext);
		}   
		else if(ntoken == COLON){
			printf("Colon: %s\n", yytext);
		} 
		else if(ntoken == SEMICOLON){
			printf("Semicolon: %s\n", yytext);
		} 
		else if(ntoken == COMMA){
			printf("Comma: %s\n", yytext);
		} 
		else if(ntoken == PERIOD){
			printf("Period: %s\n", yytext);
		}
		else if(ntoken == ASSIGNMENT){
			printf("Assignment: %s\n", yytext);
		}
		else if(ntoken == KEYWORD){
			hash(yytext);
		}
		else if(ntoken == ERROR){
			printf("Error: %s\n", yytext);
		} 
		ntoken = yylex();
	}
}
