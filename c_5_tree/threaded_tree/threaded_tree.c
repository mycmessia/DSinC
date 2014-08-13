#include "threaded_tree.h"

threaded_pointer insucc(threaded_pointer tree)
{
	threaded_pointer temp;
	temp = tree->right_child;

	if (!tree->right_thread)
		while (!temp->left_thread)
			temp = temp->left_child;
	return temp;
}

void insert_right(threaded_pointer parent, threaded_pointer child)
{
	threaded_pointer temp;

	child->left_thread = 1;
	child->left_child = parent;

	child->right_thread = parent->right_thread;
	child->right_child = parent->right_child;
	
	parent->right_thread = 0;
	parent->right_child = child;

	if (!child->right_thread)
	{
		temp = insucc(child);
		temp->left_child = child;	//temp->left_thread must be 1
	}
}

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
