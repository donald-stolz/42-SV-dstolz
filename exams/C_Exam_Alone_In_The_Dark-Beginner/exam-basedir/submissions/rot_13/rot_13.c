#include <unistd.h>

void print_rot(char c)
{
	if( (c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		c += 13;
	else if (( c >= 'N' && c <= 'Z') || ( c >= 'n' && c <= 'z'))
		c -= 13;
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
			print_rot(argv[1][i++]);
	}
	write(1, "\n", 1);
	return 0;
}
