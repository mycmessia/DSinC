/* print a b c from small to big */
#include <stdio.h>

int a, b, c;

void p_num(int a, int b, int c)
{
	int arr[3] = {a, -1, -1};

	if (b >= arr[0])
		arr[1] = b;
	else
	{
		arr[1] = a;
		arr[0] = b;
	}

	if (c >= arr[0])
	{
		if (c >= arr[1])
			arr[2] = c;
		else
		{
			arr[2] = arr[1];
			arr[1] = c;
		}
	}
	else
	{
		arr[2] = arr[1];
		arr[1] = arr[0];
		arr[0] = c;
	}

	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
}

void p_num_web(int a, int b, int c)
{
	int t = 0;

	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}

	if (a > c)
	{
		t = a;
		a = c;
		c = t;
	}

	if (b > c)
	{
		t = b;
		b = c;
		c = t;
	}

	printf("%d %d %d\n", a, b, c);
}

int main(void)
{
	scanf("%d %d %d", &a, &b, &c);

	p_num_web(a, b, c);		

	return 0;
}
