#include <stdio.h>
#include <string.h>
#include "graph.h"

extern int matrix1[][3], matrix2[][2], matrix3[][4];
extern node_pointer graph[MAX_VERTICES];
extern int visited[MAX_VERTICES];

int main(void)
{
	create_adj_list(matrix3);
	//read_adj_list(graph);
	
	printf("bfs of adj_list in page 172: ");
	bfs(0);

	memset(visited, 0, MAX_VERTICES);

	printf("dfs of adj_list in page 172: ");
	dfs(0);

	return 0;
}
