/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:35:27 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/19 09:35:30 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void ft_partition_a(t_dir *tail, t_dir *head)
{
	// TODO: Sort partition
	t_dir 
}

void ft_quick_sort(t_dir *tail, t_dir *head, t_bool t_sort)
{
	t_dir *partition;
	if (head && head != tail && tail != head->next) {
		partition = t_sort ? ft_partition_t(head, tail) 
							: ft_partition_a(head, tail);
		ft_quick_sort(tail, partition->previous, t_sort);
		ft_quick_sort(partition->next, head, t_sort);
	}
	
}

void ft_sort(t_opt *options, t_dir *parents)
{
	t_dir tail;
	tail = ft_get_tail(parents)
	ft_quick_sort(tail, parents, options->t_op)
	if (options->r_op)
		ft_reverse_list(parents);
	if (parents->children)
		ft_sort(options, parents->children);	
}