#include "param.h"

param* insertParam(param **list, char *identifier, int type)
{
	// Inserting in the first position of the list
	param *tmp = *list;
	*list = (param*) malloc(sizeof(param));
	(*list)->next = tmp;

	(*list)->type = type;
	(*list)->identifier = (char*) malloc(sizeof(char)*strlen(identifier) + 1);
	strcpy((*list)->identifier, identifier);

	return (*list);
}

// Search the table
param* searchParam(param *list, char *identifier, int type)
{
	while(list != NULL)
	{
		if(!strcmp(list->identifier, identifier))
		{
			return list;
		}
		list = list->next;
	}

	return NULL;
}

// Search the table
// This function returns:
// 0 if everything is okay
// 1 if the arguments doesn't match
// 2 if the number of arguments doesn't match
int compareList(param* list1, param* list2)
{
	while(list1 != NULL && list2 != NULL)
	{
		if(list1->type != list2->type)
		{
			return 1;
		}

		list1 = list1->next;
		list2 = list2->next;
	}

	// Checking if one of the lists is not empty
	if(list1 != NULL)
	{
		return 2;
	}
	else if(list2 != NULL)
	{
		return 2;
	}

	return 0;
}

void removeParam(param** list, param* rem)
{
	param* tmp;

	if(*list != NULL && *list == rem)
	{
		(*list) = (*list)->next;
		free(rem->identifier);
		free(rem);
	}
	else
	{
		tmp = (*list);
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

void printParam(param* list)
{
	for(; list != NULL; list = list->next)
	{
		printf("====== New Param =====\n");
		printf("ID: %s\n", list->identifier);
		printf("type: %d\n", list->type);
	}
}
/*
int main(void)
{
	int x;
	param *list1 = NULL;
	param *list2 = NULL;
	param *x1 = NULL;
	param *y1 = NULL;
	param *z1 = NULL;
	param *x2 = NULL;
	param *y2 = NULL;
	param *z2 = NULL;

	x1 = insertParam(&list1, "x", 1);
	y1 = insertParam(&list1, "y", 2);
	z1 = insertParam(&list1, "z", 1);
	//removeParam(&list1, z1);

	x2 = insertParam(&list2, "x", 1);
	y2 = insertParam(&list2, "y", 1);
	z2 = insertParam(&list2, "z", 1);

	printf("RESULT: %d\n", compareList(list1, list2));

	printParam(list1);
	printParam(list2);

	return EXIT_SUCCESS;
}*/
