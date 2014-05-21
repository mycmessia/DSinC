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
void read_sm(term a[]);
void print_sm(term a[]);
void search_sm(term a[], int key, term *res);
void mmult(term a[], term b[], term d[]);

#endif
