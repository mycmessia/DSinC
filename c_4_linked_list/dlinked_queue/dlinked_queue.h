#ifndef DLINKED_QUEUE
#define DLINKED_QUEUE

#define MAX_QUEUE 10
typedef struct _queue *queue_pointer;
typedef struct _queue {
	element item;
	queue_pointer link;
} queue;

#define IS_MEMORY_FULL(p) (!(p))
#define IS_QUEUE_EMPTY(p) (!(p))

void addq(queue_pointer *front, queue_pointer *rear, element item);
element deleteq(queue_pointer *front);

#endif
