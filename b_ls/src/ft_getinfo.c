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

#include "../inc/b_ls.h"

char	*ft_parsepermissions(mode_t st_mode)
{
	char	*permissions;

	permissions = malloc(11);
	*(permissions + 0) = (S_ISDIR(st_mode)) ? 'd' : '-';
	if (S_ISLNK(st_mode)) *(permissions + 0) = 'l';
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

t_dir *ft_getinfo(DIR *dirstream, char *directory, size_t *size)
{
	t_dir 			*info;
	t_dir *tmp;
	struct dirent	*dirRD;
	struct stat		fileStats;
	struct passwd *pwd;
	struct group *grp;

	info = malloc(sizeof(struct s_dir));
	while( (dirRD = readdir(dirstream)) != NULL)
	{
		tmp = malloc(sizeof(struct s_dir));
		lstat(ft_strjoin(directory, dirRD->d_name), &fileStats);
		tmp->name = dirRD->d_name;
		tmp->permissions = ft_parsepermissions(fileStats.st_mode);
		tmp->links = fileStats.st_nlink;
		pwd = getpwuid(fileStats.st_uid);
		tmp->owner = pwd->pw_name;
		grp = getgrgid(fileStats.st_gid);
		tmp->group = grp->gr_name;
		// or dirRD.d_reclen for links ? Can also check type dirRD.d_type
		tmp->size = fileStats.st_size;
		*size += (size_t)fileStats.st_blocks;
		tmp->mtime = fileStats.st_mtime;
		tmp->next = info->name ? info : NULL;
		info = tmp;
	}
	tmp = NULL;
	free(tmp);
	return (info);
}
