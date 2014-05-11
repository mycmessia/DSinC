#include <stdlib.h>
#include <stdio.h>
#include "poly_operate.h"
#include "compare.h"

polynomial terms[MAX_TERMS];
int avail = 0;	/* the next availiable unit of terms's index */

void attach(float coefficient, int exponent)	/* add a new term to the array terms */
{
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(1);
	}

	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

void padd(int starta, int finisha, int startb, int finishb,
				   int *startd, int *finishd)
{
	float coefficient;
	*startd = avail;
	
	while (starta <= finisha && startb <= finishb)
	{
		switch (COMPARE(terms[starta].expon,
				terms[startb].expon))
		{
			case -1:
				attach(terms[startb].coef, terms[startb].expon);
				startb++;;
				break;
			case 0:
				coefficient = terms[starta].coef +
					      terms[startb].coef;
				if (coefficient)
					attach(coefficient, terms[starta].expon);
				starta++;
				startb++;
				break;
			case 1:
				attach(terms[starta].coef, terms[starta].expon);
				starta++;
				break;
		}
	}

	for (; starta <= finisha; starta++)
		attach(terms[starta].coef, terms[starta].expon);

	for (; startb <= finishb; startb++)
		attach(terms[startb].coef, terms[startb].expon);

	*finishd = avail - 1;
}

poly_pos read_poly(void)
{
	poly_pos read_poly_pos = {avail, -1};
	float coef = 0;
	int expon = 0;
	char is_continue = 'n';

	do {
		printf("Please input the coef and expon of poly:\n");
		scanf("%f %d", &coef, &expon);
		pinsert(coef, expon, read_poly_pos.start, avail - 1);

		printf("Do you want to read another item input(y/n)?\n");
		scanf(" %c", &is_continue);

	} while (is_continue == 'y');

	read_poly_pos.finish = avail - 1;

	return read_poly_pos;
}

void print_poly(int start, int finish)
{
	int i = start;

	printf("Each item of the poly is: ");

	while (i <= finish)
	{
		printf("%.0fx^%d", terms[i].coef, terms[i].expon);

		i++;

		if (i <= finish)
			printf("+");
	}

	printf("\n");
}

/*int main(void)
{
	poly_pos position = read_poly();

	print_poly(position.start, position.finish);

	return 0;
}*/
