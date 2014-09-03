#ifndef IS_SATISFIED
#define IS_SATISFIED

#define TRUE 1
#define FALSE 0

typedef enum {not, and, or, true, false} logical;
typedef struct _node *tree_pointer
typedef struct _node {
	tree_pointer left_child;
	logical data;
	short int value;
	tree_pointer right_child;
} node;

/*
 * modified post order traversal to 
 * evaluate a propositional calculus tree
 */
void post_order_eval(tree_pointer node)
{
	if (node)
	{
		post_order_eval(node->left_child);
		post_order_eval(node->right_child);
		switch (node->data)
		{
			case not:
				node->value = !(node->right_child->value);
				break;
			case and:
				node->value = node->left_child->value &&
					      node->right_child->value;
				break;
			case or:
				node->value = node->left_child->value ||
					      node->right_child->value;
				break;
			case true:
				node->value = TRUE;
				break;
			case false:
				node->value = FALSE;
				break;
			default:
				fprintf(stderr, "node->value is invalid.\n");
				break;
		}
	}
}

#endif
