#ifndef STACK
#define STACK

#define MAX_STACK_SIZE 100
typedef struct {
	int key;
} element;

element is_empty(void);
void is_full(void);

void add(element item);
element delete();

void print_stack(void);

#endif
