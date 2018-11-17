#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int ft_matches(char c, char *str)
{
	int q;

	q = 0;
	while (*(str + q))
	{
		if (c == *(str + q))
			return (1);
		q++;
	}
	*(str + q) = c;
	return (0);
}

int main(int argc, const char *argv[])
{
	char *characters;
	int i;

	characters = (char *)malloc(sizeof(char) * (127 -33));
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (*(*(argv + 1) + i))
	{
		if (!ft_matches((*(*(argv + 1) + i)), characters))
			write(1, &(*(*(argv + 1) + i)), 1);
		i++;
	}
	i = 0;
	while (*(*(argv + 2) + i))
	{
		if (!ft_matches((*(*(argv + 2) + i)), characters))
			write(1, &(*(*(argv + 2) + i)), 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
