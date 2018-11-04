/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:40:51 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/19 19:14:31 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (((int *)dst > (int *)src && (int *)src + len > (int *)dst))
	{
		while (len > 0)
		{
			len--;
			*((char *)dst + len) = *((char *)src + len);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
