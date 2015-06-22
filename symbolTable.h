#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "param.h"

// Symbol table row
typedef struct str
{
	// type of the symbol
	// 0 function
	// 1 variable
	int type;
	int type_var;
	param* parameters;
	char* identifier;

	// Scope of the symbol
	// NULL means global
	struct str* scope;

	// Next symbol
	struct str* next;

} str;


str* insertSymbol(str **table,char*identifier, int type, int type_var, param* parameters, str* scope);
str* searchSymbol(str *table, char *identifier, int type, str* scope);
void removeSymbol(str** table, str* rem);
void printTable(str* table);
