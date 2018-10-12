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

/**
 * Dirent Struct: https://stackoverflow.com/questions/12991334/members-of-dirent-structure
 * 
 * Stat Struct: http://pubs.opengroup.org/onlinepubs/009695399/basedefs/sys/stat.h.html
 * 
 **/

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
	t_bool	l_op; // use a long listing format
	t_bool	a_op; // --all; do not ignore entries starting with .
	t_bool	r_op; // --reverse; reverse order while sorting
	t_bool	t_op; // sort by modification time
}				t_opt;

/**	- file permissions (in st_mode)
 *		+http://codewiki.wikidot.com/c:system-calls:stat
 *	- number of links
 * 	- owner name
 * 	- owner group
 * 	- file size
 * 	- time of last modification	
 * 	- file/directory name
 **/
typedef struct s_dir
{
	char *permissions;
	nlink_t links;
	char *owner;
	char *group;
	off_t size;
	time_t mtime;
	char *name;
	struct s_dir	*next;
}				t_dir;
// t_file	*subdirs;
//Works for regular files; Not symbolic links
// Might need to parse into "char *" https://en.wikibooks.org/wiki/C_Programming/time.h/time_t

typedef struct s_dirlist
{
	char *name;
	t_dir *head;
} 				t_dirlist;
//int total?

char	**ft_getdirnames(int argc, const char **argv, int numdirs);
t_opt	*ft_setflags(const char *flags);
char	*ft_parsepermissions(mode_t st_mode);
t_dir	*ft_getinfo(DIR *dirstream, char *directory);
t_dir	*ft_sortdir(t_dir *dir, t_opt *option);
void	ft_sortmtime(t_dir *dir);
t_dir	*ft_revlist(t_dir *dir);
void	ft_swapdata(t_dir *dir1, t_dir *dir2);
#endif
