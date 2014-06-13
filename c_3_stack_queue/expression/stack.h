#ifndef STACK
#define STACK

#define MAX_STACK_SIZE 100

int is_empty(void);
void is_full(void);

void add(int item);
int delete(void);
int get_top(void);
void print_stack(void);

#endif
