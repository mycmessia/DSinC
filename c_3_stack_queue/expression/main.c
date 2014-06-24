#include <stdio.h>
#include "stack.h"
#include "expression.h"

int main(void)
{
	int s1, e1, s2, e2;
	char exp[MAX_EXPR_SIZE] = "(3+5)((2+1)*5)";

	get_operands(exp, 14, &s1, &e1, &s2, &e2);
	
	printf("s1 = %d, e1 = %d, s2 = %d, e2 = %d\n", s1, e1, s2, e2);

	return 0;
}
