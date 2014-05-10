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

#endif
