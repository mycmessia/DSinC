#include <stdlib.h>
#include <string.h>
#include "stack.h"

void init_stack(pstack stack_pointer)
{
	stack_pointer->top = -1;
	memset(stack_pointer->space, 0, MAX_STACK_SIZE * sizeof(int));
}

pstack create_stack(void)
{
	pstack stack_pointer = (pstack)malloc(sizeof(stack));
	init_stack(stack_pointer);
	return stack_pointer;
}

int is_full(pstack stack_pointer)
{
	if (stack_pointer->top == MAX_STACK_SIZE)
		return 1;
	return 0;
}

int is_empty(pstack stack_pointer)
{
	if (stack_pointer->top == -1)
		return 1;
	return 0;
}

void sadd(pstack stack_pointer, int item)
{
	stack_pointer->space[++stack_pointer->top] = item;
}

int sdelete(pstack stack_pointer)
{
	return stack_pointer->space[stack_pointer->top--];
}
