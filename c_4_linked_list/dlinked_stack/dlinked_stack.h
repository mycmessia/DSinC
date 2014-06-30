#ifndef DLINKED_STACK
#define DLINKED_STACK

#define MAX_STACKS 10

typedef struct {
	int key;
} element;

typedef struct _stack *stack_pointer;
typedef struct _stack {
	element item;
	stack_pointer link;
} stack;

#define IS_EMPTY(pointer) (!(pointer))
#define IS_FULL(pointer) (!(pointer))

void add(stack_pointer *top, element item);
element delete(stack_pointer *top);

int is_palin(char *str, int len, stack_pointer *top);
int is_in_pair(char *exp, int len, stack_pointer *top);

#endif
