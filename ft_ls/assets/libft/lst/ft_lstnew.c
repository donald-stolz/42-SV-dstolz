/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:39:07 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/03 16:39:09 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content_size = 0;
		lst->content = NULL;
	}
	else
	{
		lst->content_size = content_size;
		lst->content = malloc(lst->content_size);
		if (!lst->content)
		{
			free((void *)content);
			return (NULL);
		}
		lst->content = ft_memcpy(lst->content, content, lst->content_size);
	}
	lst->next = NULL;
	return (lst);
}
