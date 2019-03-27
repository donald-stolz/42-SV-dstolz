/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:34:04 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/27 11:34:05 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_place_left(t_dir **head, t_dir **prev, t_dir **cur)
{
	if ((*head) == NULL)
		(*head) = *cur;
	*prev = *cur;
	*cur = (*cur)->next;
}

void	ft_place_right(t_dir **tail, t_dir **prev, t_dir **cur)
{
	t_dir	*tmp;

	if (*prev)
		(*prev)->next = (*cur)->next;
	tmp = (*cur)->next;
	(*cur)->next = NULL;
	(*tail)->next = (*cur);
	(*tail) = (*cur);
	(*cur) = tmp;
}
