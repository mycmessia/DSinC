#ifndef SPARSE_MATRIX
#define SPARSE_MATRIX

#define MAX_TERMS 101
typedef struct {
	int row; 
	int col;
	int value;
} term;

void transpose(term a[], term b[]);
void fast_transpose(term a[], term b[]);
void mread(term a[]);
void mprint(term a[]);
void msearch(term a[], int key, term *res);
void fast_mmult(term a[], term b[], term d[]);

#endif
