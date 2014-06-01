#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

char string1[MAX_SIZE], *s = string1;
char string2[MAX_SIZE], *t = string2;

int strnins(char s[], char t[], int i)
{
	/* here must init temp by \0 to make the strcat right */
	char temp[MAX_SIZE] = {'\0'};

	if (i < 0 && i > strlen(s))
	{	
		fprintf(stderr, "Position is out of bounds.\n");
		exit(1);
	}

	if (!strlen(s))
		strcpy(s, t);
	else
	{
		strncpy(temp, s, i);
		//printf("%s\n", temp); I find the bug in line 11 by this
		strcat(temp, t);
		//printf("%s\n", temp);
		strcat(temp, (s + i));
		//printf("%s\n", temp);
		strcpy(s, temp);
	}

	return 0;
}

/* Not use the temp */
void strnins2(char s[], char t[], int pos)
{
	int lent = strlen(t);
	int lens = strlen(s);
	int i = 1;

	while (i <= lent)
	{
		s[lens + lent - i] = s[lens - i];
		s[lens - i] = t[lent - i];
		i++;
	}
}

int strsearch(char *s, char *p)
{
	int lens = strlen(s);
	int lenp = strlen(p);
	int i = 0, j = 0;

	while (i < lens && j < lenp)
	{
		if (s[i] == p[j])
		{
			i++; j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}

	return ((j == lenp) ? i - lenp : -1);
}
