#ifndef GRAPH
#define GRAPH

#define MAX_VERTICES 50
typedef struct _node *node_pointer;
typedef struct _node {
	int vertex;
	node_pointer link;
} node;

node_pointer new_node(int vertex);

/* create a adjacency list from two-dimensional matrix */
void create_adj_list(void);

#endif
