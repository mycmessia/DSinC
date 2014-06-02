#include "queue.h"

int main(void)
{
	element e1 = {1}, e2 = {2}, e3 = {3};

	/*unshift(e3);
	unshift(e2);
	unshift(e1);
	pop();
	pop();
	pop();*/
	
	push(e1);
	push(e2);
	push(e3);
	p_de_queue();
	shift();
	p_de_queue();
	shift();
	p_de_queue();
	shift();
	p_de_queue();

	return 0;
}
