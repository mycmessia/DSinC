#define MAX_EXPR_SIZE 1000
typedef enum {lparen, rparen, plus, minus, times, divide,
		mod, eos, operand} precedence;
/*
 * isp and icp arrays - index is value of precedence
 * lparen, rparen, plus, minus, times, divide, mod, eos
 * eg isp[plus] -> isp[2] means plus's precedence is 12
 */
static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};	/* in stack */
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};	/* out of stack */

int eval(void);
precedence get_token(char *symbol, int *n);
void in2post(void);
