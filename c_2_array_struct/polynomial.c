#include "polynomial.h"

polynomial terms[MAX_TERMS];
int avail = 0;					/* the next availiable unit of terms's index */

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
				   int startd, int finishd)
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
				if (coeffcient)
					attach(coeffcient, terms[starta].expon);
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
