/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 09:59:12 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/27 17:45:23 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	if (dstsize < dst_len + 1)
		return (src_len + dstsize);
	else if (dstsize > dst_len + 1)
	{
		while (i < dstsize - 1)
			*(dst + i++) = *(src + j++);
		*(dst + i) = '\0';
	}
	return (dst_len + src_len);
}
