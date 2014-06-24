#ifndef EXPRESSION
#define EXPRESSION

#define MAX_EXPR_SIZE 100

typedef enum {lparen, rparen, plus, minus, times, divide,
		mod, eos, operand} precedence;

int calc_op(pstack pstack_res, precedence token);

precedence get_token(char exp[], char *symbol, int *n);

int post_eval(char exp[]);

int in2post(char exp_in[], char exp_out[]);

int in2pre(char exp_in[], char exp_out[]);

char get_symbol(precedence token);

int post2in(char exp_in[], char exp_out[]);

void get_operands(char exp[], int n, int *s1, int *e1, int *s2, int *e2);

#endif
