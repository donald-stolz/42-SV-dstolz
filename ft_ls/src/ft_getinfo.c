/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:31:42 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/04 09:31:46 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	ft_getdescriptor(mode_t m)
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

char	*ft_parsepermissions(mode_t st_mode)
{
	char	*permissions;

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

void	ft_getlink(char **path, size_t size)
{
	char	*linkname;
	char	*tmp;

	linkname = malloc(size);
	readlink(*path, linkname, size);
	tmp = ft_strjoin(*path, " -> ");
	free(*path);
	*path = ft_strjoin(tmp, linkname);
	free(tmp);
}

t_dir	*ft_getfile(char *name, size_t *total, struct dirent *dirread,
					t_opt *options)
{
	t_dir			*tmp;
	struct stat		filestats;
	char			*dirpath;

	dirpath = ft_strjoin(name, dirread->d_name);
	tmp = malloc(sizeof(struct s_dir));
	lstat(dirpath, &filestats);
	free(dirpath);
	tmp->name = ft_strdup(dirread->d_name);
	tmp->permissions = ft_parsepermissions(filestats.st_mode);
	tmp->links = filestats.st_nlink;
	tmp->owner = getpwuid(filestats.st_uid)->pw_name;
	tmp->group = getgrgid(filestats.st_gid)->gr_name;
	tmp->size = filestats.st_size;
	*total += (size_t)filestats.st_blocks;
	tmp->mtime = filestats.st_mtimespec;
	if (S_ISLNK(filestats.st_mode) && options->l_op)
		ft_getlink(&tmp->name, (size_t)(filestats.st_size + 1));
	return (tmp);
}

t_dir	*ft_getinfo(t_dirlist *directory, t_opt *options)
{
	DIR				*dirstream;
	t_dir			*info;
	t_dir			*tmp;
	struct dirent	*dirread;

	dirstream = opendir(directory->name);
	if (dirstream == NULL)
	{
		b_printf("ft_ls: %s: No such file or directory\n", directory->name);
		return (NULL);
	}
	info = NULL;
	while ((dirread = readdir(dirstream)) != NULL)
	{
		if (*(dirread->d_name) != '.' || options->a_op)
		{
			tmp = ft_getfile(directory->name, &directory->total, dirread,
								options);
			tmp->next = info;
			info = tmp;
		}
	}
	closedir(dirstream);
	return (info);
}
