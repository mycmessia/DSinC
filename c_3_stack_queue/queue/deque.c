#include <stdio.h>
#include "deque.h"

double_ended_queue deque;

void queue_full(pde p)
{
	fprintf(stderr, "The queue is full.\n");
	return;
}

element queue_empty(pde p)
{
	fprintf(stderr, "The queue is empty.\n");
	element err_empty = {1};
	return err_empty;
}

void push(pde p, element item)
{
	if (p->length == MAX_QUEUE_SIZE)
		return queue_full(p);
	
	p->rear = (p->rear + 1) % MAX_QUEUE_SIZE;
	p->length++;
	p->queue[p->rear] = item;
	//p->rear = (p->rear + 1) % MAX_QUEUE_SIZE;
}

element pop(pde p)
{
	if (p->length == 0)
		return queue_empty(p);

	p->rear = (p->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	p->length--;
	return p->queue[p->rear];
}

void unshift(pde p, element item)
{
	if (p->length == MAX_QUEUE_SIZE)
		return queue_full(p);
	
	p->head = (p->head - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	p->length++;
	p->queue[p->head] = item;
	//p->head = (p->head - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	
}

element shift(pde p)
{
	if (p->length == 0)
		return queue_empty(p);

	p->head = (p->head + 1) % MAX_QUEUE_SIZE;
	p->length--;
	return p->queue[p->head];
}

void print_deque(pde p)
{
	int i = p->head;
	int j = 0;

	while (j < p->length)
	{
		printf("key = %d\t", p->queue[i].key);
		i = (i + 1) % MAX_QUEUE_SIZE;
		
		j++;
		if (!(j % 3))	printf("\n");
	}
	
	if (j < 3) printf("\n");
}
