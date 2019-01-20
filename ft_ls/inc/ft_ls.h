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
	char			*permissions;
	nlink_t			links;
	char			*owner;
	char			*group;
	off_t			size;
	struct timespec mtime;
	char			*name;
	struct s_dir	*next;
}				t_dir;

typedef struct	s_dirlist
{
	char				*name;
	t_dir				*head;
	size_t				total;
	struct s_dirlist	*next;
}				t_dirlist;

t_dirlist		*ft_parseargs(int argc, const char **argv, t_opt *options);
t_dir			*ft_getinfo(t_dirlist *directory, t_opt *options);
char			*ft_checkname(char *str);
void			ft_setflags(const char *flags, t_opt *options);
char			*ft_parsepermissions(mode_t st_mode);
t_dir			*ft_sortdir(t_dir *dir, t_opt *option);
void			ft_sortmtime(t_dir *dir);
t_dir			*ft_revlist(t_dir *dir);
void			ft_swapdata(t_dir *dir1, t_dir *dir2);
void			ft_displaydir(t_dirlist *dir, t_opt *options, int i);
char			*ft_printtime(char *m_time);
t_opt			*ft_newflags(void);
t_dir			*ft_getfile(char *name, size_t *total, struct dirent *dirread,
							t_opt *options);
void			ft_freelist(t_dir *dir);
void			ft_getlink(char **path, size_t size);
t_dirlist		*ft_revnames(t_dirlist *names);
t_dirlist		*ft_getchildren(t_dirlist *list, t_opt *options);
t_dirlist		*ft_nextfree(t_dirlist *directory);
int				ft_isdir(const char *path);
t_dirlist		*ft_lsttail(t_dirlist *head);
t_dirlist		*ft_newdir(char *name);
#endif
