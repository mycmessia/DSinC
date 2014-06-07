#include <stdio.h>
#include "maze.h"
#include "stack.h"

offsets move[MAX_DIR] = {
	{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
	{1, 0}, {1, -1}, {0, -1}, {-1, -1}
};

int maze[ROW][COL] = {
	{0, 0, 1, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 0, 1, 0, 1},
	{0, 0, 1, 1, 1},
	{0, 1, 0, 0, 0}
};

extern int top;
extern element stack[MAX_STACK_SIZE];

void dfs(void)
{
	element pos;
	int found = 0;
	int row = -1, col = -1, dir = -1;
	int next_row = -1, next_col = -1;
	int i;

	maze[0][0] = 2;
	element start = {0, 0, 0};
	add(start);

	while (top > -1 && !found)
	{
		pos = delete();
		row = pos.row;
		col = pos.col;
		dir = pos.dir;
		
		while (dir < MAX_DIR && !found)
		{
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;

			if (next_row == ROW && next_col == COL)
				found = 1;
			else if (next_row > -1 && next_row < ROW &&
				 next_col > -1 && next_col < COL &&
				 maze[next_row][next_col] == 0)
			{
				/*
				 * add the old pos but change a dir
				 * for the reason that when we must
				 * go back we won't go the same way
				 */
				maze[next_row][next_col] = 2;
				pos.row = row;
				pos.col = col;
				pos.dir = ++dir;
				add(pos);
				row = next_row; col = next_col; dir = 0;
			}
			else
				dir++;
		}
	}

	if (found)
	{
		printf("The path is:\n");
		printf("row\tcol\n");
		for (i = 0; i <= top; i++)
			printf("%d\t%d\n", stack[i].row, stack[i].col);
		printf("%d\t%d\n", ROW - 1, COL - 1);
	}
	else
		printf("The maze does not have a path.\n");
}
