/* dynamic linked queue */
#include <stdlib.h>
#include <stdio.h>
#include "dlinked_queue.h"

queue_pointer front[MAX_QUEUE], rear[MAX_QUEUE];

void addq(queue_pointer *front, queue_pointer *rear, int  vertex)
{
	/* add an element to the rear of the queue */
	queue_pointer temp = (queue_pointer) malloc(sizeof(queue));
	
	if (IS_MEMORY_FULL(temp))
	{
		fprintf(stderr, "The memory is full.\n");
		return;
	}

	temp->vertex = vertex;
	temp->link = NULL;
	if (*front) (*rear)->link = temp;
	else *front = temp;

	*rear = temp;
}

int deleteq(queue_pointer *front)
{
	/* delete an element from the front of the queue */
	queue_pointer temp = *front;
	int vertex = -1;
	
	if (IS_QUEUE_EMPTY(*front))
	{
		fprintf(stderr, "The queue is empty.\n");
		return vertex;
	}

	vertex = temp->vertex;
	*front = temp->link;
	free(temp);
	
	return vertex;
}
