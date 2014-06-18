#ifndef EXPRESSION
#define EXPRESSION

#define MAX_EXPR_SIZE 100
typedef enum {lparen, rparen, plus, minus, times, divide,
		mod, eos, operand} precedence;

int calc_op(pstack pstack_res, precedence token);
precedence get_token(char exp[], char *symbol, int *n);
int post_eval(char exp[]);

#endif