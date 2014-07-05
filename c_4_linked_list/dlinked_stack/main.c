#include <stdio.h>
#include "dlinked_stack.h"

extern stack_pointer top_list[MAX_STACKS];

int main(void)
{
	char str[10] = "revive\0";

	printf("%s is %d palin\n", str, is_palin(str, 6, &top_list[0]));

	return 0;
}
