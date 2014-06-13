#define MAX_EXPR_SIZE 1000
typedef enum {lparen, rparen, plus, minus, times, divide,
		mod, eos, operand} precedence;

precedence get_token(char *symbol, int *n, int type);
void print_token(precedence item);
int calc_op(precedence token, int type);

int post_eval(void);
void in2post(void);

int pre_eval(void);
int in2pre(void);
