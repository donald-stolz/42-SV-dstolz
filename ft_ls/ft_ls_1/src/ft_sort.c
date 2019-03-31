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

// FIXME: Norminette only allows 4 parameters per function
static t_dir	*ft_partition(t_dir *head, t_dir *tail, t_dir **n_head,
	t_dir **n_tail, t_bool (*cmp)(t_dir, t_dir))
{
	t_dir	*pivot;
	t_dir	*prev;
	t_dir	*cur;

	pivot = tail;
	prev = NULL;
	cur = head;
	while (cur != pivot)
	{
		if ((*cmp)(*cur, *pivot))
			ft_place_left(n_head, &prev, &cur);
		else
			ft_place_right(&tail, &prev, &cur);
	}
	if ((*n_head) == NULL)
		(*n_head) = pivot;
	(*n_tail) = tail;
	return (pivot);
}

static t_dir	*ft_quick_sort(t_dir *head, t_dir *tail,
	t_bool (*cmp)(t_dir, t_dir))
{
	t_dir	*n_head;
	t_dir	*n_tail;
	t_dir	*pivot;
	t_dir	*tmp;

	if (!head || head == tail)
		return (head);
	n_head = NULL;
	n_tail = NULL;
	pivot = ft_partition(head, tail, &n_head, &n_tail, (*cmp));
	if (n_head != pivot)
	{
		tmp = n_head;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		n_head = ft_quick_sort(n_head, tmp, (*cmp));
		tmp = ft_get_tail(n_head);
		tmp->next = pivot;
	}
	pivot->next = ft_quick_sort(pivot->next, n_tail, (*cmp));
	return (n_head);
}

static t_bool	ft_cmp_lex(t_dir a, t_dir b)
{
	return (ft_strcmp(a.name, b.name) < 0);
}

static t_bool	ft_cmp_time(t_dir a, t_dir b)
{
	t_bool cmp;

	cmp = a.m_time.tv_sec == b.m_time.tv_sec;
	if (cmp)
		cmp = a.m_time.tv_nsec > b.m_time.tv_nsec;
	else
		cmp = a.m_time.tv_sec > b.m_time.tv_sec;
	return (cmp);
}

void			ft_sort(t_opt *opts, t_dir **parents)
{
	t_dir	*tail;
	t_bool	(*cmp)(t_dir, t_dir);

	if (!(*parents)->next)
		return ;
	tail = ft_get_tail(*parents);
	cmp = opts->t_op ? &ft_cmp_time : &ft_cmp_lex;
	*parents = ft_quick_sort(*parents, tail, cmp);
	if (opts->r_op)
		ft_rev_list(parents);
}
