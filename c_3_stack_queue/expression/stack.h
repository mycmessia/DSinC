#ifndef STACK
#define STACK

#define MAX_STACK_SIZE

typedef struct {
	int key;
} item;

typedef struct {
	item space[MAX_STACK_SIZE];
	int top;
} stack;

typedef *stack pstack;

void init_stack(pstack pointer)
{
	pointer->top = 0;
	memset(pointer->space, 0, MAX_STACK_SIZE * sizeof(item));
}

void create_stack(pstack pointer)
{
	
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

#endif
