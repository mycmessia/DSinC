#ifndef GRAPH
#define GRAPH

#define MAX_VERTICES 50
typedef struct _node *node_pointer;
typedef struct _node {
	int vertex;
	node_pointer link;
} node;

#define FIR_DIM_SIZE 8
#define SEC_DIM_SIZE 4

node_pointer new_node(int vertex);

/* create a adjacency list from two-dimensional matrix */
void create_adj_list(int matrix[][SEC_DIM_SIZE]);

void read_adj_list(node_pointer adj_list[MAX_VERTICES]);

#define TRUE 1
#define FALSE 0

/* deep first search of a graph beginning with vertex v */
void dfs(int v);

/* breadth first search of a graph starting with node v */
void bfs(int v);

#endif
