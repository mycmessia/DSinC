#include <stdio.h>
#include "binary_tree.h"

int main(void)
{
	/*tree_pointer root = create_tree();

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
	printf("\n");*/

	int pre[] = {7, 10, 4, 3, 1, 2, 8, 11};
	int in[] = {4, 10, 3, 1, 7, 11, 8, 2};
	int n = sizeof(in) / sizeof(in[0]);
	//printf("the count of tree nodes is %d\n", n);
	map2index(in, n);
	tree_pointer root = build_inorder_preorder(pre, n, 0);
	printf("postorder: ");
	postorder(root);
	printf("\n");

	return 0;
}
