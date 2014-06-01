#include <stdio.h>
#include <string.h>
#include "string.h"
#include "kmp.h"

extern char string1[MAX_SIZE], string2[MAX_SIZE];

int main(void)
{
	printf("please input two string divided by a space:\n");
	scanf("%s %s", string1, string2);

	strnins(string1, string2, 2);

	printf("%s\n", string1);

	int failure[8];
	int res = -1;

	//fail(string2, failure);
	//res = kmp(string1, string2, failure);
	res = strsearch(string1, string2);
	if (res == -1)
		printf("Don't find %s in the %s\n", string2, string1);
	else
		printf("Find %s in the %d of %s\n", string2, res, string1);

	return 0;
}
