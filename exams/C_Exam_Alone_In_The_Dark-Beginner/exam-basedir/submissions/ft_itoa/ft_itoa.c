#include <stdlib.h>

void ft_strrev(char *str)
{
	int i = 0;
	int q = 0;
	char temp;
	while (*(str + q))
		q++;
	q--;
	while (i < q)
	{
		temp = *(str + i);
		*(str + i++) = *(str + q);
		*(str + q--) = temp;
	}
}

unsigned int ft_numlen(int nbr)
{
	unsigned int i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return i;
}

char *ft_itoa(int nbr)
{
	long long num = nbr;
	int i = 0;
	int sign = nbr > 0 ? 1 : -1;
	char *str;

	num = sign > 0 ? num : -num;
	str = (char *)malloc(ft_numlen(nbr) + 1);
	if (nbr == 0)
		*(str + i) = '0';
	while (num != 0)
	{
		*(str + i++) = num % 10 + '0';
		num /= 10;
	}
	if (sign < 0)
		*(str + i++) = '-';
	*(str + i++) = '\0';
	ft_strrev(str);
	return str;
}
