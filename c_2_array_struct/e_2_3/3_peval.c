#include <stdio.h>
#include "poly_operate.h"

extern polynomial terms[MAX_TERMS];
extern int avail;	/* the next availiable unit of terms's index */

/* Horner rule */
int peval(int start, int finish, int x)
{
	int sum = 0;
	int expon_t = 0;
	int coef_t = 0;
	int i = start;

	/* find the max expon of the poly which determine loop count */
	for (i = start; i <= finish; i++)
	{
		if (terms[i].expon > expon_t)
		{
			expon_t = terms[i].expon;
			coef_t = terms[i].coef;
		}
	}

	while (expon_t)
	{
		expon_t--;

		sum += coef_t;
		sum *= x;

		coef_t = 0;
		for (i = start; i <= finish; i++)
		{
			if (terms[i].expon == expon_t)
				coef_t = terms[i].coef;
		}
	}
	
	return sum;
}

int main(void)
{
	poly_pos pos = read_poly();

	print_poly(pos.start, pos.finish);

	int sum = peval(pos.start, pos.finish, 3);

	printf("The sum is %d\n", sum);

	return 0;
}
