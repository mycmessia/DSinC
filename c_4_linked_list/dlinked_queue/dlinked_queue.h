#define MAX_QUEUE 10
typedef struct queue *queue_pointer;
typedef struct queue {
	element item;
	queue_pointer link;
};
