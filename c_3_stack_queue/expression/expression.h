#ifndef EXPRESSION
#define EXPRESSION

#define MAX_EXPR_SIZE 100
typedef enum {lparen, rparen, plus, minus, times, divide,
		mod, eos, operand} precedence;

int calc_op(pstack pstack_res, precedence token);
precedence get_token(char exp[], char *symbol, int *n);
int post_eval(char exp[]);
int in2post(char exp_in[], char exp_out[]);
void print_token(precedence token);
int in2pre(char exp_in[], char exp_out[]);

#endif
