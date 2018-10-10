#include <unistd.h>
#include <stdio.h>

//Seg faults when no argument specified
int main(int argc, const char *argv[])
{
	int i;

	i = 0;
	while (*(*(argv + 1) + i))
		i++;
	while (i > 0 && argc == 2)
		write(1, (argv[1] + --i),1);
	write(1, "\n", 1);
	return (0);
}
