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

	dirnames = (char **)malloc((sizeof(char *) * (numdirs)));
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
	//Check for -a here
	return (dirnames);
}

// NOTE: May want to send options as a pointer for case: 'ls -a -r -t ./'
t_opt	*ft_setflags(const char *flags)
{
	t_opt *options;
	if (*(flags + 0) == '-')
	{
		options = malloc(sizeof(t_opt)); // Free later
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
	t_dirlist	*directory;

	//NOTE: can have multipl '-' args need to restructure arg parsing
	// Crashes when there are no args
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
	directory = malloc(sizeof(struct s_dirlist));
	/** Place in a loop to handle multiple dirnames **/
	while(i < numdirs){
		directory->name = *(dirnames + i);
		dirstream = opendir(directory->name);
		if (directory == NULL)
			printf("Error"); // TODO: Handle error
		directory->head = ft_getinfo(dirstream, directory->name);
		directory->head = ft_sortdir(directory->head, options);
		closedir(dirstream);
		ft_displaydir(directory, options);
	 	// ft_freelist(directory->head);
		i++;
	}
    return 0;
}

