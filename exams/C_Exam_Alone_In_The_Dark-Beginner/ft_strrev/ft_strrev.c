
char *ft_strrev(char *str)
{
	char temp;
	int i = 0;
	int q = 0;

	while(str[q])
		q++;
	q--;
	while (i < q)
	{	
		temp = *(str + i);
		*(str + i) = *(str + q);
		*(str + q) = temp;
		i++;
		q--;
	}
	return str;
}
