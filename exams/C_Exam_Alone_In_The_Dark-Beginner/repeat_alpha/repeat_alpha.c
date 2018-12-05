#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int q;
	if (argc == 2)
	{
		q = 0;
		while(argv[1][q])
		{ 
			if (argv[1][q] > 'A' && argv[1][q] < 'Z')
				i = argv[1][q] - 'A';
			else if (argv[1][q] > 'a' && argv[1][q] < 'z')
				i = argv[1][q] - 'a';
			else
				i = 0;
			i++;			
			while (i > 0)
			{
				write(1, &argv[1][q], 1);
				i--;
			}
			q++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
