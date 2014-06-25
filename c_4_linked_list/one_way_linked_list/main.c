#include <stdio.h>
#include "one_way_linked_list.h"

int main(void)
{
	list_pointer ptr = NULL;

	insert(&ptr, 10);
	insert(&ptr, 20);
	//insert(&ptr, 30);
	//insert(&ptr, 40);
	//insert(&ptr, 50);

	print_list(ptr);

	printf("length is %d\n", length(ptr));

	interval_delete(&ptr);

	print_list(ptr);

	return 0;
}
