/* dynamic linked queue */
#include <stdio.h>
#include "dlinked_queue.h"

queue_pointer front[MAX_QUEUE], rear[MAX_QUEUE];

void addq(queue_pointer *front, queue_pointer *rear, element item)
{
	/* add an element to the rear of the queue */
	queue_pointer temp = (queue_pointer) malloc(sizeof(queue));
	
	if (IS_FULL(temp))
	{
		fprintf(stderr, "The memory is full.\n");
		return;
	}

	temp->item = item;
	temp->link = NULL;
	if (*front) (*rear)->link = temp;
	else *front = temp;

	*rear = temp;
}

element deleteq(queue_pointer *front)
{
	/* delete an element from the front of the queue */
	queue_pointer temp = *front;
	element item;
	
	if (IS_EMPTY(*front))
	{
		fprintf(stderr, "The queue is empty.\n");
		return item;
	}

	item = temp->item;
	*front = temp->link;
	free(temp);
	
	return item;
}
