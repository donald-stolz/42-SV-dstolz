/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_strrev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 11:58:08 by dstolz            #+#    #+#             */
/*   Updated: 2019/01/20 11:58:10 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_printf.h"

char	*b_strrev(char *str)
{
	int		i;
	int		q;
	char	temp;

	i = 0;
	q = b_strlen(str) - 1;
	while (i < q)
	{
		temp = *(str + i);
		*(str + i++) = *(str + q);
		*(str + q--) = temp;
	}
	return (str);
}
