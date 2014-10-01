#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

int is_empty()
{
	return front == rear;
}

int is_full()
{
	return rear == MAX_QUEUE_SIZE - 1;
}

void addq(element item)
{
	if (is_full())
	{
		fprintf(stderr, "The queue is full, add failed.\n");
		exit(1);
	}
	
	queue[++rear] = item;
}

element deleteq(void)
{
	if (is_empty())
	{
		fprintf(stderr, "The queue is empty, delete failed.\n");
		exit(1);
	}

	return queue[++front];
}
