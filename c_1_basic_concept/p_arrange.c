#include <stdio.h>
#include "swap.h"

#define N 3

int arr[N] = {1, 2, 3};

void p_arrange(int arr[], int length, int now)
{
	int i = 0;
	int t = 0;

	if (now == length - 1)
	{
		for (i = 0; i < length; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else
	{
		for (i = now; i < length; i++)
		{
			SWAP(arr[now], arr[i], t);
			p_arrange(arr, length, now + 1);
			SWAP(arr[i], arr[now], t);
		}
	}
}

int main(void)
{
	p_arrange(arr, N, 0);

	return 0;
}
