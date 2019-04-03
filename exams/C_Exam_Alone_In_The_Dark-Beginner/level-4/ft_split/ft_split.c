#include <stdlib.h>
#include <stdio.h>

int is_space(char c)
{
	return (c == ' '|| c == '\t' || c == '\v' || c == '\n');
}

int count_words(char *str)
{
	int i = 0;

	while(*str)
	{
		if(!is_space(*str))
		{
			while(!is_space(*str))
				str++;
			i++;
		}
		str++;
	}
	return i;
}

int word_len(char *str)
{
	int i = 0;

	while(*(str + i) && !is_space(*(str + i)))
		i++;
	return i;
}

char **ft_split(char *str)
{
	char **result;
	int len;
	int q = 0;
	int i = 0;

	result = malloc(sizeof(char *) * (count_words(str) + 1));
	while (*str)
	{
		if(!is_space(*str))
		{
			len = word_len(str);
			result[q] = malloc(sizeof(char) * (len + 1));
			result[q][len + 1] = '\0';
			while(*(str + i) && !is_space(*(str + i)))
				{result[q][i] = *(str + i);
				i++;
				}
			while (!is_space(*str ))
				str++;
			i = 0;
			q++;
		}
		str++;
	}
	result[q] = NULL;
	return result;
}

int main(void)
{
	char **split;
	int i = 0;

	split = ft_split("RVc6, hello world");
	while(split[i]){
		printf("%s\n", split[i++]);
	}
	
	return 0;
}