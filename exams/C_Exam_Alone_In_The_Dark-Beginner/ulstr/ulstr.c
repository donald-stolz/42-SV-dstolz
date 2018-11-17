#include <unistd.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i;
	char tmp;

	i = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*(*(argv + 1) + i))
	{
		if (*(*(argv + 1) + i) >= 'A' && *(*(argv + 1) + i) <='Z')
			tmp = (*(*(argv + 1) + i) + 32 );
		else if (*(*(argv + 1) + i) >= 'a' && *(*(argv + 1) + i) <= 'z')
			tmp = (*(*(argv + 1) + i) - 32);
		else
			tmp = *(*(argv + 1) + i);
		write(1, &tmp, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
