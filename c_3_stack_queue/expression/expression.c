#include <stdio.h>
#include "stack.h"
#include "expression.h"

int calc_op(pstack pstack_res, precedence token)
{
	/* 
	 * delete two operands, perform operation,		
	 * and return result to the stack
	 */
	int op1, op2;
	op1 = sdelete(pstack_res);
	op2 = sdelete(pstack_res);

	switch (token)
	{
		case plus: sadd(pstack_res, op1 + op2); break;
		case minus: sadd(pstack_res, op1 - op2); break;
		case times: sadd(pstack_res, op1 * op2); break;
		case divide: sadd(pstack_res, op1 / op2); break;
		case mod: sadd(pstack_res, op1 % op2); break;
		default:
			printf("Invaild token in %s.\n", __FUNCTION__);
			return -1; 
	}
	return 0;
}

/* evaluate a postfix expression */
int post_eval(char exp[])
{
	precedence token;
	char symbol;
	int n = 0;
	pstack pstack_res = create_stack();
	
	token = get_token(exp, &symbol, &n);
	while (token != eos)
	{
		if (token == operand)
			sadd(pstack_res, symbol - '0');
		else
			if (calc_op(pstack_res, token)) return -1;
		token = get_token(exp, &symbol, &n);
	}

	return sdelete(pstack_res);
}

precedence get_token(char exp[], char *symbol, int *n)
{
	*symbol = exp[(*n)++];
	
	switch (*symbol)
	{
		case '(': return lparen;
		case ')': return rparen;
		case '+': return plus;
		case '-': return minus;
		case '/': return divide;
		case '*': return times;
		case '%': return mod;
		case ' ': return eos;
		case '\n': return eos;
		default: return operand;
	}
}
