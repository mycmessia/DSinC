#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

typedef struct _element {
	int n;
} element;

typedef struct _node *node_pointer;
typedef struct _node {
	node_pointer rlink;
	element item;
	node_pointer rlink;
} node;

void dinsert(node_pointer node, node_pointer newnode);
void ddelete(node_pointer node, node_pointer deleted);

#endif
