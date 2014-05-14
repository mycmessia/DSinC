/* A new poly structure, see detail in Page 42 */
#include <stdio.h>
#include "../compare.h"

#define MAX_TERMS 101
#define MAX_POLYS 15

typedef struct {
	float coef;
	int expon;
} polynomial;

polynomial terms[MAX_POLYS][MAX_TERMS];

int avail = 0;

int read_poly (void)
{
	int i = 1;
	int poly_sum = 0, term_sum = 0;
	char answer = 'n';
	polynomial *poly = NULL;

	do {
		poly = &terms[avail][0];
		avail++;
		poly_sum++;

		printf("Please input the sum of terms in the poly:\n");
		scanf("%d", &term_sum);

		poly[0].expon = term_sum;

		for (i = 1; i <= term_sum; i++)
		{
			printf("Please input coef and expon of a term:\n");
			scanf("%f %d", &poly[i].coef, &poly[i].expon);
		}

		printf("Do you want to input another poly?(y/n)\n");
		scanf(" %c", &answer);

	} while (answer == 'y' || answer == 'Y');

	return poly_sum;
}

void print_poly(polynomial poly[])
{
	int term_sum = poly[0].expon;
	int i = 0;

	for (i = 1; i <= term_sum; i++)
	{
		printf("%.0fx^%d", poly[i].coef, poly[i].expon);
		if (i < term_sum)
			printf("+");
	}
	printf("\n");
}

void pinsert(polynomial poly[], float coef, int expon)
{
	int sum = poly[0].expon;
	int i;
	
	for (i = 1; i <= sum; i++)
	{
		if (poly[i].expon == expon)
		{
			poly[i].coef += coef;
			return;
		}
	}

	poly[0].expon += 1;
	poly[poly[0].expon].coef = coef;
	poly[poly[0].expon].expon = expon;
}

/* 
 * read poly from poly1 and poly2 and store the result in poly3 
 */
void padd(polynomial poly1[], polynomial poly2[], polynomial poly3[])
{
	int sum1 = poly1[0].expon;
	int sum2 = poly2[0].expon;
	int i = 1, j = 1;

	poly3[0].expon = 0;
	
	while (i <= sum1 && j <= sum2) 
	{
		switch (COMPARE(poly1[i].expon, poly2[j].expon)) {
		 case -1:
			pinsert(poly3, poly2[j].coef, poly2[j].expon);
			j++;
			break;
		 case 0:
			pinsert(poly3, 
				poly1[i].coef + poly2[j].coef, 
				poly1[i].expon);
			i++;
			j++;
			break;
		 case 1:
			pinsert(poly3, poly1[i].coef, poly1[i].expon);
			i++;
			break;
		}
	}

	while (i <= sum1) {
		pinsert(poly3, poly1[i].coef, poly1[i].expon);
		i++;
	}

	while (j <= sum2) {
		pinsert(poly3, poly2[j].coef, poly2[j].expon);
		j++;
	}

	
}

void pmult(polynomial poly1[], polynomial poly2[], polynomial poly3[])
{
	int sum1 = poly1[0].expon;
	int sum2 = poly2[0].expon;

	poly3[0].expon = 0;

	int i, j;
	int coef, expon;

	for (i = 1; i <= sum1; i++)
	{
		for (j = 1; j <= sum2; j++)
		{
			coef = poly1[i].coef * poly2[j].coef;
			expon = poly1[i].expon + poly2[j].expon;
			pinsert(poly3, coef, expon);
		}
	}
}

int main(void)
{
	int poly_sum = read_poly();

	int i = 1;

	while (i <= poly_sum)
	{
		print_poly(&terms[avail - i][0]);
		i++;
	}

	printf("padd:\n");
	padd(&terms[0][0], &terms[1][0], &terms[avail++][0]);
	print_poly(terms[avail - 1]);

	printf("pmult:\n");
	pmult(&terms[0][0], &terms[1][0], &terms[avail++][0]);
	print_poly(terms[avail - 1]);

	return 0;
}
