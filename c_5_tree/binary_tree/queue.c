#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "binary_tree.h"

static tree_pointer queue[MAX_QUEUE_SIZE];
static int head = -1, rear = 0, length = 0;

void addq(tree_pointer ptr)
{
	if (length == MAX_QUEUE_SIZE)
	{
		fprintf(stderr, "The queue is full.\n");
		exit(1);
	}
	length++;	

	queue[rear] = ptr;
	rear = (rear + 1) % MAX_QUEUE_SIZE;
}

tree_pointer deleteq(void)
{
	if (length == 0)
	{
		fprintf(stderr, "The queue is empty.\n");
		exit(1);
	}
	length--;

	head = (head + 1) % MAX_QUEUE_SIZE;

	return queue[head];
}
