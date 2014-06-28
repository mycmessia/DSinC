#include <stdio.h>
#include "one_way_linked_list.h"

int main(void)
{
	list_pointer ptr1 = NULL;
	list_pointer ptr2 = NULL;

	insert(&ptr1, 50);
	insert(&ptr1, 30);
	insert(&ptr1, 10);

	insert(&ptr2, 60);
	insert(&ptr2, 40);
	insert(&ptr2, 20);

	list_pointer ptr3 = NULL;

	merge_list(&ptr1, &ptr2, &ptr3);

	ptr1 = NULL;
	ptr2 = NULL;

	print_list(ptr3);

	return 0;
}
