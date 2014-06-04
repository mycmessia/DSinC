#include <stdio.h>
#include "stack.h"

int main(void)
{
	element e1 = {11}, e2 = {22};
	
	add(&e1);
	add(&e2);
	delete();
	print_stack();

	return 0;
}
