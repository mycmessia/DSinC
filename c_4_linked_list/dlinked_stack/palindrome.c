#include "dlinked_stack.h"

int is_palin(char *str, int len, stack_pointer *top)
{
	int i = 0;
	char c;

	for (; i < len / 2; i++)
	{
		element item = {str[i] - '0'};

		add(top, item);
	}

	if (i % 2) i++;

	while (IS_EMPTY(top))
	{
		c = delete(top).key + '0';
		
		if (c != str[i])
			return 0;
	}

	return 1;
}
