#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

typedef struct node *tree_pointer;
typedef struct node {
	int data;
	tree_pointer left_child, right_child;
};

tree_pointer search(tree_pointer root, int key);
tree_pointer iter_search(tree_pointer root, int key);

void insert_node(tree_pointer *node, int sum);
#endif
