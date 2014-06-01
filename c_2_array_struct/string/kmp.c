#include <stdio.h>
#include <string.h>

void fail(char *pat, int failure[])
{
	int i,j;
	int n = strlen(pat);
	
	failure[0] = -1;

	for (j = 1; j < n; j++)
	{
		/* calc failure[j] */
		i = failure[j - 1];

		while (pat[i + 1] != j && i >= 0)
			i = failure[i];

		if (pat[i + 1] == pat[j])
			failure[j] = i + 1;
		else
			failure[j] = i;
		printf("%d ", failure[j]);
	}
	printf("\n");
}

int kmp(char *str, char *pat, int failure[])
{
	int i = 0, j = 0;
	int lens = strlen(str);
	int lenp = strlen(pat);

	while (i < lens && j < lenp)
	{
		if (str[i] == pat[j])
		{
			i++; j++;
		}
		else if (j == 0) 
			i++;
		else
		{
			j = failure[j - 1] + 1;
		}
	}

	return ((j == lenp) ? (i - lenp) : -1);
}
