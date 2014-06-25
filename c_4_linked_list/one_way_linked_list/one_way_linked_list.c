#include <stdio.h>
#include <stdlib.h>
#include "one_way_linked_list.h"

void insert(list_pointer *ptr, int data)
{
	list_pointer tmp;
	tmp = (list_pointer)malloc(sizeof(list_node));
	if (IS_MEMORY_FULL(tmp))
	{
		fprintf(stderr, "The memory is full.\n");
		return;
	}

	tmp->data = data;

	if (*ptr)
		tmp->link = *ptr;
	else
		tmp->link = NULL;
	
	*ptr = tmp;
}

void delete(list_pointer *ptr, list_pointer pre)
{
	list_pointer next = pre->link;

	if (pre)
		pre->link = next->link;
	else
		*ptr = (*ptr)->link;

	free(next);
}

void print_list(list_pointer ptr)
{
	printf("The list contains: ");
	for (; ptr; ptr = ptr->link)
		printf("%4d", ptr->data);
	printf("\n");
}

list_pointer search(list_pointer ptr, int num)
{
	for (; ptr; ptr = ptr->link)
	{
		if (ptr->data == num)
			return ptr;
	}
	return NULL;
}

int length(list_pointer ptr)
{
	int len = 0;
	for (; ptr; ptr = ptr->link, len++)
		;
	return len;
}

/* delete the 1, 3, 5... node of ptr */
void interval_delete(list_pointer *ptr)
{
	int counter = 0;
	list_pointer plast = NULL;
	list_pointer ptmp = *ptr;

	if (!ptmp)
	{
		fprintf(stderr, "list can not be null.\n");
		return;
	}

	if (!ptmp->link)
	{
		fprintf(stderr, "one node list can not delte.\n");
		return;
	}

	*ptr = (*ptr)->link;		

	plast = ptmp;
	ptmp = ptmp->link;
	
	while (ptmp && plast)
	{		
		if (!(counter++ % 2))
			free(plast);
		else
			plast->link = ptmp->link;
		
		plast = ptmp;
		ptmp = ptmp->link;
	}
}
