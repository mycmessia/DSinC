#include <stdio.h>
#include "stack.h"

int stack[MAX_STACK_SIZE];
int top = -1;

int is_empty(void)
{
	fprintf(stderr, "stack is empty, delete failed.\n");
	return 1;
}

void is_full(void)
{
	fprintf(stderr, "stack is full, add failed.\n");
	return;
}

void add(int item)
{
	if (top == MAX_STACK_SIZE - 1)
	{
		return is_full();
	}

	stack[++top] = item;
}

int delete(void)
{
	if (top < 0)
	{
		return is_empty();
	}
	
	return stack[top--];
}

int get_top(void)
{
	return stack[top];
}

void print_stack(void)
{
	int i = 0;

	for (i = 0; i <= top; i++)
	{
		printf("stack[%d].key = %d\n", i, stack[i]);
	}
}
