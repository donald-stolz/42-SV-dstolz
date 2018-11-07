/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 13:57:03 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 13:57:21 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memalloc(size_t size)
{
	char	*p;
	void	*ptr;

	MALLCHECK((ptr = malloc(size)));
	p = (char *)ptr;
	while (size-- > 0)
		*p++ = 0;
	return (ptr);
}
