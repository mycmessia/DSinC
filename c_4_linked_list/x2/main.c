#include "x2.h"

extern x2_pointer front;

int main(void)
{
	add_front(3);
	add_front(2);
	add_front(1);

	add_rear(4);
	add_rear(5);
	add_rear(6);

	delete();

	print_x2(front);

	return 0;
}
