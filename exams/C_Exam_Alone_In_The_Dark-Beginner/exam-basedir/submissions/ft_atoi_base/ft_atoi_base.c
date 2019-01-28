int convert_num(char c, int base)
{
	int result;
	if (c >= '0' && c <= '9')
		result = c - '0';
	else if (c >= 'a' && c <= 'f')
		result = c - 'a' + 10;
	else if (c >= 'A' && c <= 'F')
		result = c - 'A' + 10;
	else
		return -1;
	return result < base ? result : -1;
}

int ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;

	result = 0;
	if (*str == '\0')
		return (0);
	while (*str <= 32)
		str++;
	sign = *str == '-' ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : 0;
	while (convert_num(*str, str_base) > 0)
		result = result * str_base + convert_num(*str++, str_base);
	return (result * sign);
}
