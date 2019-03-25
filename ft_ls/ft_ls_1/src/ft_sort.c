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

static t_dir	*ft_partition_lex(t_dir *tail, t_dir *head)
{
	t_dir	*nav;
	t_bool	cmp;

	nav = head;
	while(nav && nav != tail && nav != head)
	{
		cmp = ft_strcmp(tail->name, nav->name) > 0;
		nav = nav->next;
		if (cmp)
			ft_place_right(tail, nav->previous);
		else
			ft_place_left(tail, nav->previous);
	}
	return (tail);
}

static void	ft_quick_sort_lex(t_dir *tail, t_dir *head)
{
	t_dir	*partition;

	if (head && head != tail && tail != head->next) {
		partition = ft_partition_lex(head, tail);
		ft_quick_sort_lex(tail, partition->previous);
		ft_quick_sort_lex(partition->next, head);
	}
}

static t_dir	*ft_partition_time(t_dir *tail, t_dir *head)
{
	t_dir *nav;
	t_bool cmp;

	nav = head;
	while (nav && nav != tail && nav != head)
	{
		cmp = tail->m_time.tv_sec == nav->m_time.tv_sec;
		if (cmp)
			cmp = tail->m_time.tv_nsec > nav->m_time.tv_nsec
		else
			cmp = tail->m_time.tv_sec > nav->m_time.tv_sec;
		nav = nav->next;
		if (cmp)
			ft_place_right(tail, nav->previous);
		else
			ft_place_left(tail, nav->previous);
	}
	return (tail);
}

static void		ft_quick_sort_time(t_dir *tail, t_dir *head)
{
	t_dir	*partition;

	if (head && head != tail && tail != head->next) {
		partition = ft_partition_time(head, tail);
		ft_quick_sort_time(tail, partition->previous);
		ft_quick_sort_time(partition->next, head);
	}
}

void			ft_sort(t_opt *opts, t_dir *parents)
{
	t_dir *head;
	t_dir *tail;

	head = ft_get_head(parents);
	tail = ft_get_tail(parents);
	if (opts->t_op)
		ft_quick_sort_time(tail, head);
	else
		ft_quick_sort_lex(tail, head);
	if (opts->r_op)
		ft_rev_dirs(parents);
	if (opts->rec_op && parents->is_dir)
		ft_sort(opts, parents->children);
	parents = parents->next;
}
