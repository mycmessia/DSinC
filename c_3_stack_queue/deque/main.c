#include "deque.h"

int main(void)
{
	extern double_ended_queue deque;
	deque.length = 0;
	deque.head = 0;
	deque.rear = -1;
	pde pdeque = &deque;

	element e1 = {1}, e2 = {2}, e3 = {3};

	push(pdeque, e1);
	//push(pdeque, e2);
	//pop(pdeque);

	//print_deque(pdeque);

	unshift(pdeque, e1);
	//unshift(pdeque, e2);
	//shift(pdeque);

	push(pdeque, e3);

	print_deque(pdeque);

	return 0;
}
