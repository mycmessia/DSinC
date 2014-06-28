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

void merge_list(list_pointer *ptr1, list_pointer *ptr2, list_pointer *ptr3)
{
	list_pointer pt3 = NULL, pt1 = *ptr1, pt2 = *ptr2;
	

	if (pt1->data > pt2->data)
	{
		*ptr3 = pt2;
		pt2 = pt2->link;
	}
	else
	{
		*ptr3 = pt1;
		pt1 = pt1->link;
	}

	pt3 = *ptr3;
	
	while (pt1 && pt2)
	{
		if (pt1->data > pt2->data)
		{
			pt3->link = pt2;
			pt2 = pt2->link;
		}
		else
		{
			pt3->link = pt1;
			pt1 = pt1->link;
		}

		pt3 = pt3->link;
	}

	if (pt1)
		pt3->link = pt1;
	else
		pt3->link = pt2;

	*ptr1 = NULL;
	*ptr2 = NULL;
}
