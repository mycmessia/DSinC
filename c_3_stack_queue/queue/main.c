#include <stdio.h>
#include "queue.h"

int main(void)
{
	element e1 = {0};
	addq(e1);
	e1 = deleteq();
	printf("e1.data is %d\n", e1.data);

	return 0;
}
