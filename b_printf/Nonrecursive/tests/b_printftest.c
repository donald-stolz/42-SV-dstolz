#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "../includes/libftprintf.h"

void	test_printf(void)
{
	int		ccount;
	int		test0;
	int		test1;
	char	test2[] = "print a string";
	char	test3;
	unsigned int	test4;
	unsigned int	test5;
	unsigned int	test6;
	void	*test7;

	test0 = INT_MIN;
	test1 = -0;
	test3 = '%';
	test4 = 10530;
	test5 = 3284947190;
	test6 = 0x7ffe;
	test7 = &test3;
	b_printf("\n");
	b_printf("Test 1:\n");
	b_printf("\n");
	ccount = printf("Standard printf : %d  ", test0);
	printf("Characters Printed: %d \n", ccount);
	ccount = b_printf("My printf       : %d  ", test0);
	printf("Characters Printed: %d \n", ccount);
	ccount = printf("Standard printf : %i  ", test1);
	printf("Characters Printed: %d \n", ccount);
	ccount = b_printf("My printf       : %i  ", test1);
	printf("Characters Printed: %d \n", ccount);
	ccount = printf("Standard printf : %s  ", test2);
	printf("Characters Printed: %d \n", ccount);
	ccount = b_printf("My printf       : %s  ", test2);
	printf("Characters Printed: %d \n", ccount);
	ccount = printf("Standard printf : %c  ", test3);
	printf("Characters Printed: %d \n", ccount);
	ccount = b_printf("My printf       : %c  ", test3);
	printf("Characters Printed: %d \n", ccount);
	ccount = printf("Standard printf : %o  ", test4);
	printf("Characters Printed: %d \n", ccount);
	ccount = b_printf("My printf       : %o  ", test4);
	printf("Characters Printed: %d \n", ccount);
	ccount = printf("Standard printf : %u  ", test5);
	printf("Characters Printed: %d \n", ccount);
	ccount = b_printf("My printf       : %u  ", test5);
	printf("Characters Printed: %d \n", ccount);
	ccount = printf("Standard printf : %x  ", test6);
	printf("Characters Printed: %d \n", ccount);
	ccount = b_printf("My printf       : %x  ", test6);
	printf("Characters Printed: %d \n", ccount);
	ccount = printf("Standard printf : %p  ", test7);
	printf("Characters Printed: %d \n", ccount);
	ccount = b_printf("My printf       : %p  ", test7);
	printf("Characters Printed: %d \n", ccount);
	ccount = printf("Standard printf : %p  ", &test2);
	printf("Characters Printed: %d \n", ccount);
	ccount = b_printf("My printf       : %p  ", &test2);
	printf("Characters Printed: %d \n", ccount);
	printf("Characters Printed: %d \n", ccount);
	//Edge case: b_printf("%");
	printf("Characters Printed: %d \n", ccount);
	ccount = printf("Standard printf : %s  ", NULL);
	printf("Characters Printed: %d \n", ccount);
	ccount = b_printf("My printf       : %s  ", NULL);
	printf("Characters Printed: %d \n", ccount);
	b_printf("\n");
}

void	test_printf2(void)
{
	char s[] = "abcd";

	b_printf("Test 2:\n");
	assert(
		b_printf("hello %c %c %s %s %p bye\n", 'a', 'b', s, s, s) ==
		printf("hello %c %c %s %s %p bye\n", 'a', 'b', s, s, s));
	assert(
		b_printf("%d %d %i %o %o %x %x %u %u\n", INT_MIN, INT_MAX, 123,
			INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, UINT_MAX) ==
		printf("%d %d %i %o %o %x %x %u %u\n", INT_MIN, INT_MAX, 123,
			INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, UINT_MAX));
	b_printf("\n");
}

void	test_printf3(void)
{
	char s[] = "Hello World";

	b_printf("Test 3:\n");
	assert(
		b_printf("%d\n", b_printf("%s %s %c %d %o %u ---- %x %p\n", s, NULL,
			*s, -36363, -99919, 123, -3254, s)) ==
		printf("%d\n", printf("%s %s %c %d %o %u ---- %x %p\n", s, NULL,
			*s, -36363, -99919, 123, -3254, s)));
	b_printf("\n");
}

int	main(void)
{
	test_printf();
	test_printf2();
	test_printf3();
	return (0);
}
