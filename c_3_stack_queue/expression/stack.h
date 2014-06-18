#ifndef STACK
#define STACK

#define MAX_STACK_SIZE 20

typedef struct {
	int key;
} element;

typedef struct {
	element space[MAX_STACK_SIZE];
	int top;
} stack, *pstack;

void init_stack(pstack stack_pointer);
pstack create_stack(void);
int is_full(pstack stack_pointer);
int is_empty(pstack stack_pointer);

#endif
