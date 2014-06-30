#include <stdio.h>
#include <stdlib.h>
#include "x2.h"

x2_pointer front = NULL;
x2_pointer rear = NULL;

void add_front(int num)
{
	x2_pointer temp = (x2_pointer)malloc(sizeof(x2_node));
	if (IS_FULL(temp))
	{
		fprintf(stderr, "The memory is full.\n");
		exit(1);
	}

	temp->data = num;

	if (front)
	{
		temp->link = front;
		front = temp;
	}
	else
	{
		temp->link = NULL;
		front = temp;
		rear = temp;
	}
}

void add_rear(int num)
{
	x2_pointer temp = (x2_pointer)malloc(sizeof(x2_node));
	if (IS_FULL(temp))
	{
		fprintf(stderr, "The memory is full.\n");
		exit(1);
	}

	temp->data = num;

	if (rear)
	{
		rear->link = temp;
		rear = temp;
	}
	else
	{
		front = temp;
		rear = temp;
	}

	temp->link = NULL;
}

/* delete from the front of list */
int delete(void)
{
	if (IS_EMPTY(front))
	{
		fprintf(stderr, "can not delete empty list.\n");
		exit(1);
	}

	x2_pointer temp = front;
	int n = temp->data;
	front = temp->link;
	free(temp);

	return n;
}

void print_x2(x2_pointer ptr)
{
	printf("The x2 list contains: ");
	for (; ptr; ptr = ptr->link)
		printf("%4d", ptr->data);
	printf("\n");
}
