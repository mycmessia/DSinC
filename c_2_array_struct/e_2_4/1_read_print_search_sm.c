#include "../sparse_matrix.h"
#include <stdio.h>

void read_sm(term a[])
{
	int count = 0;
	int value_max = 0;	
	char answer = 'n';

	printf("Please input the row and col of sm:\n");
	scanf("%d %d", &a[0].row, &a[0].col);

	value_max = a[0].row * a[0].col;

	do {
		count++;		
		if (count == value_max + 1) {
			printf("No more space for more terms.\n");
			return;
		}

		printf("Please input the row, col, value:\n");
		scanf("%d %d %d", &a[count].row, 
				  &a[count].col, &a[count].value);	

		printf("Do you want to input another term?(y/n)\n");
		scanf(" %c", &answer);

	} while (answer == 'y' || answer == 'Y');

	a[0].value = count;
}

void print_sm(term a[])
{
	int i;
	
	printf("row\tcol\tvalue\n");
	for (i = 0; i <= a[0].value; i++) {
		printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
	}
}

void search_sm(term a[], int key, term *res)
{
	int i;

	for (i = 1; i <= a[0].value; i++) {
		if (a[i].value == key) {
			res->row = a[i].row;
			res->col = a[i].col;
			res->value = key;
		}
	}

	res->row = -1; res->col = -1; res->value = -1;
}

/*int main(void)
{
	term a[MAX_TERMS];
	term b[MAX_TERMS];
	
	read_sm(a);
	print_sm(a);

	fast_transpose(a, b);
	print_sm(b);

	return 0;
}*/
