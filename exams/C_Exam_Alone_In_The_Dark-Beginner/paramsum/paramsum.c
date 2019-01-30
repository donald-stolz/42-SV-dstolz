#include <unistd.h>
#include <stdio.h>
int numlen(int num)
{
	int i = 0;
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return i;
}

void writeItoa(int num)
{
	long rev = 0;
	int check = num;
	char c;
	while(num > 0)
	{
		rev = rev * 10 + (num % 10);
		num /= 10;
	}
	while (rev > 0)
	{
		c = rev % 10 + '0';
		rev /= 10;
		write(1, &c, 1);	
	}
	if (check % 10 == 0)
		write(1, "0", 1);
	if (check % 100 == 0)
		write(1, "0", 1);
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 1 && argv)
		write(1, "0\n", 2);
	else
		writeItoa( (argc-1));
	return 0;
}
