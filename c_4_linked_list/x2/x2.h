#ifndef X2
#define X2

typedef struct _x2_node *x2_pointer;
typedef struct _x2_node {
	int data;
	x2_pointer link;
} x2_node;

#define IS_FULL(ptr) (!(ptr))
#define IS_EMPTY(ptr) (!(ptr))

void add_front(int n);
void print_x2(x2_pointer ptr);

#endif
