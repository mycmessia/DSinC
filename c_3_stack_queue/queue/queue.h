#ifndef QUEUE
#define QUEUE

#define MAX_QUEUE_SIZE 100
typedef struct {
	int key;
} element;

void push(element item);
element pop(void);
void unshift(element item);
element shift(void);
void p_de_queue(void);

#endif
