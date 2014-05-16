#include "sparse_matrix.h"
#define MAX_COL 50

void transpose(term a[], term b[])
{
	int i, j;
	int sum_term = a[0].value;
	int sum_col = a[0].col;
	int count = 0;			/* count number of b*/

	/* algorithm in book check if a is a zero matrix here */

	for (j = 0; j < sum_col; j++)
	{
		for (i = 1; i <= sum_term; i++)
		{
			if (a[i].col == j)
			{
				b[count + 1].row = j;
				b[count + 1].col = a[i].row;
				b[count + 1].value = a[i].value;
				count++;
			}
		}
	}

	b[0].value = count;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
}

void fast_transpose(term a[], term b[])
{
	int i;
	int row_nums[MAX_COL] = {0}, start_pos[MAX_COL] = {0};
	
	/* prepare */
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	for (i = 1; i <= a[0].value; i++) 
	{
		row_nums[a[i].col]++;
	}

	start_pos[0] = 1;	/* b[0].is used for basic info */
	for (i = 1; i < a[0].col; i++)
	{
		/* This is a hole */
		start_pos[i] = start_pos[i - 1] + row_nums[i - 1]; 
	}

	for (i = 1; i <= a[0].value; i++)
	{
		b[start_pos[a[i].col]].row = a[i].col;
		b[start_pos[a[i].col]].col = a[i].row;
		b[start_pos[a[i].col]++].value = a[i].value;
	}
}
