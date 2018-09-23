/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:00:05 by exam              #+#    #+#             */
/*   Updated: 2018/09/21 10:56:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
void ft_putchar(int c);
void ft_putint(int c);

int	main(int argc, char const *argv[])
{
	ft_putint(argc);
	if ((void *)argv == NULL)
		return 0;
	ft_putchar('\n');
	return 0;
}

void ft_putint(int c)
{
	if (c > 0)
	{
		ft_putint(c/10);
		ft_putchar(47 + (c%10));
	}
}

void ft_putchar(int c)
{
	write(1, &c, 1);
}
