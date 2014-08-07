#include <stdlib.h>
#include "stack.h"
#include "two_branch_tree.h"

void inorder(tree_pointer ptr)
{
	if (ptr)
	{
		inorder(ptr->left_child);
		printf("%d", ptr->data);
		inorder(ptr->right_child);
	}
}

void preorder(tree_pointer ptr)
{
	if (ptr)
	{
		printf("%d", ptr->data);
		preorder(ptr->left_child);
		preorder(ptr->right_child);
	}
}

void postorder(tree_pointer ptr)
{
	if (ptr)
	{
		postorder(ptr->left_child);
		postorder(ptr->right_child);
		printf("%d", ptr->data);
	}
}

/* left root right */
void iter_inorder(tree_pointer node)
{
	for (;;)
	{
		for (; node; node = node->left_child)
			add(node);
		node = delete();
		if (!node) break;
		printf("%d", node->data);
		node = node->right_child;
	}

	printf("\n");
}

/* root left right */
void iter_preorder(tree_pointer ptr)
{
	for (;;)
	{
		if (!ptr) break;
		printf("%d", ptr->data);
		if (ptr->right_child)
			add(ptr->right_child);
		if (ptr->left_child)
			add(ptr->left_child);
		ptr = delete();
	}

	printf("\n");
}

/* left right root */
void iter_postorder(tree_pointer ptr)
{
	for (;;)
	{
		if (ptr)
		{
			if (ptr->right_child && !is_added(ptr->right_child))
			{
				add(ptr->right_child);
				ptr = ptr->right;
			}
			else if (ptr->left_child && !is_added(ptr->left_child))
			{
				add(ptr->left_child);
				ptr = ptr->left;
			}
			else
				ptr = NULL;
		}
		else
		{
			ptr = delete();
			if (!ptr) break;

			if ((!ptr->left_child && !ptr->right_child) || 
			    (is_added(ptr->left_child) && is_added(ptr->right_child)))
				printf("%d");
			else if (!is_added(ptr))
				add(ptr);
		}
	}

	printf("\n");
}

/* check if the ptr has been added to the stack */
int is_added(node_pointer ptr)
{
	
}

void level_order(tree_pointer ptr)
{
	if (!ptr) return;
	
	addq(ptr);
	for (;;)
	{
		ptr = deleteq();
		if (ptr)
		{
			printf("%d", ptr->data);
			if (ptr->left_child)
				addq(ptr->left_child);
			if (ptr->right_child)
				addq(ptr->right_child);
		}
		else
			break;
	}
}

void copy(tree_pointer original)
{
	tree_pointer temp;
	
	if (original)
	{
		temp = (tree_pointer) malloc(sizeof(node));
		if (IS_FULL(temp))
		{
			fprintf(stderr, "The memory is full.\n");
			exit(1);
		}
		temp->left_child = copy(original->left_child);
		temp->right_child = copy(original->right_child);
		temp->data = original->data;
		return temp;
	}
	else
		return NULL;
}
