#include <stdio.h>
#include <limits.h>
#include "../libprintf.h"

void test_printf();

void test_printf()
{
	int	testReturn;
	int test0, test1;
	char test2[] = "print a string";
	char test3;
	t_uint test4, test5, test6;
	void *test7;

	test0 = INT_MIN;
	test1 = INT_MAX;
	test3 = '%';
	test4 = 10530;
	test5 = 3284947190;
	test6 = 0x7ffe;
	test7 = &test3;

	b_printf("Tests :\n");
	b_printf("\n");

	testReturn = printf("Standard printf : %d  ", test0);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = b_printf("My printf       : %d  ", test0);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = printf("Standard printf : %i  ", test1);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = b_printf("My printf       : %i  ", test1);
	printf("Characters Printed: %d \n", testReturn);
	b_printf("\n");

	testReturn = printf("Standard printf : %s  ", test2);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = b_printf("My printf       : %s  ", test2);
	printf("Characters Printed: %d \n", testReturn);
	b_printf("\n");

	testReturn = printf("Standard printf : %c  ", test3);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = b_printf("My printf       : %c  ", test3);
	printf("Characters Printed: %d \n", testReturn);
	b_printf("\n");

	testReturn = printf("Standard printf : %o  ", test4);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = b_printf("My printf       : %o  ", test4);
	printf("Characters Printed: %d \n", testReturn);
	b_printf("\n");

	testReturn = printf("Standard printf : %u  ", test5);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = b_printf("My printf       : %u  ", test5);
	printf("Characters Printed: %d \n", testReturn);
	b_printf("\n");

	testReturn = printf("Standard printf : %x  ", test6);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = b_printf("My printf       : %x  ", test6);
	printf("Characters Printed: %d \n", testReturn);
	b_printf("\n");

	testReturn = printf("Standard printf : %p  ", test7);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = b_printf("My printf       : %p  ", test7);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = printf("Standard printf : %p  ", &test2);
	printf("Characters Printed: %d \n", testReturn);
	testReturn = b_printf("My printf       : %p  ", &test2);
	printf("Characters Printed: %d \n", testReturn);
	b_printf("\n");

	testReturn = printf("Standard printf : %%  ");
	printf("Characters Printed: %d \n", testReturn);
	testReturn = b_printf("My printf       : %%  ");
	printf("Characters Printed: %d \n", testReturn);

}

int main() {
	test_printf();
	return 0;
}
