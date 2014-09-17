#ifndef THREADED_TREE
#define THREADED_TREE

typedef struct _node *tree_pointer;
typedef struct _node {
	int data;
	tree_pointer left_child, right_child;
} node;

typedef enum {link, thread} pointer_tag;

typedef struct _threaded_tree *threaded_pointer;
typedef struct _threaded_tree {
	short int left_thread;		/* 1 if left_child is a thread */
	threaded_pointer left_child;
	char data;
	short int right_thread;;
	threaded_pointer right_child;
} threaded_tree;

tree_pointer new_node(int data);
tree_pointer create_tree(void);

threaded_pointer create_inorder_ttree(threaded_pointer tree);

/* find the inorder successor of thread_pointer tree *//
threaded_pointer insucc(threaded_pointer tree);

void tinorder(threaded_pointer tree);

void insert_right(threaded_pointer parent, threaded_pointer child);

void insert_left(threaded_pointer parent, threaded_pointer child);

#endif
