#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "binary_tree.h"

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
				ptr = ptr->right_child;
			}
			else if (ptr->left_child && !is_added(ptr->left_child))
			{
				add(ptr->left_child);
				ptr = ptr->left_child;
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
				printf("%d", ptr->data);
			else if (!is_added(ptr))
				add(ptr);
		}
	}

	printf("\n");
}

/* check if the ptr has been added to the stack */
int is_added(tree_pointer ptr)
{
	//TODO finish the func
	return 1;	
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

tree_pointer copy(tree_pointer original)
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

int equal(tree_pointer first, tree_pointer second)
{
	return (
		(!first && !second) ||
		(first && second &&
			(
				first->data == second->data &&
			 	equal(first->left_child, second->left_child) &&
			 	equal(first->right_child, second->right_child)
			)
		)
	);
}

void swap_tree(tree_pointer ptr)
{
	if (ptr)
	{
		tree_pointer ptemp = ptr->left_child;
		ptr->left_child = ptr->right_child;
		ptr->right_child = ptemp;
		swap_tree(ptr->left_child);
		swap_tree(ptr->right_child);
	}
}

int count(tree_pointer ptr)
{
	int sum = 0;
	for (;;)
	{
		for (; ptr->left_child; ptr = ptr->left_child)
			add(ptr->left_child);
		ptr = delete();
		if (!ptr) break;
		sum++;
		if (ptr->right_child)
			add(ptr->right_child);
	}

	return sum;
}