#ifndef STACK
#define STACK

#include "threaded_tree.h"

#define MAX_STACK_SIZE 100

#define IS_FULL(p) (!(p))

threaded_pointer is_empty(void);
void is_full(void);

void add(threaded_pointer ptr);
threaded_pointer delete(void);

void print_stack(void);

#endif
