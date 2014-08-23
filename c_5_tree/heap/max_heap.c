#include <stdio.h>
#include "max_heap.h"

element heap[MAX_ELEMENTS];
int n;

/**
 * insert item into a max heap of current size *n
 * use array to save max heap for the reason that max heap
 * is a complete binary tree and can find parent node
 * easily without use another space
 */
void insert_max_heap(element item, int *n)
{
	int i;
	if (HEAP_FULL(*n))
	{
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}

	i = ++(*n);
	while (i != 1 && item.key > heap[i / 2].key)
	{
		heap[i] = heap[i / 2];
		i = i / 2;
	}
	heap[i] = item;
}

/* delete element with the highest key from the heap */
void delete_max_heap(int *n)
{
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(*n))
	{
		fprintf(stderr, "The heap is empty, delete failed.\n");
		exit(1);
	}
	/* save value of the element with the highest key for return at the end*/
	item = heap[1];
	/* use last element in heap to adjust the heap */
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	
	while (child <= *n)
	{
		/* find the larger child of the current parent */
		if (child < *n && heap[child].key < heap[child + 1].key)
			child++;
		if (temp.key > heap[child].key)	break;
		/* move to the next lower level */
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}
