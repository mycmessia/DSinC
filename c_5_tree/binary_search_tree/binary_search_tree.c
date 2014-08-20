#include <stdlib.h>
#include "binary_search_tree.h"

tree_pointer search(tree_pointer root, int key)
{
	if (!root)
		return NULL;
	else
	{
		if (root->data == key)
			return root
		else if (root->data > key)
			return search(root->left_child, key);
		else
			return search(root->right_child, key);
	}
}

tree_pointer iter_search(tree_pointer root, int key)
{
	if (!root)
		return NULL;
	else
	{
		while (root)
		{
			if (root->data == key)
				break;
			else if (root->data > key)
				root = root->left_child;
			else
				root = root->right_child;
		}

		return root;
	}
}

/**
 * if num is in the tree or root is NULL, return NULL
 * else return the last tree_pointer of the search
 */
tree_pointer modified_search(tree_pointer root, int num)
{
	tree_pointer last_ptr = NULL;

	if (root)
	{
		while (root)
		{
			if (root->data == key)
			{
				last_ptr = root;
				break;
			}
			else
			{
				last_ptr = root;
				if (root->data > num)
					root = root->left_child;
				else
					root = root->right_child;
			}
		}
	}

	return last_ptr;
}

/** 
 * if num is in the tree pointed at by node, do nothing,
 * otherwise add a new node with data = num
 */
void insert_node(tree_pointer *node, int num)
{
	tree_pointer ptr, temp = modified_search(*node, num);
	if (temp || !(*node))
	{
		ptr = (tree_pointer)malloc(sizeof(node));
		if (IS_MEMORY_FULL(ptr))
		{
			fprintf(stderr, "The memory is full.\n");
			exit(1);
		}
		ptr->data = num;
		ptr->left_child = ptr->right_child = NULL;
		
		if (*node)	/* insert as child of temp */
		{
			if (num < temp->data)
				temp->left_child = ptr;
			else
				temp->right_child = ptr;
		}
		else
			*node = ptr;
	}
}

tree_pointer *get_max_node(tree_pointer node)
{
}

/* TODO finish this function  */
void delete_node(tree_pointer root, int num)
{
	tree_pointer *max_node, ptr = iter_search(root, num);
	if (ptr)
	{
		if (ptr->left_child)
		{
			max_node = get_max_node(ptr->left_child);
			ptr->data = (*max_node)->data;
			if ((*max_node)->left_child)
			{
				(*max_node)->data = (*max_node)->left_child->data;
				(*max_node)->left_child = NULL;
			}
			else if ((*max_node)->right_child)
			{
				(*max_node)->data = (*max_node)->right_child->data;
				(*max_node)->right_child = NULL;
			}
			else
				*max_node = NULL;
		}
		else if (ptr->right_child)
		{
		}
		else
		{
			ptr = NULL;
		}
	}
	
	return ptr
}
