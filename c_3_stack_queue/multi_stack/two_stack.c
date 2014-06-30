#include <stdio.h>
#define MEMORY_SIZE 5

int memory[MEMORY_SIZE];
int top[2], boundary[3];

void init_stacks(void)
{
	top[0] = -1;
	boundary[0] = top[0];
	
	top[1] = MEMORY_SIZE / 2;
	boundary[1] = top[1];

	boundary[2] = MEMORY_SIZE - 1;
}

int stack_full(int stack_no)
{
	int i;

	if (stack_no == 1)
	{
		if (top[0] == boundary[1])
		{
			fprintf(stderr, "All memory is full.\n");
			return 1;
		}

		for (i = boundary[1]; i < top[1]; i++)
			memory[i] = memory[i + 1];

		boundary[1]--;
		top[1]--;
	}
	else
	{
		if (top[1] == boundary[2])
		{
			fprintf(stderr, "All memory is full.\n");
			return 1;
		}

		for (i = top[1]; i > boundary[1]; i--)
			memory[i + 1] = memory[i];
		
		boundary[1]++;
		top[1]++;
	}

	return 0;
}

void add(int stack_no, int n)
{
	if (top[stack_no] == boundary[stack_no + 1])
		if (stack_full(stack_no)) return;

	memory[++top[stack_no]] = n;
}

int main(void)
{
	init_stacks();

	add(1, 5);
	add(1, 4);
	add(1, 3);
	add(1, 2);
	add(1, 1);
	add(1, 0);

	printf("top[0] %d, boundary[0] %d, top[1] %d, boundary[1] %d\n",
		top[0], boundary[0], top[1], boundary[1]);

	return 0;
}
