#include <stdio.h>
#include "stack.h"
#include "expression.h"

/* a string of expr end with a \n or a space */
char expr[MAX_EXPR_SIZE] = "12+7*\n";

/* evaluate a postfix expression */
int eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	
	token = get_token(&symbol, &n);
	while (token != eos)
	{
		if (token == operand)
		{
			add(symbol - '0');
		}
		else
		{
			/* 
			 * delete two operands, perform operation,
			 * and return result to the stack
			 */
			op2 = delete();
			op1 = delete();
			switch (token)
			{
				case plus:
					add(op1 + op2);
					break;
				case minus:
					add(op1 - op2);
					break;
				case times:
					add(op1 * op2);
					break;
				case divide:
					add(op1 / op2);
					break;
				case mod:
					add(op1 % op2);
					break;
				default:
					printf("Invaild token in %s.\n", __FUNCTION__);
					return -1; 
			}
		}
		token = get_token(&symbol, &n);
	}

	return delete();
}

precedence get_token(char *symbol, int *n)
{
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
