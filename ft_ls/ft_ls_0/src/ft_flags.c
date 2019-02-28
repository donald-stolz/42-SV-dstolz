/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 09:12:29 by dstolz            #+#    #+#             */
/*   Updated: 2019/01/21 09:12:31 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void ft_setflags(const char *flags, t_opt *options)
{
	if (*(flags + 1) != '-')
	{
		options->l_op = ft_strchr(flags, 'l') ? true : options->l_op;
		options->a_op = ft_strchr(flags, 'a') ? true : options->a_op;
		options->r_op = ft_strchr(flags, 'r') ? true : options->r_op;
		options->t_op = ft_strchr(flags, 't') ? true : options->t_op;
		options->rec_op = ft_strchr(flags, 'R') ? true : options->rec_op;
		return;
	}
	ft_putstr("ft_ls: illegal option -- - \n");
	exit(1);
}

t_opt *ft_newflags(void)
{
	t_opt *new;

	new = malloc(sizeof(t_opt));
	new->l_op = false;
	new->a_op = false;
	new->r_op = false;
	new->t_op = false;
	new->rec_op = false;
	new->m_arg = false;
	return (new);
}
