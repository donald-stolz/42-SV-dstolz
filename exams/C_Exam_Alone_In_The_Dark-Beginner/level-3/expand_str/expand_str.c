#include <unistd.h>

int is_space(char c)
{
	return (c == ' ' || c == '	');
}

void expand_str(char *str)
{
	int i = 0;

	while (str[i] && is_space(str[i]))
		i++;
	while (str[i])
	{
		while (str[i] &&!is_space(str[i]))
			write(1, &str[i++], 1);
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i])
			write(1, "   ", 3);
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
	return 0;
}
