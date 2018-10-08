/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 09:51:45 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/02 09:51:47 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/b_ls.h"

char **ft_getdirnames(int argc, const char **argv, int numdirs)
{
	int i;
	char **dirnames;

	dirnames = (char **)malloc((sizeof(char *) * (numdirs)) + 1);
	i = 1;
	if (*(*(argv + 1) + 0) == '-')
		i++;
	if ((i + 1) == argc)
	{
		*(dirnames) = "./";
		i++;
	}
	while (i < argc)
	{
		*(dirnames + i) = *((char **)(argv + i));
		i++;
	}
	return (dirnames);
}

// NOTE: May want to send options as a pointer for case: 'ls -a -r -t ./'
t_opt	*ft_setflags(const char *flags)
{
	t_opt *options;

	if (*(flags + 0) == '-')
	{
		printf("In set flags: %s \n", flags);
		options = malloc(sizeof(t_opt));
		options->l_op = ft_strchr(flags, 'l') ? true : false;
		options->a_op = ft_strchr(flags, 'a') ? true : false;
		options->r_op = ft_strchr(flags, 'r') ? true : false;
		options->t_op = ft_strchr(flags, 't') ? true : false;
		flags++;
	}
	else
		options = NULL;
	return (options);
}

int		main(int argc, const char *argv[])
{
	t_opt	*options;
	char	**dirnames;
	DIR		*dirstream;
	int		numdirs;
	int		i;
	// t_dir	*dir;

	if (argc > 1)
		options = ft_setflags(*(argv + 1));
	else
		options = NULL;
	numdirs = argc > 1 ? argc - 1 : 1;
	numdirs -= options && numdirs > 1 ? 1 : 0;
	dirnames = ft_getdirnames(argc, argv, numdirs);
	if (!dirnames)
		return (0);
	i = 0;
	/** Place in a loop to handle multiple dirnames **/
	while(i < numdirs){
		dirstream = opendir(*(dirnames + i));
		/** May just want to pass as *dir to getinfo and sort**/
		dir = ft_getinfo(dirstream, options);
		/** 
		 * May be able to use an "if" to skip. 
		 * If dir is sorted properly intially
		 **/
		// ft_sortdir(&dir, options);
		// ft_displaydir(&dir, options);
		closedir(dirstream);
	// 	// Free everything?
		i++;
	}
    return 0;
}

