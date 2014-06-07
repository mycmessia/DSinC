#ifndef STACK
#define STACK

#define MAX_STACK_SIZE 100

typedef struct {
	int row;
	int col;
	int dir;
} element;

element is_empty(void);
void is_full(void);

void add(element item);
element delete();

#endif
