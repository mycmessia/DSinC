#include <stdio.h>
#include "stack.h"
#include "expression.h"

int main(void)
{
	//int s1, e1, s2, e2;
	//char exp[MAX_EXPR_SIZE] = "";

	//get_operands(exp, 14, &s1, &e1, &s2, &e2);
	
	//printf("s1 = %d, e1 = %d, s2 = %d, e2 = %d\n", s1, e1, s2, e2);

	char exp_in[MAX_EXPR_SIZE] = "abc-d+/ea-*c*\0";
	char exp_out[MAX_EXPR_SIZE];

	post2in(exp_in, exp_out);
	printf("postfix is %s -> infix is %s\n", exp_in, exp_out);

	return 0;
}
