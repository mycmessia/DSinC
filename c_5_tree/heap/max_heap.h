/*
 * max heap is a max tree and also a complete tree
 * max tree is a tree whose nodes' children is no 
 * larger than the nodes
 */

#ifndef MAX_HEAP
#define MAX_HEAP

#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
	int key;
} element;

#endif
