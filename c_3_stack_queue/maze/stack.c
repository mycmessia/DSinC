#include <stdio.h>
#include "stack.h"

element stack[MAX_STACK_SIZE];
int top = -1;

element is_empty(void)
{
	fprintf(stderr, "stack is empty, delete failed.\n");
	element err_empty = {-1, -1, -1};
	return err_empty;
}

void is_full(void)
{
	fprintf(stderr, "stack is full, add failed.\n");
	return;
}

void add(element item)
{
	if (top == MAX_STACK_SIZE - 1)
	{
		return is_full();
	}

	stack[++top] = item;
}

element delete(void)
{
	if (top < 0)
	{
		return is_empty();
	}
	
	return stack[top--];
}
