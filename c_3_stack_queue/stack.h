#ifndef STACK
#define STACK

#define MAX_STACK_SIZE 100
typedef struct {
	int key;
} element;
typedef element *pe;

int is_empty(void);
int is_full(void);
void add(pe pointer);
pe delete();
void pstack(void);

#endif
