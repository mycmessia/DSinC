#include <stdio.h>
#include "one_way_linked_list.h"

int main(void)
{
	list_pointer ptr = NULL;

	insert(&ptr, 10);
	insert(&ptr, 20);

	printf("ptr->data is %d, %d\n", ptr->data, ptr->link->data);

	return 0;
}
