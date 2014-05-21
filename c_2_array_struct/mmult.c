/* Program 2-8 mmult.c */
#include <stdio.h>
#include <stdlib.h>
#include "sparse_matrix.h"
#include "compare.h"

void storesum(term d[], int *totald, int row, int column, int *sum)
{
	if (*sum)
	{
		if (*totald < MAX_TERMS)
		{
			d[++*totald].row = row;
			d[*totald].col = column;
			d[*totald].value = *sum;
			*sum = 0;
		}
		else
		{
			fprintf(stderr, "Numbers of terms in product exceeds %d.\n", MAX_TERMS);
			exit(1);
		}
	}
}

void mmult(term a[], term b[], term d[])
{
	int rows_a = a[0].row, cols_a = a[0].col, totala = a[0].value;
	int rows_b = b[0].row, cols_b = b[0].col, totalb = b[0].value;
	int totald = 0;

	term trans_b[MAX_TERMS];
	int column;			/* now calc which column of b */
	int row = a[1].row;		/* now calc which row of a */
	int row_begin = 1;
	int sum = 0;
	int i, j;
	
	/* set boundary condition */
	a[totala + 1].row = rows_a;
	trans_b[totalb + 1].row = cols_b;
	trans_b[totalb + 1].col = 0;

	if (cols_a != rows_b) 
	{
		fprintf(stderr, "Incompatible matrices.\n");
		exit(1);
	}

	fast_transpose(b, trans_b);

	print_sm(trans_b);

	for (i = 1; i <= totala;) 
	{
		column = trans_b[1].row;
		for (j = 1; j <= totalb + 1;) 
		{
			/* multiply row of a by column of b */
			if (a[i].row != row)
			{
				/* when finish calc a row of a */
				storesum(d, &totald, row, column, &sum);
				i = row_begin;
				for (; trans_b[j].row == column; j++)
					;
				column = trans_b[j].row;
			}
			else if (trans_b[j].row != column)
			{
				/* when finish calc a col of b */
				storesum(d, &totald, row, column, &sum);
				i = row_begin;
				column = trans_b[j].row;
			}
			else
			{
				switch (COMPARE(a[i].col, trans_b[j].col))
				{
					case -1:
						i++;
						break;
					case 0:
						sum += (a[i++].value * trans_b[j++].value);
						break;
					case 1:
						j++;
						break;
				}
			}
		}
		for (; a[i].row; i++)
			;
		row_begin = i; row = a[i].row;
	} /* end of for i <= totala */

	d[0].row = rows_a;
	d[0].col = cols_b;
	d[0].value = totald;
}
