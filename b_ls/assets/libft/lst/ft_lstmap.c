/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:38:45 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/03 16:38:47 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list *curr;
	t_list *tail;
	t_list *head;

	if (!lst)
		return (NULL);
	while (lst)
	{
		tail = malloc(sizeof(t_list));
		if (!tail)
			return (NULL);
		tail = f(lst);
		if (!head)
		{
			head = tail;
			curr = tail;
		}
		else
		{
			curr->next = tail;
			curr = tail;
		}
		lst = lst->next;
	}
	return (head);
}
