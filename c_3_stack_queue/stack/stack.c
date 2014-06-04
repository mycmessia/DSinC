#include <stdio.h>
#include "stack.h"
pe stack[MAX_STACK_SIZE];
int top = -1;

int is_empty(void)
{
	return (top < 0 ? 1 : 0);
}

int is_full(void)
{
	return (top == MAX_STACK_SIZE - 1 ? 1 : 0);
}

void add(pe pointer)
{
	if (is_full())
	{
		fprintf(stderr, "stack is full, add failed.\n");
		return;
	}

	stack[++top] = pointer;
}

pe delete(void)
{
	if (is_empty())
	{
		fprintf(stderr, "stack is empty, delete failed.\n");
		return;
	}
	
	return stack[top--];
}

void print_stack(void)
{
	int i = 0;

	for (i = 0; i <= top; i++)
	{
		printf("stack[%d].key = %d\n", i, stack[i]->key);
	}
}
