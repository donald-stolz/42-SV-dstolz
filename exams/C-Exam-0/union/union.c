/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:36:23 by exam              #+#    #+#             */
/*   Updated: 2018/09/25 10:07:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c);
int ft_wasprinted(char c, char *printed);

int ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int ft_wasprinted(char c, char *printed)
{
	while (*printed)
		if (c == *printed++)
			return 1;
	return 0;
}

int main(int argc, const char *argv[])
{
	char printed[95];
	int i;

	i = 0;
	if (argc != 3)
	{
		ft_putchar('\n');
		return 0;
	}
	while (*(argv[1]))
		if (ft_wasprinted(*argv[1], printed))
				argv[1]++;
		else
		{
			printed[i++] = *argv[1];
			argv[1] += ft_putchar(*argv[1]);
		}
	while (*(argv[2]))
		if (ft_wasprinted(*argv[2], printed))
			argv[2]++;
		else
		{
			printed[i++] = *argv[2];
			argv[2] += ft_putchar(*argv[2]);
		}
	ft_putchar('\n');
	return 0;
}
