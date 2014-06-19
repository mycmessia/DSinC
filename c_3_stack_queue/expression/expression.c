#include <stdio.h>
#include "stack.h"
#include "expression.h"

/*
 * isp and icp arrays - index is value of precedence
 * lparen, rparen, plus, minus, times, divide, mod, eos
 * eg isp[plus] -> isp[2] means plus's precedence is 12.
 * 
 * The reason we need two precedence is lparen '(' must add to
 * the stack and other token must add after the lparen so the
 * lparen must have two precedence to keep the code unitive.
 */
static int inp[] = {0, 19, 12, 12, 13, 13, 13, 0};	/* in stack */
static int outp[] = {20, 19, 12, 12, 13, 13, 13, 0};	/* out of stack */

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

void print_token(precedence token)
{
	switch (token)
	{
		case lparen:	printf("("); break;
		case rparen:	printf(")"); break;
		case plus:	printf("+"); break;
		case minus:	printf("-"); break;
		case divide:	printf("/"); break;
		case times:	printf("*"); break;
		case mod:	printf("%"); break;
		default: 	printf(""); break;
	}
}

void in2post(char exp[])
{
	char symbol;
	int n = 0;
	int top = -1;
	precedence token = get_token(exp, &symbol, &n);
	pstack pstack_tmp = create_stack();
	
	sadd(pstack_tmp, eos);
	for (; token != eos; token = get_token(exp, &symbol, &n))
	{		
		if (token == operand)
			printf("%c", symbol);
		else if (token == rparen)
		{
			top = pstack_tmp->top;
			while (pstack_tmp->space[top] != lparen)
				print_token(sdelete(pstack_tmp));
			sdelete(pstack_tmp);
		}
		else
		{
			top = pstack_tmp->top;
			while (outp[pstack_tmp->space[pstack_tmp->top]] >=
				inp[token])
			{
				print_token(sdelete(pstack_tmp));
			}
			sadd(pstack_tmp, token);
		}
	}

	while ((token = sdelete(pstack_tmp)) != eos)
		print_token(token);
	printf("\n");
}
