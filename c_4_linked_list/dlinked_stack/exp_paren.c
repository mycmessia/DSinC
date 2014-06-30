/* check if parentheses in a exp is in pair */
#include "dlinked_stack.h"

int is_in_pair(char *exp, int len, stack_pointer *top)
{
	int i = 0;
	for (; i < len; i++)
	{
		if (exp[i] == '(')
		{
			element item = {1};
			add(top, item);
		}
		else if (exp[i] == ')')
		{
			delete(top);
		}
	}

	if (IS_EMPTY(top))
		return 1;
	else
		return 0;
}
