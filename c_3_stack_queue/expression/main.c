#include <stdio.h>
#include "stack.h"
#include "expression.h"

int main(void)
{
	/* a string of expr end with a \n or a space */
	//char expr[MAX_EXPR_SIZE] = "/*193\n";	//prefix
	char exp_in[MAX_EXPR_SIZE] = "2*(3-4)\0";	//postfix
	char exp_out[MAX_EXPR_SIZE] = {'\0'};	

	printf("infix is %s\n", exp_in);
	in2post(exp_in, exp_out);
	printf("postfix is %s\n", exp_out);
	in2pre(exp_in, exp_out);
	printf("prefix is %s\n", exp_out);

	//printf("The result of exp is: %d\n", post_eval(exp));

	//pstack pstack_res = create_stack();
	//printf("%d\n", pstack_res->top);

	return 0;
}
