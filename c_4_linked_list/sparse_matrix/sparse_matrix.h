#ifndef SPARSE_MATRIX
#define SPARSE_MATRIX

#define MAX_SIZE 50 /* max of the col and row of sparse_matrix */
typedef enum {head, entry} tagfield;
typedef struct _matrix_node *matrix_pointer;

typedef struct _entry_node { 
	int row;
	int col;
	int value;
} entry_node;

typedef struct _matrix_node {
	matrix_pointer down;
	matrix_pointer right;
	tagfield tag;
	union {
		matrix_pointer next;
		entry_node entry;
	} u;
} matrix_node;

#define IS_FULL(ptr) (!(ptr))

matrix_pointer mread(void);
matrix_pointer new_node(void);
void mwrite(matrix_pointer node);

#endif
