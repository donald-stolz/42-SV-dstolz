/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:25:38 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/22 18:25:39 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static char	ft_getdescriptor(mode_t m)
{
	if ((m & S_IFMT) == S_IFREG)
		return ('-');
	else if ((m & S_IFMT) == S_IFDIR)
		return ('d');
	else if ((m & S_IFMT) == S_IFCHR)
		return ('c');
	else if ((m & S_IFMT) == S_IFBLK)
		return ('b');
	else if ((m & S_IFMT) == S_IFIFO)
		return ('p');
	else if ((m & S_IFMT) == S_IFLNK)
		return ('l');
	else if ((m & S_IFMT) == S_IFSOCK)
		return ('s');
	return ('0');
}

static char	*ft_parse_permissions(mode_t st_mode)
{
	char *permissions;

	permissions = malloc(11);
	*(permissions + 0) = ft_getdescriptor(st_mode);
	*(permissions + 1) = (st_mode & S_IRUSR) ? 'r' : '-';
	*(permissions + 2) = (st_mode & S_IWUSR) ? 'w' : '-';
	*(permissions + 3) = (st_mode & S_IXUSR) ? 'x' : '-';
	*(permissions + 4) = (st_mode & S_IRGRP) ? 'r' : '-';
	*(permissions + 5) = (st_mode & S_IWGRP) ? 'w' : '-';
	*(permissions + 6) = (st_mode & S_IXGRP) ? 'x' : '-';
	*(permissions + 7) = (st_mode & S_IROTH) ? 'r' : '-';
	*(permissions + 8) = (st_mode & S_IWOTH) ? 'w' : '-';
	*(permissions + 9) = (st_mode & S_IXOTH) ? 'x' : '-';
	*(permissions + 10) = '\0';
	return (permissions);
}

static void	ft_set_link(char *path, char **link, size_t size)
{
	char	*linkname;
	char	*tmp;

	free(*link);
	linkname = malloc(size);
	readlink((const char *)path, linkname, size);
	tmp = ft_strjoin(path, " -> ");
	linkname = ft_strjoin(tmp, linkname);
	ft_strdel(&tmp);
	*link = linkname;
}

void		ft_get_dir_info(t_dir *dir, t_opt *opts, size_t *total)
{
	struct stat	dir_stats;

	lstat(dir->path, &dir_stats);
	dir->is_dir = S_ISDIR(dir_stats.st_mode) && !S_ISLNK(dir_stats.st_mode);
	dir->permissions = ft_parse_permissions(dir_stats.st_mode);
	dir->links = dir_stats.st_nlink;
	dir->owner = getpwuid(dir_stats.st_uid)->pw_name;
	dir->group = getgrgid(dir_stats.st_gid)->gr_name;
	dir->size = dir_stats.st_size;
	*total += (size_t)dir_stats.st_blocks;
	dir->m_time = dir_stats.st_mtimespec;
	if (S_ISLNK(dir_stats.st_mode && opts->l_op))
		ft_set_link(dir->path, &dir->name, (size_t)(dir_stats.st_size + 1));
}
