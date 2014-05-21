#include "sparse_matrix.h"

int main(void)
{
	term a[MAX_TERMS] = {
		{2, 3, 3},
		{0, 0, 1},
		{1, 0, 3},
		{1, 1, 4}
	};
	term b[MAX_TERMS] = { 
		{3, 2, 4},
		{0, 2, 5},
		{1, 0, 6},
		{1, 1, 7},
		{2, 1, 8}
	};
	term d[MAX_TERMS];	

	//print_sm(a);
	print_sm(b);
	fast_transpose(b, d);

	//mmult(a, b, d);

	print_sm(d);	

	return 0;
}
