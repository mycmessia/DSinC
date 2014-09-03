#include <stdlib.h>
#include "graph.h"

node_pointer graph[MAX_VERTICES];
int n = 0;

/* two-dimensional matrix for create adjacency list */
int matrix1[4][3] = {
	{1, 2, 3}, {0, 2, 3}, {0, 1, 3}, {0, 1, 2}
};;

int matrix2[8][2] = {
	{1, 2}, {0, 3}, {0, 3}, {1, 2}, 
	{5, -1}, {4, 6}, {5, 7}, {6, -1}
};

node_pointer new_node(int vertex)
{
	node_pointer ptr = (node_pointer)malloc(sizeof(node));
	ptr->vertex = vertex;
	ptr->link = NULL;
	return ptr;
}

/* TODO pass a two-dimensional array pointer as parameter */
void create_adj_list(void)
{
	int i, j;
	node_pointer temp;

	for(i = 0; i < 4; i++)
	{
		graph[i] = new_node(i);
		temp = graph[i];
		for (j = 0; j < 3; j++)
		{
			temp->link = new_node(matrix1[i][j]);
			temp = temp->link;
		}
	}
}
