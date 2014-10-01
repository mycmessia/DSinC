#ifndef QUEUE
#define QUEUE

#define MAX_QUEUE_SIZE 100

typedef struct {
	int data;
} element;

int is_queue_empty(void);
int is_queue_full(void);

void addq(element item);
element deleteq(void);

#endif
