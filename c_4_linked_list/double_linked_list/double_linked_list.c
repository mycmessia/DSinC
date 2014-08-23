#include <stdlib.h>

void dinset(node_pointer node, node_pointer newnode)
{
	/* 
	 * node is the head node of list
	 * insert a newnode after node
	 */
	node->rlink = newnode;
	newnode->llink = node;
	newnode->rlink = node->rlink;
	node->rlink->llink = newnode;
}

void ddelete(node_pointer node, node_pointer deleted)
{
	if (node == deleted)
		printf("Deletion of head node not permitted.\n");
	else
	{
		deleted->llink->rlink = deleted->rlink;
		deleted->rlink->llink = deleted->llink;
		free(deleted);
	}
}
