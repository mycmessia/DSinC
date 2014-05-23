#include <stdio.h>
#include "polynomial.h"

extern polynomial terms[MAX_TERMS];
extern int avail;

/* Horner rule */
int peval(int start, int finish, int x)
{
	int sum = 0;
	int expon_t = 0;
	int coef_t = 0;
	int i = start;

	/*
	 * find the max expon of the poly 
	 * which determine loop count 
	 */
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
