/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:11:10 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/19 12:11:13 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_swap_dir(t_dir *a, t_dir *b)
{
	t_dir *temp;

	temp->next = a->next;
	a->next = b->next;
	b->next = temp->next;
	if (a->next)
		a->next->previous = a;
	if (b->next)
		b->next->previous = b;
	temp->previous = a->previous;
	a->previous = b->previous;
	b->previous = temp->previous;
	if (a->previous)
		a->previous->next = a;
	if (b->previous)
		b->previous->next = b;
}

