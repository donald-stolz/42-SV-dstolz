/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:02:46 by exam              #+#    #+#             */
/*   Updated: 2018/09/21 11:48:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

char ft_toupper(char c);
char ft_tolower(char c);
void ft_putchar(int c);

char ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int main(int argc, char const *argv[])
{
	int i;
	int q;

	i = 0;
	q = 0;
	if (argc == 1)
	{
		ft_putchar('\n');
		return 0;
	}
	while (i++ < (argc - 1))
	{
		while (*(argv[i] + q))
		{
			if (*((char *)argv[i] + (q + 1)) == ' ' || *((char *)argv[i] + (q + 1)) == '\0' || *((char *)argv[i] + (q + 1)) == '\n')
				ft_putchar(ft_toupper(*((char *)argv[i] + q)));
			else
				ft_putchar(ft_tolower(*((char *)argv[i] + q)));
			q++;
		}
		q = 0;
		ft_putchar('\n');
	}
	return 0;
}


