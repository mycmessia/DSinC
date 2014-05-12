#ifndef POLYNOMIAL
#define POLYNOMIAL

#define MAX_TERMS 100
typedef struct {
	float coef;
	int expon;
} polynomial;

typedef struct {
	int start;
	int finish;
} poly_pos;

poly_pos read_poly(void);
void print_poly(int, int);
void pmult(int, int, int, int, int *, int *);
void attach(float, int);
void padd(int, int, int, int, int *, int *);
void pinsert(float, int, int, int);
int peval(int start, int finish, int x);
#endif
