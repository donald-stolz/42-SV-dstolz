#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int x;
	int y;
	char op;
	long long res; 
	int check = 0;

	if(argc == 4)
	{
		op = argv[2][0];
		x = atoi(argv[1]);
		y = atoi(argv[3]);
		if(op == '+')
		{
			res = x + y;
			check = 1;
		}
		else if(op == '-')
		{
			res = x - y;
			check = 1;
		}
		else if(op == '*')
		{
			res = x * y;
			check = 1;
		}
		else if(op == '/')
		{
			res = x / y;
			check = 1;
		}
		if(check == 1)
			printf("%lld", res);
	}
	printf("\n");
	return 0;
}
