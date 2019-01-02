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

	linkname = malloc(size);
	readlink(*path, linkname, size);
	*path = ft_strjoin(*path, " -> ");
	*path = ft_strjoin(*path, linkname);
}

t_dir	*ft_getfile(char *name, size_t *total, struct dirent *dirread)
{
	t_dir			*tmp;
	struct passwd	*pwd;
	struct group	*grp;
	struct stat		filestats;

	tmp = malloc(sizeof(struct s_dir));
	stat(ft_strjoin(name, dirread->d_name), &filestats); // Need to seperate out lstat
	tmp->name = dirread->d_name;
	tmp->permissions = ft_parsepermissions(filestats.st_mode);
	tmp->links = filestats.st_nlink;
	pwd = getpwuid(filestats.st_uid);
	tmp->owner = pwd->pw_name;
	grp = getgrgid(filestats.st_gid);
	tmp->group = grp->gr_name;
	tmp->size = filestats.st_size;
	if (S_ISLNK(filestats.st_mode))
		ft_getlink(&tmp->name, (tmp->size + 1));
	*total += (size_t)filestats.st_blocks;
	tmp->mtime = filestats.st_mtimespec;
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
		printf("ft_ls: %s: No such file or directory\n", directory->name);
		return (NULL);
	}
	info = NULL;
	while ((dirread = readdir(dirstream)) != NULL)
	{
		if (*(dirread->d_name) != '.' || options->a_op)
		{
			tmp = ft_getfile(directory->name, &directory->total, dirread);
			tmp->next = info;
			info = tmp;
		}
	}
	tmp = NULL;
	free(tmp);
	closedir(dirstream);
	return (info);
}
