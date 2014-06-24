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
		case '\0': return eos;
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

/* TODO pre_eval */

char get_symbol(precedence token)
{
	switch (token)
	{
		case lparen:	return '(';
		case rparen:	return ')';
		case plus:	return '+';
		case minus:	return '-';
		case divide:	return '/';
		case times:	return '*';
		case mod:	return '%';
		default: 	return ' ';
	}
}

int in2post(char exp_in[], char exp_out[])
{
	char symbol;
	int n = 0, i = 0;
	precedence token = get_token(exp_in, &symbol, &n);
	pstack pstack_t = create_stack();
	
	sadd(pstack_t, eos);
	for (; token != eos; token = get_token(exp_in, &symbol, &n))
	{		
		if (token == operand)
			exp_out[i++] = symbol;
		else if (token == rparen)
		{
			while (pstack_t->space[pstack_t->top] != lparen)
			{
				exp_out[i++] = get_symbol(sdelete(pstack_t));
			}
			sdelete(pstack_t);
		}
		else
		{
			while (inp[pstack_t->space[pstack_t->top]] >=
				outp[token])
			{
				exp_out[i++] = get_symbol(sdelete(pstack_t));
			}
			sadd(pstack_t, token);
		}
	}

	while ((token = sdelete(pstack_t)) != eos)
		exp_out[i++] = get_symbol(token);
	
	exp_out[i] = '\0';

	return i;
}

int in2pre(char exp_in[], char exp_out[])
{
	char exp_tmp[MAX_EXPR_SIZE] = {'\0'};
	int i = 0, length = 0;	

	length = in2post(exp_in, exp_tmp);

	exp_out[length] = '\0';
	for (i = 0; i < length; i++)
	{
		exp_out[length - i - 1] = exp_tmp[i];
	}

	return length;	
}

/* trans a postfix to a infix with the most parenthesis */
int post2in(char exp_in[], char exp_out[])
{
	pstack poperand = create_stack();
	int first_operator = 1;
	int  n = 0, i = 0;
	char symbol = 0, c1, c2;

	int token = get_token(exp_in, &symbol, &n);
	for (; token != eos; token = get_token(exp_in, &symbol, &n))
	{
		if (token == operand)
			sadd(poperand, symbol - '0');
		else
		{
			add_lparen(exp_out, i);
			i++;
			if (first_operator && !is_empty(poperand))
			{
				c1 = sdelete(poperand) + '0';
				c2 = sdelete(poperand) + '0';
				exp_out[i++] = c2;
				exp_out[i++] = get_symbol(token);
				exp_out[i++] = c1;
				first_operator = 0;
			}
			else
			{
				exp_out[i++] = get_symbol(token);
				exp_out[i++] = sdelete(poperand) + '0';
			}
			exp_out[i++] = get_symbol(rparen);
		}
	}

	return i;
}

/* here use doubly queue may be better */
void add_lparen(char exp[], int i)
{
	while (i > 0)
	{
		exp[i] = exp[i - 1];
		i--;
	}

	exp[0] = get_symbol(lparen);
}
