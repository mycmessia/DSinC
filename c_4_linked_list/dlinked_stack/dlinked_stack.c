/* dynamic linked stack */
#include <stdio.h>
#include <stdlib.h>
#include "dlinked_stack.h"

stack_pointer top_list[MAX_STACKS];

void add(stack_pointer *top, element item)
{
	stack_pointer temp = (stack_pointer) malloc(sizeof(stack));
	
	if (IS_FULL(temp))
	{
		fprintf(stderr, "The memory is full.\n");
		return;
	}
	
	temp->item = item;
	temp->link = *top;
	*top = temp;
}

element delete(stack_pointer *top)
{
	stack_pointer temp = *top;
	element item = {-1};
	
	if (IS_EMPTY(temp))
	{
		fprintf(stderr, "The stack is empty.\n");
		return item;
	}

	item = temp->item;
	*top = temp->link;
	free(temp);

	return item;
}
