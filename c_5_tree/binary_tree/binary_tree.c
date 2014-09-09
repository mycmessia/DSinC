#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "binary_tree.h"

tree_pointer new_node(int data)
{
	tree_pointer ptr = (tree_pointer) malloc(sizeof(node));
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

tree_pointer create_tree(void)
{
	tree_pointer root = new_node(1);
	root->left_child = new_node(2);
	root->right_child = new_node(3);

	root->left_child->left_child = new_node(4);
	root->left_child->right_child = new_node(5);

	root->right_child->left_child = new_node(6);
	root->right_child->right_child = new_node(7);

	return root;
}

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
	return !(ptr->is_added);
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
			fprintf(stderr, "The memory is full.");
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

int map_index[256];
void map2index(int inorder[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		map_index[inorder[i]] = i;
}

/* n is the count of node, offset is the start of child tree */
tree_pointer build_inorder_preorder(int pre[], int n, int offset)
{
	if (!n) return NULL;
	int root_data = pre[0];
	int i = map_index[root_data] - offset;
	tree_pointer root = new_node(root_data);
	root->left_child = build_inorder_preorder(pre + 1, i, offset);
	root->right_child = build_inorder_preorder(pre + i + 1, n - i - 1, offset + i + 1);
	return root;
}

//TODO
tree_pointer bulid_inorder_postorder(int post[], int n, int offset)
{
}
