#include <stdio.h>
#include <stdlib.h>
#include "dlinked_queue.h"
#include "graph.h"

node_pointer graph[MAX_VERTICES];
short int visited[MAX_VERTICES];
int n = 0;

/* two-dimensional matrix for create adjacency list */

int matrix1[4][3] = {
	{1, 2, 3}, {0, 2, 3}, {0, 1, 3}, {0, 1, 2}
};;

int matrix2[8][2] = {
	{1, 2}, {0, 3}, {0, 3}, {1, 2}, 
	{5, -1}, {4, 6}, {5, 7}, {6, -1}
};

int matrix3[8][4] = {
	{1, 2, -1}, {0, 3, 4, -1}, {0, 5, 6, -1}, {1, 7, -1},
	{1, 7, -1}, {2, 7, -1}, {2, 7, -1}, {3, 4, 5, 6}
};

node_pointer new_node(int vertex)
{
	node_pointer ptr = (node_pointer)malloc(sizeof(node));
	ptr->vertex = vertex;
	ptr->link = NULL;
	return ptr;
}

void create_adj_list(int matrix[][SEC_DIM_SIZE])
{
	int i, j;
	node_pointer temp;

	for(i = 0; i < FIR_DIM_SIZE; i++)
	{
		graph[i] = new_node(i);
		temp = graph[i];
		for (j = 0; j < SEC_DIM_SIZE; j++)
		{
			if (matrix[i][j] == -1)	break;
			temp->link = new_node(matrix[i][j]);
			temp = temp->link;
		}
	}
}

/* TODO checkout whether the function works right */
void read_adj_list(node_pointer adj_list[MAX_VERTICES])
{
	int vertices, edge_v1, edge_v2;
	int i;
	char ans;

	printf("please input number of vertices of adj_list:\n");
	scanf("%d", &vertices);
	
	for (i = 0; i < vertices; i++)
	{
		adj_list[i] = new_node(i);
	}

	do {
		printf("Please input two vertices of the edge divided by a space\n");
		scanf("%d %d", &edge_v1, &edge_v2);
		
		adj_list[edge_v1]->link = new_node(edge_v2);
		adj_list[edge_v1] = adj_list[edge_v1]->link;
		
		adj_list[edge_v2]->link = new_node(edge_v1);
		adj_list[edge_v2] = adj_list[edge_v2]->link;

		printf("Do you want to input another edge?\n");
		scanf(" %c", &ans);

	} while (ans == 'y');
}

void dfs(int v)
{
	node_pointer w;
	visited[v] = TRUE;
	printf("%5d", v);
	for (w = graph[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs(w->vertex);
	if (v == FIR_DIM_SIZE - 1) printf("\n");
}

void bfs(int v)
{
	node_pointer w;
	queue_pointer front, rear;
	front = rear = NULL;
	
	visited[v] = TRUE;
	printf("%5d", v);

	addq(&front, &rear, v);	
	while (front)
	{
		v = deleteq(&front);
		for (w = graph[v]; w; w = w->link)
		{
			if (!visited[w->vertex])
			{
				printf("%5d", w->vertex);
				addq(&front, &rear, w->vertex);
				visited[w->vertex] = TRUE;
			}
		}
	}
	printf("\n");
}
