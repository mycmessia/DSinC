#include <stdio.h>
#include "poly_operate.h"

extern polynomial terms[MAX_TERMS];
extern int avail;	/* the next availiable unit of terms's index */

void pinsert(float coef, int expon, int start, int finish)
{
	int i = 0;
	int is_exist = 0;

	for (i = start; i <= finish; i++)
	{
		if (terms[i].expon == expon)
		{
			terms[i].coef = terms[i].coef + coef;
			is_exist = 1;
			break;	
		}
	}

	if (!is_exist)
	{
		attach(coef, expon);
	}
}

void pmult(int starta, int finisha, int startb, int finishb,
				    int *startd, int *finishd)
{
	*startd = avail;
	int i = starta, j = startb;
	polynomial poly_t;

	for (i = starta; i <= finisha; i++)
	{
		for (j = startb; j <= finishb; j++)
		{	
			poly_t.coef = terms[i].coef * terms[j].coef;
			poly_t.expon = terms[i].expon + terms[j].expon;
			pinsert(poly_t.coef, poly_t.expon, 
				*startd, avail - 1);
		}
	}
	
	*finishd = avail - 1;
}

int main(void)
{
	poly_pos pos1 = read_poly();
	print_poly(pos1.start, pos1.finish);

	poly_pos pos2 = read_poly();
	print_poly(pos2.start, pos2.finish);

	poly_pos pos3;

	pmult(pos1.start, pos1.finish, pos2.start, pos2.finish,
	      &pos3.start, &pos3.finish);

	printf("mult poly:\n");
	print_poly(pos3.start, pos3.finish);

	return 0;
}
