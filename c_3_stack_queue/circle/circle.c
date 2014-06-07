#include <stdio.h>
#define MAX_SIZE 4

int front = -1;
int rear = -1;
int circle[MAX_SIZE];

void is_full(void)
{
	printf("circle is full, ninsert failed.\n");
	return;
}

int is_empty(void)
{
	printf("circle is empty, ndelete failed.\n");
	return -1;
}

int length()
{
	if (rear > front)
		return rear - front;
	else if (rear < front)
		return rear + MAX_SIZE - front;
	return 0;
}

void ninsert(int pos, int num)
{
	if (pos < 0 || pos >= MAX_SIZE || pos > length())
	{
		printf("pos is invaild, %s failed.\n", __FUNCTION__);
		return;
	}

	if (length() == MAX_SIZE)
	{
		return is_full();
	}

	int i = rear, j, count = length() - pos;

	while (count > 0)
	{
		j = (i + 1) % MAX_SIZE;
		circle[j] = circle[i];
		i = (i - 1 + MAX_SIZE) % MAX_SIZE;
		
		count--;
	}

	rear = (rear + 1) % MAX_SIZE;
	circle[pos] = num;
}

int ndelete(int pos)
{
	if (pos < 0 || pos >= MAX_SIZE || pos >= length())
	{
		printf("pos is invaild, %s failed.\n", __FUNCTION__);
	}

	if (length() == 0)
		return is_empty();

	int i = pos, j, count = length() - pos;
	int res = circle[pos];

	while (count > 0)
	{
		j = (i + 1) % MAX_SIZE;
		circle[i] = circle[j];
		i = (i + 1) % MAX_SIZE;

		count--;
	}

	rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;

	return res;
}

void print_circle(void)
{
	int n = length();
	int i = front;

	while (n > 0)
	{
		i = (i + 1) % MAX_SIZE;
		printf("%d ", circle[i]);
		n--;
	}

	printf("\n");
}

int main(void)
{
	ninsert(0, 0);
	ninsert(1, 1);
	ninsert(2, 2);
	ndelete(-1);
	print_circle();
	//printf("front = %d, rear = %d, length = %d\n", front, rear, length());

	return 0;
}
