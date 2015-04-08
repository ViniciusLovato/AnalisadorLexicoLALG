#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "scanner.h"

#define HASH_SIZE 40

extern int yylex(); 
extern int yylineno;
extern char *yytext;

typedef struct hash_n
{
	// Number of keywords with the same hash value
	int size;
	// Keywords
	char **keywords;
} hash_node;

hash_node table[HASH_SIZE];

int init_hash()
{
	int i, j;
	int hash_value;
	char keyword[20][20] = {"program", "begin", "end", "var", "real", "integer", "char", "procedure", "function", "return", "else", "read", "write", "while", "do", "if", "then", "for", "repeat", "until"};

	// Initializing hash
	for(i = 0; i < HASH_SIZE; i++)
	{
		table[i].size = 0;
		table[i].keywords = NULL;
	}

	// Filling out the hash
	for(i = 0; i < 20; i++)
	{
		// Calculating hash value (index)
		hash_value = hash(keyword[i]);

		// Verifying if there is no collision
		if(table[hash_value].size == 0)
		{
			// No collision
			table[hash_value].size = 1;
			// Allocating memory
			table[hash_value].keywords = (char**) malloc(sizeof(char*));
			table[hash_value].keywords[0] = (char*) malloc(sizeof(char)*strlen(keyword[i])+1);
			strcpy(table[hash_value].keywords[0], keyword[i]);
		}
		else
		{
			table[hash_value].size++;
			// Allocating memory
			table[hash_value].keywords = realloc(table[hash_value].keywords, sizeof(char*)*table[hash_value].size);
			table[hash_value].keywords[table[hash_value].size - 1] = (char*) malloc(sizeof(char)*strlen(keyword[i])+1);
			strcpy(table[hash_value].keywords[table[hash_value].size - 1], keyword[i]);
		}
	}

	return (0);
}

// Function to destroy the hash structure and free the memory
int destroy_hash()
{
	int i, j;
	for(i = 0; i < HASH_SIZE; i++)
	{
		for(j = 0; j < table[i].size; j++)
		{
			free(table[i].keywords[j]);
		}
		free(table[i].keywords);
	}
}

// Hash function
// Sum all the char values starting with 0 for 'a', mod 40
int hash(char *identifier)
{
	int value = 0;
	int j = strlen(identifier);
	for(--j; j >= 0; j--)
	{
		value += (identifier[j] - 97);
	}
	value %= 40;

	return(value);
}

// Function to check if the identifiers are keywords
int keywordCheck(char *keyword)
{
	int hash_value = hash(keyword);
	int j;

	// Checking if the hash_value is valid
	if(hash_value  > 0 && hash_value < HASH_SIZE)
	{
		for(j = 0; j < table[hash_value].size; j++)
		{
			// Verifying if the keyword is the same
			if(!strcmp(table[hash_value].keywords[j], keyword))
			{
				return(1);
			}
		}
	}
	// Identifier is not a keyword
	return (0);
}

int main(void){

	int ntoken, vtoken;

	// Initializing hash
	init_hash();

	ntoken = yylex();
	while(ntoken){
		if(ntoken == IDENTIFIER){
			if(keywordCheck(yytext))
				printf("Keyword: %s\n", yytext);
			else
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
		else if(ntoken == ERROR){
			printf("Error: %s\n", yytext);
		} 
		ntoken = yylex();
	}
	destroy_hash();
	return (0);
}
