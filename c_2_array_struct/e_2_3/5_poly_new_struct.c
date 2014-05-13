/* A new poly structure, see detail in Page 42 */
#include <stdio.h>

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

int main(void)
{
	int poly_sum = read_poly();

	int i = 1;

	while (i <= poly_sum)
	{
		print_poly(&terms[avail - i][0]);

		i++;
	}

	return 0;
}
