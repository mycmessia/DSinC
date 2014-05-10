#include <stdio.h>
#include "compare.h"

#define N 5

int a[N] = {1, 2, 3, 4, 5};

int binary_search(int a[], int num, int start, int end)
{
	if (start <= end)
	{
		int mid = (start + end) / 2;

		switch(COMPARE(a[mid], num))
		{
			case 1:
				return binary_search(a, num, start, mid - 1);
			case 0:
				return mid;
			case -1:
				return binary_search(a, num, mid + 1, end);
		}
	}

	return -1;
}

/*void p_arr(int a[], int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}*/

int main(void)
{
	int num = 0;
	
	printf("Please input the number you want to search:\n");
	scanf("%d", &num);

	printf("The numder's index is %d\n", binary_search(a, num, 0, N - 1));

	return 0;
}
