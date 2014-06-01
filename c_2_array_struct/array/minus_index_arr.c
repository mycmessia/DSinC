#include <stdio.h>

int main(void)
{
	int a[5] = {0};
	int *p = &a[2];
	int i;

	for (i = -2; i <= 2; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");

	int b[5][5] = {
		{2, 2, 2, 2, 2},
		{1, 1, 1, 1, 1},
		{3, 3, 3, 3, 3},
		{1, 1, 1, 1, 1},
		{5, 5, 5, 5, 5}
	};
	p = &b[2][2];
	int j;

	for (i = -2; i <= 2; i++)
	{
		for (j = -2; j <= 2; j++)
		{
			printf("%d ", *(p + i * 5 + j));
		}
		printf("\n");
	}

	return 0;
}
