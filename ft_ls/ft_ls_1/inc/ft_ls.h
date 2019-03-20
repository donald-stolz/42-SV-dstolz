/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 09:53:01 by dstolz            #+#    #+#             */
/*   Updated: 2018/11/09 09:46:38 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "b_printf.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <stdlib.h>

typedef enum
{
	false,
	true
}	t_bool;

typedef struct	s_opt
{
	t_bool	l_op: 1;
	t_bool	a_op: 1;
	t_bool	r_op: 1;
	t_bool	t_op: 1;
	t_bool	rec_op: 1;
}				t_opt;

typedef struct	s_dir
{
	char				*name;
	t_bool				is_dir;
	// is_link?
	size_t				total;
	char				*permissions;
	nlink_t				links;
	char				*owner;
	char				*group;
	off_t				size;
	struct timespec		mtime;
	struct s_dir		*children;
	struct s_dir		*previous;
	struct s_dir		*next;
}				t_dir;

 
#endif
