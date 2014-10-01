#include <stdio.h>
#include "threaded_tree.h"
#include "stack.h"

threaded_pointer stack[MAX_STACK_SIZE];
int top = -1;

threaded_pointer is_empty(void)
{
	fprintf(stderr, "stack is empty, delete failed.\n");
	threaded_pointer err_empty = NULL;
	return err_empty;
}

void is_full(void)
{
	fprintf(stderr, "stack is full, add failed.\n");
	return;
}

void add(threaded_pointer ptr)
{
	if (top == MAX_STACK_SIZE - 1)
	{
		return is_full();
	}

	stack[++top] = ptr;
}

threaded_pointer delete(void)
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
