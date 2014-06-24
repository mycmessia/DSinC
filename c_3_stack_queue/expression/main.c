#include <stdio.h>
#include "stack.h"
#include "expression.h"

int main(void)
{
	/* a string of expr end with a \n or a space */
	char exp_in[MAX_EXPR_SIZE] = "23-4/\0";	//postfix
	char exp_out[MAX_EXPR_SIZE] = {'\0'};	

	/*
	printf("infix is %s\n", exp_in);
	in2post(exp_in, exp_out);
	printf("postfix is %s\n", exp_out);
	in2pre(exp_in, exp_out);
	printf("prefix is %s\n", exp_out);
	*/
	
	printf("postfix is %s\n", exp_in);
	post2in(exp_in, exp_out);
	printf("infix is %s\n", exp_out);
	in2post(exp_out, exp_in);
	printf("in2post postfix is %s\n", exp_in);

	return 0;
}
