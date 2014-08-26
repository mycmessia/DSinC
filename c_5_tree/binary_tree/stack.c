#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

tree_pointer stack[MAX_STACK_SIZE];
int top = -1;

tree_pointer is_empty(void)
{
	fprintf(stderr, "stack is empty, delete failed.\n");
	return NULL;
}

void is_full(void)
{
	fprintf(stderr, "stack is full, add failed.\n");
	return;
}

void add(tree_pointer item)
{
	if (top == MAX_STACK_SIZE - 1)
	{
		return is_full();
	}
	
	item->is_added = 1;
	stack[++top] = item;
}

tree_pointer delete(void)
{
	if (top < 0)
	{
		return is_empty();
	}
	
	return stack[top--];
}

void print_stack(void)
{
	int i = 0;

	for (i = 0; i <= top; i++)
	{
		printf("stack[%d]->data = %d\n", i, stack[i]->data);
	}
}
