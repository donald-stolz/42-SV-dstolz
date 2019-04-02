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
# define SIXMONTHS ((365 / 2) * 86400)

typedef	enum
{
	false,
	true
}	t_bool;

typedef	struct	s_opt
{
	t_bool		l_op: 1;
	t_bool		a_op: 1;
	t_bool		r_op: 1;
	t_bool		t_op: 1;
	t_bool		rec_op: 1;
}				t_opt;

typedef	struct	s_dir
{
	char			*name;
	char			*path;
	t_bool			is_dir;
	size_t			total;
	char			*permissions;
	nlink_t			links;
	char			*owner;
	char			*group;
	off_t			size;
	struct timespec	m_time;
	struct s_dir	*children;
	struct s_dir	*next;
}				t_dir;

t_opt			*ft_get_flags(const char **argv);
t_dir			*ft_get_args(char **argv, t_opt *opts);
void			ft_sort(t_opt *opts, t_dir **parents);
void			ft_get_children(t_opt *opts, t_dir *p);
void			ft_print_ls(t_opt *opts, t_dir *p, t_bool root);
t_dir			*ft_new_dir(char *name, char *path, t_opt *opts, size_t *total);
void			ft_get_dir_info(t_dir *dir, t_opt *opts, size_t *total);
t_dir			*ft_get_tail(t_dir *curr);
void			ft_push(t_dir **curr, t_dir *new);
void			ft_rev_list(t_dir **dir);
void			ft_place_left(t_dir **head, t_dir **prev, t_dir **cur);
void			ft_place_right(t_dir **tail, t_dir **prev, t_dir **cur);
char			*ft_parse_path(char *name, char *path);
char			*ft_parse_time(struct timespec m_time);
void			ft_print_header(t_dir *path, t_bool root);
void			ft_print_dir(t_dir *dir, t_bool l_op);
void			ft_print_l(t_dir *dir);
void			ft_free_opts(t_opt **opts);
void			ft_free_dirs(t_dir **dir);
t_dir			*ft_set_children(char *p_name, t_opt *opts, size_t *total);
#endif
