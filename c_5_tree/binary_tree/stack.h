#ifndef STACK
#define STACK

#define MAX_STACK_SIZE 100

#include "binary_tree.h"

#define IS_FULL(p) (!p)

tree_pointer is_empty(void);
void is_full(void);

void add(tree_pointer item);
tree_pointer delete();

void print_stack(void);

#endif
