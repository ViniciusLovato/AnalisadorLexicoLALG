#include <stdio.h>

#include "scanner.h"

extern int yylex(); 
extern int yylineno;
extern char *yytext;

int hash(char *identifier)
{
	printf("Identifier: %s\n", yytext);
	return(0);
}

int main(void){

	int ntoken, vtoken;

	ntoken = yylex();
	while(ntoken){
		if(ntoken == IDENTIFIER){
			hash(yytext);
		}
		else if(ntoken == INTEGER){
			printf("Inteiro: %s\n", yytext);
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
		else if(ntoken == ERROR){
			printf("Error: %s\n", yytext);
		} 
		ntoken = yylex();
	}
}
