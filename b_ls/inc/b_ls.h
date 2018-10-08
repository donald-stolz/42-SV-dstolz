/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 09:53:01 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/02 09:53:03 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LS_H
# define B_LS_H

# include "libft.h"
# include "macros.h"
# include <dirent.h>
# include <sys/types.h>
# include <errno.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } t_bool;

typedef struct	s_opt
{
	t_bool	l_op;
	t_bool	a_op;
	t_bool	r_op;
	t_bool	t_op;
}				t_opt;

// typedef struct	s_file
// {

// }				t_file;

// typedef struct	s_dir
// {
// 	t_file	*files;
// 	t_dir	*dirs;
// }				t_dir;

char **ft_getdirnames(int argc, const char **argv, int numdirs);
t_opt *ft_setflags(const char *flags);
#endif
