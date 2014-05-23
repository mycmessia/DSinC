#include <stdio.h>
#define MAX 100

void p_bool(int a[], int i, int max)
{
	if (i == max)
	{	
		int j;

		printf("<");
		for (j = 0; j < max; j++)
		{
			if (a[j])
			{
				printf("true");
				if (j < max-1)
					printf(", ");
			}
			else
			{
				printf("false");
				if (j < max-1)
					printf(", ");
			}
		}
		printf(">\n");
	}
	else
	{
		a[i] = 0;
		p_bool(a, i+1, max);
		a[i] = 1;
		p_bool(a, i+1, max);
	}
}

int main(void)
{
	int n;
	int a[MAX];

	scanf("%d", &n);

	p_bool(a, 0, n);

	return 0;
}
