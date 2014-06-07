#ifndef QUEUE
#define QUEUE

#define MAX_QUEUE_SIZE 2

typedef struct {
	int key;
} element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int length;
	int head;
	int rear;
} double_ended_queue;

typedef double_ended_queue *pde;

void queue_full(pde p);
element queue_empty(pde p);

void push(pde p, element item);
element pop(pde p);

void unshift(pde p, element item);
element shift(pde p);

void print_deque(pde p);
#endif
