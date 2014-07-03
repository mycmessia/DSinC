#include <stdio.h>
#include <stdlib.h>
#include "sparse_matrix.h"

matrix_pointer hdnode[MAX_SIZE];

/**
 * read in a matrix and set up its linked representation,
 * an auxiliary global array hdnode is used.
 */
matrix_pointer mread(void)
{
	int num_rows, num_cols, num_terms, num_heads, i;
	int row, col, value, current_row;
	matrix_pointer temp, last, node;

	printf("Enter the number of rows, cols, and number"
		"of nonzero terms:\n");
	scanf("%d%d%d", &num_rows, &num_cols, &num_terms);
	num_heads = (num_cols > num_rows) ? num_cols : num_rows;
	node = new_node(); 
	node->tag = entry;
	node->u.entry.row = num_rows;
	node->u.entry.col = num_cols;

	if (!num_heads)
		node->right = node;
	else
	{
		/* init the head nodes */
		for (i = 0; i < num_heads; i++)
		{
			temp = new_node();
			hdnode[i] = temp; 
			hdnode[i]->tag = head;
			hdnode[i]->right = hdnode[i];
			hdnode[i]->u.next = hdnode[i];
		}
		current_row = 0;
		last = hdnode[0]; /* last node in current row */
		for (i = 0; i < num_terms; i++)
		{
			printf("Enter row, col, and value:\n");
			scanf("%d%d%d", &row, &col, &value);
			/* 
			 * use last to shadow the last node in one row,
			 * use the hdnode[col].u.next to shadow the last
			 * node in one col.
			 */
			if (row > current_row) /* close current row */
			{
				last->right = hdnode[current_row];
				current_row = row;
				last = hdnode[row];
			}
			temp = new_node();
			temp->tag = entry; 
			temp->u.entry.row = row;
			temp->u.entry.col = col;
			temp->u.entry.value = value;
			last->right = temp; /* link into row list */
			last = temp;
			hdnode[col]->u.next->down = temp;
			hdnode[col]->u.next = temp;
		}
		/* close last row */
		last->right = hdnode[current_row];
		/* close all col lists */
		for (i = 0; i < num_cols; i++)
			hdnode[i]->u.next->down = hdnode[i];
		/* link all head nodes together */
		for (i = 0; i < num_heads - 1; i++)
			hdnode[i]->u.next = hdnode[i + 1];
		hdnode[num_heads - 1]->u.next = node;
		node->right = hdnode[0];
	}
	
	return node;
}

matrix_pointer new_node(void)
{
	matrix_pointer temp;
	temp = (matrix_pointer)malloc(sizeof(matrix_node));
	if (IS_FULL(temp))
	{
		fprintf(stderr, "The memory is full.\n");
		exit(1);
	}

	return temp;
}

void mwrite(matrix_pointer node)
{
	int i;
	matrix_pointer temp, head = node->right;
	
	printf("\nnum_rows = %d, num_cols = %d\n",
		node->u.entry.row, node->u.entry.col);
	printf("The matrix by row, col, value:\n");
	for (i = 0; i < node->u.entry.row; i++)
	{
		for (temp = head->right; temp != head; temp = temp->right)
			printf("%4d%4d%4d \n", temp->u.entry.row,
				temp->u.entry.col, temp->u.entry.value);
		head = head->u.next;
	}
}

void merase(matrix_pointer *node)
{
	matrix_pointer x, y, head = (*node)->right;
	int i, num_heads;

	/* free the entry and head nodes by row */
	for (i = 0; i < (*node)->u.entry.row; i++)
	{
		y = head->right;
		while (y != head)
		{
			x = y; y = y->right; free(x);
		}
		x = head; head = head->u.next; free(x);
	}
	
	/* free remaining head nodes(when cols is more the rows) */
	y = head;
	while (y 1= *node)
	{
		x = y; y = y->u.next; free(x);
	}
	free(*node); *node = NULL;
}
