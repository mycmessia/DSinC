#include <stdio.h>
#include "queue.h"

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

element queue_empty(void)
{
	element err_empty = {1};

	fprintf(stderr, "queue is empty!\n");
	return err_empty;
}

void queue_full(void)
{
	fprintf(stderr, "queue is full!\n");
	return;
}

void addq(int *rear, element item)
{
	if (*rear == MAX_QUEUE_SIZE - 1)
	{
		return queue_full();
	}
	queue[++*rear] = item;
}

element deleteq(int *front, int rear)
{
	if (*front == rear)
		return queue_empty();
	return queue[++*front];
}

element de_queue[MAX_QUEUE_SIZE];
int de_front = 0, de_rear = 0;

void push(element item)
{
	if (de_rear == MAX_QUEUE_SIZE - 1)
		return queue_full();
	de_queue[de_rear++] = item;
}

element pop(void)
{
	if (de_rear <= de_front)
		return queue_empty();
	return de_queue[--de_rear];
}

void unshift(element item)
{
	if (de_rear == MAX_QUEUE_SIZE - 1)
		return queue_full();
	int i = de_rear;
	for (i = de_rear; i >= de_front; i--)
	{
		de_queue[i + 1] = de_queue[i];
	}
	de_rear++;
	de_queue[de_front] = item;
}

element shift(void)
{
	if (de_front > de_rear)
		return queue_empty();
	return de_queue[de_front++];
}

void p_de_queue(void)
{
	int i = de_front;

	for (i = de_front; i < de_rear; i++)
		printf("key = %d\n", de_queue[i].key);
}
