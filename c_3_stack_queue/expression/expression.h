#define MAX_EXPR_SIZE 1000
typedef enum {lparen, rparen, plus, minus, times, divide,
		mod, eos, operand} precedence;

int eval(void);
precedence get_token(char *symbol, int *n);
