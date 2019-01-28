#include <stdlib.h>

char *ft_strdup(const char *s1)
{
	char *s2;
	int i;

	i = 0;
	while (*(s1 + i))
		i++;
	s2 = malloc(i + 1);
	i = 0;
	while (*s1)
		*(s2 + i++) = *s1++;
	return s2;
}
