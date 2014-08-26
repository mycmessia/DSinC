#include <stdio.h>
#include "binary_tree.h"

int main(void)
{
	tree_pointer root = create_tree();

	printf("inorder: ");
	inorder(root);
	printf("\n");
	
	printf("iter_inorder: ");
	iter_inorder(root);
	printf("\n");

	printf("preorder: ");
	preorder(root);
	printf("\n");

	printf("postorder: ");
	postorder(root);
	printf("\n");

	return 0;
}
