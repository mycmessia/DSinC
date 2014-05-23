#include "sparse_matrix.h"

int main(void)
{
	term a[MAX_TERMS] = {
		{1, 2, 2},
		{0, 0, 1},
		{0, 1, 3}
	};
	term b[MAX_TERMS] = { 
		{2, 1, 2},
		{0, 0, 5},
		{1, 0, 6}
	};
	term d[MAX_TERMS];	

	mprint(b);
	//fast_transpose(b, d);

	fast_mmult(a, b, d);

	mprint(d);	

	return 0;
}
