#ifndef ONE_WAY_LINKED_POLY
#define ONE_WAY_LINKED_POLY

typedef struct poly_node *poly_pointer;
typedef struct poly_node {
	int coef;
	int expon;
	poly_pointer link;
}

#endif
