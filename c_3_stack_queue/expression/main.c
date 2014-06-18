#include <stdio.h>
#include "stack.h"
#include "expression.h"

int main(void)
{
	/* a string of expr end with a \n or a space */
	//char expr[MAX_EXPR_SIZE] = "/*193\n";	//prefix
	char exp[MAX_EXPR_SIZE] = "234*+\n";	//postfix
	
	printf("The result of exp is: %d\n", post_eval(exp));

	//pstack pstack_res = create_stack();
	//printf("%d\n", pstack_res->top);

	return 0;
}
