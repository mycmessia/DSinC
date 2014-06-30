#include "multi_stack.h"

element memory[MEMORY_SIZE];
int top[MAX_STACKS];
int boundary[MAX_STACKS];
int n;	/* number of stacks entered by user */

void init_memory(int n)
{
	top[0] = boundary[0] = -1;
	for (i = 1; i < n; i++)
		top[i] = boundary[i] = i * (MEMORY_SIZE / n);
	/* for top[n - 1] == boundary[n], the stack is full */
	boundary[n] = MEMORY_SIZE - 1;
}

void add(int i, element item)
{
	if (top[i] == boundary[i + 1])
	{
		if (stack_full(i))
		{
			fprintf(stderr, "All the memory is used.\n");
			return;
		}
	}

	memory[++top[i]] = item;
}

element delete(int i)
{
	if (top[i] == boundary[i])
		return stack_empty(i);
	return memory[top[i]--];
}

/* if the memory have space then any stack can add */
int stack_full(int stack_no)
{
	/* search the right of stack i in memory*/
	int i = stack_no + 1, j, k;
	int nr = -1, nl = -1;

	for (; i < nr; i++)
		if (top[i] != boundary[i + 1]) 
		{
			nr = i;
			break;
		}

	if (nr != -1)
	{
		j = top[nr]; 
		while (j > top[stack_no])
		{
			memory[j + 1] = j;
			j--;
		}
		return 0;
	}
	else
	{
		/* search left */
		j = stack_no - 1;
		for (; j >= 0; j--)
			if (top[j] != boundary[j + 1])
			{
				nl = j;
				break;
			}

		if (nl != -1)
		{
			k = boundary[nl + 1];
			while (k < boundary[stack_no])
			{
				memory[k] = memory[k + 1];
				k++;
			}
			return 0;
		}		
		return 1;
	}
}
