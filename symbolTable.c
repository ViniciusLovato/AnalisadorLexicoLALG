#include "symbolTable.h"

str* insertSymbol(str **table,char*identifier, int type, int type_var, param* parameters, str* scope)
{
	// Inserting in the first position of the table
	str *tmp = *table;
	*table = (str*) malloc(sizeof(str));
	(*table)->next = tmp;
	(*table)->type_var = type_var;
	(*table)->parameters = parameters;

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

// Search the scope
str* searchScope(str *table, char *identifier, int type, str *scope)
{
	str *tmp;
	int isNotNull;

	do
	{
		tmp = table;
		while(tmp != NULL)
		{
			if((!strcmp(tmp->identifier, identifier)) && tmp->type == type && tmp->scope == scope)
			{
				return tmp;
			}
			tmp = tmp->next;
		}
		if(scope != NULL)
		{
			scope = scope->scope;
			isNotNull = 1;
		}
		else
		{
			isNotNull = 0;
		}
	}
	while (isNotNull);

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
		printf("type: %s\n", (table->type == 0)? "Function" : "Variable");
		printf("ID: %s\n", table->identifier);
		printf("scope: %s\n", (table->scope != NULL)? table->scope->identifier : "Global");
		
		if(table->type == 0)
		{
			printf("\t===== Parameters =====\n");
			printParam(table->parameters);
		}
		else
		{
			if(table->type_var == 0)	
				printf("Type: Inteiro\n");
			else if(table->type_var == 1)	
				printf("Type: Real\n");
			else
				printf("Type: Char\n");

		}	
			

	}
}
/*
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
}*/
