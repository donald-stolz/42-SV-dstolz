/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:09:51 by exam              #+#    #+#             */
/*   Updated: 2018/09/25 09:30:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int ft_putchar(char c);

int ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int main( int argc, char const *argv[])
{
	char *str;
	char s;
	char r;
	int i;

	if (argc !=4)
	{
		ft_putchar('\n');
		return 0;
	}
	str = (char *)argv[2];
	if (*(str + 1))
	{
		ft_putchar('\n');
		return 0;
	}
	str = (char *)argv[1];
	s = (char)*argv[2];
	r = (char)*argv[3];
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == s)
			ft_putchar(r);
		else
			ft_putchar(*(str + i));
		i++;
	}
	ft_putchar('\n');
	return 0;
}
