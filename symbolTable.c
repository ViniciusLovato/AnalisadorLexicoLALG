#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Symbol table row
typedef struct str
{
	// type of the symbol
	// 0 function
	// 1 variable
	int type;

	char* identifier;

	// Scope of the symbol
	// NULL means global
	struct str* scope;

	// Next symbol
	struct str* next;

} str;

str* insertSymbol(str **table, int type, char *identifier, str* scope)
{
	// Inserting in the first position of the table
	str *tmp = *table;
	*table = (str*) malloc(sizeof(str));
	(*table)->next = tmp;

	(*table)->type = type;
	(*table)->identifier = (char*) malloc(sizeof(char)*strlen(identifier) + 1);
	strcpy((*table)->identifier, identifier);
	(*table)->scope = scope;

	return (*table);
}

// Search the table
str* searchSymbol(str *table, char *identifier, int type, str* scope)
{
	while(table != NULL)
	{
		if(!strcmp(table->identifier, identifier) 
				&& table->type == type 
				&& table->scope == scope)
		{
			return table;
		}
		table = table->next;
	}

	return NULL;
}

void removeSymbol(str** table, str* rem)
{
	str *tmp;

	if(*table != NULL && *table == rem)
	{
		(*table) = (*table)->next;
		free(rem->identifier);
		free(rem);
	}
	else
	{
		tmp = (*table);
		while(tmp != NULL)
		{
			if(tmp->next == rem)
			{
				tmp->next = rem->next;
				free(rem->identifier);
				free(rem);
			}
			tmp = tmp->next;
		}
	}
}

void printTable(str* table)
{
	for(; table != NULL; table = table->next)
	{
		printf("====== New Symbol =====\n");
		printf("ID: %s\n", table->identifier);
		printf("type: %d\n", table->type);
		printf("scope: %s\n", (table->scope != NULL)? table->scope->identifier : "Global");
	}
}

int main(void)
{
	str* symbolTable = NULL;
	str* scope = NULL;
	str* x = NULL;
	str* y = NULL;
	str* z = NULL;
	str* tmp = NULL;

	scope = insertSymbol(&symbolTable, 0, "main", scope);
	x = insertSymbol(&symbolTable, 1, "x", scope);
	y = insertSymbol(&symbolTable, 1, "y", scope);
	z = insertSymbol(&symbolTable, 1, "z", scope);

	if(tmp = searchSymbol(symbolTable, "k", 1, scope))
	{
		printf("====== Symbol =====\n");
		printf("ID: %s\n", tmp->identifier);
		printf("type: %d\n", tmp->type);
		printf("scope: %s\n", (tmp->scope != NULL)? tmp->scope->identifier : "Global");
		printf("====== Symbol =====\n");
	}
	else
		printf("====== Not Found =====\n");

	printTable(symbolTable);
	return EXIT_SUCCESS;
}
