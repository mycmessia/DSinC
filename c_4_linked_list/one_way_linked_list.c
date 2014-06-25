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
