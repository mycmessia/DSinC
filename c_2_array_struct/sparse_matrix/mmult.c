/* 
 * Program 2-8 mmult.c written by myc
 *
 * Through writting this program, I know that if you want to understand a algorithm completely,
 * the only way is rewriting it by yourself after you know the basic thought of the algorithm,
 * when you are rewriting it you may meet many problems and you may write it wrong at first,
 * So, what I want to say is process is important and result not.
 */
#include <stdio.h>
#include <stdlib.h>
#include "sparse_matrix.h"
#include "../../c_1_basic_concept/compare.h"

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

void fast_mmult(term a[], term b[], term d[])
{
	if (a[0].col != b[0].row)
	{
		printf("Invaild two matrixs.\n");
		exit(1);
	}

	term trans_b[MAX_TERMS];
	int i = -1, j = -1;
	int totala = a[0].value, totalb = b[0].value, totald = 0;
	int row = -1, col = -1;
	int row_begin = -1;
	int sum = 0;

	fast_transpose(b, trans_b);

	trans_b[totalb + 1].row = trans_b[0].row;

	for (i = 1; i <= totala;)
	{
		row_begin = i;
		row = a[row_begin].row;
		col = trans_b[1].row;
		for (j = 1; j <= totalb;)
		{
			if (trans_b[j].row != col)
			{
				storesum(d, &totald, row, col, &sum);
				if (j == totalb + 1)
					break;
				else
				{
					col = trans_b[j].row;
					i = row_begin;
				}
			}
			else if (a[i].row != row)
			{
				storesum(d, &totald, row, col, &sum);
				for (; trans_b[j].row == col; j++)
					;
				if (j == totalb + 1)
					break;
				else
				{
					col = trans_b[j].row;
					i = row_begin;
				}
			}
			else
			{
				switch (COMPARE(a[i].col, trans_b[j].col))
				{
					case -1:
						i++;
						break;
					case 0:
						sum += (a[i].value * trans_b[j].value);
						i++, j++;
						break;
					case 1:
						j++;
						break;
			
				}
			}
		}
	}

	storesum(d, &totald, row, col, &sum);

	d[0].value = totald;
	d[0].col = b[0].col;
	d[0].row = a[0].row;
}
