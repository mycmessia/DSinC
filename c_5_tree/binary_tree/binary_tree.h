#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct _node *tree_pointer;
typedef struct _node {
	int data;
	int is_added;
	tree_pointer left_child, right_child;
} node;

tree_pointer new_node(int data);
tree_pointer create_tree(void);

void inorder(tree_pointer ptr);
void preorder(tree_pointer ptr);
void postorder(tree_pointer ptr);

void iter_inorder(tree_pointer ptr);
void iter_preorder(tree_pointer ptr);
void iter_postorder(tree_pointer ptr);
int is_added(tree_pointer ptr);

void level_order(tree_pointer ptr);

tree_pointer copy(tree_pointer original);

/* function return 0 if the binary tree first and second are not equal */
int equal(tree_pointer first, tree_pointer second);

int count(tree_pointer ptr);
void swap_tree(tree_pointer);

#endif
