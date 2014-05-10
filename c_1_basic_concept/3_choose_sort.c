#include <swap.h>

void choose_sort(int list[], int n)
{
	int i = 0, j = 0, min = 0, t = 0;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < min)
			{
				min = j;
			}
		}
		SWAP(list[i], list[min], t)
	}
}
