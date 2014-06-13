#include <stdio.h>
#include "stack.h"
#include "expression.h"

/* a string of expr end with a \n or a space */
//char expr[MAX_EXPR_SIZE] = "/*193\n";	//prefix
char expr[MAX_EXPR_SIZE] = "234*+\n";	//postfix

/*
 * isp and icp arrays - index is value of precedence
 * lparen, rparen, plus, minus, times, divide, mod, eos
 * eg isp[plus] -> isp[2] means plus's precedence is 12.
 * 
 * The reason we need two precedence is lparen '(' must add to
 * the stack and other token must add after the lparen so the
 * lparen must have two precedence to keep the code unitive.
 */
static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};	/* in stack */
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};	/* out of stack */

/* 0 for postfix, 1 for prefix */
int calc_op(precedence token, int type)
{
	/* 
	 * delete two operands, perform operation,		
	 * and return result to the stack
	 */
	int op1, op2;
	if (type)
	{
		op1 = delete();
		op2 = delete();
	}
	else
	{
		op2 = delete();
		op1 = delete();
	}

	switch (token)
	{
		case plus: add(op1 + op2); break;
		case minus: add(op1 - op2); break;
		case times: add(op1 * op2); break;
		case divide: add(op1 / op2); break;
		case mod: add(op1 % op2); break;
		default:
			printf("Invaild token in %s.\n", __FUNCTION__);
			return -1; 
	}
	return 0;
}

/* evaluate a postfix expression */
int post_eval(void)
{
	precedence token;
	char symbol;
	int n = 0;
	
	token = get_token(&symbol, &n, 0);
	while (token != eos)
	{
		if (token == operand)
			add(symbol - '0');
		else
			if (calc_op(token, 0)) return;
		token = get_token(&symbol, &n, 0);
	}

	return delete();
}

/* type 0 from head to tail, type 1 from tail to head */
precedence get_token(char *symbol, int *n, int type)
{
	if (type)
		*symbol = expr[(*n)--];
	else
		*symbol = expr[(*n)++];
	
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

void in2post(void)
{
	char symbol;
	int n = 0;
	precedence token = get_token(&symbol, &n, 0);
	add(eos);

	for (; token != eos; token = get_token(&symbol, &n, 0))
	{
		if (token == operand)
			printf("%c", symbol);
		else if (token == rparen)
		{
			while (get_top() != lparen)
				print_token(delete());
			delete();
		}
		else
		{
			while (isp[get_top()] >= icp[token])
				print_token(delete());
			add(token);
		}
	}
	
	while ((token = delete()) != eos)
		print_token(token);
	printf("\n");
}

int get_length(char *str)
{
	int i = 0;
	while (str[i] != '\n' && str[i] != ' ')
		i++;
	return i;
}

int pre_eval(void)
{
	precedence token;
	char symbol;
	int i = get_length(expr) - 1;
	while (i >= 0)
	{
		token = get_token(&symbol, &i, 1);
		if (token == operand)
			add(symbol - '0');
		else
			if (calc_op(token, 1)) return;
	}

	return delete();
}
