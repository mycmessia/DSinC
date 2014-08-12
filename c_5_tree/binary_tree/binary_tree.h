#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct node *tree_pointer;
typedef struct node {
	int data;
	tree_pointer left_child, right_child;
};

void inorder(tree_pointer ptr);
void preorder(tree_pointer ptr);
void postorder(tree_pointer ptr);

void iter_inorder(tree_pointer ptr);
void iter_preorder(tree_pointer ptr);
void iter_postorder(tree_pointer ptr);
int is_added(tree_pointer ptr);

void level_order(tree_pointer ptr);

tree_pointer copy(tree_pointer original);

/* function returns 0 if the binary trees first and second are not equal */
int equal(tree_pointer first, tree_pointer second);

int count(tree_pointer ptr);
void swap_tree(tree_pointer);

#endif
