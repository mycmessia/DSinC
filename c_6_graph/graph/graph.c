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
void create_adj_list(int matrix[][3])
{
	int i, j;
	node_pointer temp;

	for(i = 0; i < 4; i++)
	{
		graph[i] = new_node(i);
		temp = graph[i];
		for (j = 0; j < 3; j++)
		{
			temp->link = new_node(matrix[i][j]);
			temp = temp->link;
		}
	}
}

node_pointer read_adj_list(void)
{
	node_pointer adj_list[MAX_VERTICES];
	int vertices, edge_v_1, edge_v_2;
	int i;
	char ans;

	printf("please input number of vertices of adj_list:\n");
	scanf("%d", vertices);
	
	for (i = 0; i < verticess; i++)
	{
		adj_list[i] = new_node(i);
	}

	do {
		
	} while (ans == 'y')
}
