#ifndef _PARAM_C_
#define _PARAM_C_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct param
{
	char* identifier;
	// type of the variable
	// 0 integer
	// 1 real
	// 2 char
	int type;

	struct param *next;
} param;


param* insertParam(param **list, char *identifier, int type);
param* searchParam(param *list, char *identifier);
int compareList(param* list1, param* list2);
void removeParam(param** list, param* rem);
void printParam(param* list);
#endif
