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

# define A_OP(str, a) (*(str) != '.' || a)

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
	char				*path;
	t_bool				is_dir;
	size_t				total;
	char				*permissions;
	nlink_t				links;
	char				*owner;
	char				*group;
	off_t				size;
	struct timespec		m_time;
	struct s_dir		*children;
	struct s_dir		*previous;
	struct s_dir		*next;
}				t_dir;

t_opt	*ft_get_flags(const char **argv);
t_dir	*ft_get_args(const char **argv, t_opt *opts);
void	ft_sort(t_opt *opts, t_dir *p);
void	ft_get_children(t_opt *opts, t_dir *p);
void	ft_print_ls(t_opt *opts, t_dir *p, t_bool root);
t_dir	*ft_new_dir(char *path, t_opt *opts);
t_dir	*ft_add_dir(t_dir *curr, char *path, t_opt *opts);
void	ft_get_dir_info(t_dir *dir, t_opt *opts);
t_dir	*ft_get_head(t_dir *curr);
t_dir	*ft_get_tail(t_dir *curr);
void	ft_swap_dir(t_dir *a, t_dir *b);
void	ft_place_left(t_dir *pivot, t_dir *move);
void	ft_place_right(t_dir *pivot, t_dir *move);
void	ft_rev_dirs(t_dir *dir);
void	ft_free_opts(t_opt **opts);
void	ft_free_dirs(t_dir **dir);

#endif
