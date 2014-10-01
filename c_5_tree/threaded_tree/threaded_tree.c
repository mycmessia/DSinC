#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "threaded_tree.h"

threaded_pointer new_node(int data)
{
	threaded_pointer ptr = (threaded_pointer) malloc(sizeof(threaded_node));
	if (IS_FULL(ptr))
	{
		fprintf(stderr, "The memory is full.\n");
		exit(1);
	}
	else
	{
		ptr->data = data;
		ptr->is_added = 0;
		ptr->left_child = NULL;
		ptr->right_child = NULL;
	}
	
	return ptr;
}

threaded_pointer create_tree(void)
{
	threaded_pointer root = new_node(1);
	root->left_child = new_node(2);
	root->right_child = new_node(3);

	root->left_child->left_child = new_node(4);
	root->left_child->right_child = new_node(5);

	root->right_child->left_child = new_node(6);
	root->right_child->right_child = new_node(7);

	return root;
}

/* create a inorder threaded tree */
threaded_pointer create_inorder_ttree(threaded_pointer node)
{
	threaded_pointer root = malloc(sizeof(threaded_node));
	root->left_child = node;
	root->left_thread = 0;
	root->right_child = root;	
	root->right_thread = 0;

	threaded_pointer pre = root;
	threaded_pointer tmp = NULL;	
	
	for (;;)
	{
		for (; node; node = node->left_child)
			add(node);
		node = delete();
		if (!node) break;
		if (!node->left_child)
		{
			node->left_child = pre;
			node->left_thread = 1;
		}
		else
			node->left_thread = 0;
		pre = node;

		if (!node->right_child)
		{
			tmp = insucc(node);
			node->right_child = tmp == node ? root : tmp;;
			node->right_thread = 1;
			node = NULL;
		}
		else
		{
			node->right_thread = 0;
			node = node->right_child;
		}
	}
}

threaded_pointer insucc(threaded_pointer tree)
{
	threaded_pointer temp;
	temp = tree->right_child;

	if (!tree->right_thread)
		while (!temp->left_thread)
			temp = temp->left_child;
	return temp;
}

void tinorder(threaded_pointer tree)
{
	threaded_pointer temp = tree;

	for (;;)
	{
		temp = insucc(tree);
		if (temp == tree) break;
		printf("%3d", temp->data);
	}
	printf("\n");
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
