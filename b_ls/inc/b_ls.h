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
# include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum { false, true } t_bool;

typedef struct	s_opt
{
	t_bool	l_op;
	t_bool	a_op;
	t_bool	r_op;
	t_bool	t_op;
}				t_opt;

typedef struct s_dir
{
	char	*permissions;
	nlink_t	links;
	char	*owner;
	char	*group;
	off_t	size;
	time_t	mtime;
	char	*name;
	struct s_dir	*next;
}				t_dir;

typedef struct s_dirlist
{
	char				*name;
	t_dir				*head;
	size_t				total;
	struct s_dirlist	*next;
} 				t_dirlist;

t_dirlist *ft_parseargs(int argc, const char **argv, t_opt *options);
t_dir *ft_getinfo(t_dirlist *directory, t_opt *options);
char *ft_checkname(char *str);
void ft_setflags(const char *flags, t_opt *options);
char	*ft_parsepermissions(mode_t st_mode);
t_dir	*ft_sortdir(t_dir *dir, t_opt *option);
void	ft_sortmtime(t_dir *dir);
t_dir	*ft_revlist(t_dir *dir);
void	ft_swapdata(t_dir *dir1, t_dir *dir2);
void	ft_displaydir(t_dirlist *dir, t_opt *options);
char	*ft_printtime(char *m_time);
#endif
