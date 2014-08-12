#include "threaded_tree.h"

void insert_left(threaded_pointer parent, threaded_pointer child)
{
	child->left_thread = parent->left_thread;;
	child->left_child = parent->left_child;
	
	child->right_child = parent;
	child->right_thread = 1;

	parent->left_child = child;
	parent->left_thread = 0;

	child->left_child->right_child = child;
}
