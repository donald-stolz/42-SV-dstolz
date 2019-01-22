/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:44:35 by dstolz            #+#    #+#             */
/*   Updated: 2019/01/20 15:49:24 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_args		*ft_getargs(int argc, const char **argv, t_opt *options)
{
	t_args	*result;
	t_args	*temp;
	size_t	i;

	result = NULL;
	i = 1;
	while (argv[i] && *(*(argv + i) + 0) == '-' && *(*(argv + i) + 1))
		ft_setflags(argv[i++], options);
	while (argv[i])
	{
		temp = malloc(sizeof(t_args));
		temp->is_dir = ft_isdir((char *)argv[i]);
		temp->curr = temp->is_dir ? ft_checkname((char *)argv[i++]) : ft_strdup((char *)argv[i++]);
		temp->next = result;
		result = temp;
	}
	if (argc == 1 || result == NULL)
	{
		result = malloc(sizeof(t_args));
		result->curr = ft_strdup("./");
		result->is_dir = true;
		result->next = NULL;
		return (result);
	}
	if (result->next)
		options->m_arg = true;
	return (ft_revargs(result));
}

void		ft_ls(t_args *args, t_opt *options)
{
	t_dirlist *directory;
	int i;
	if (!args->is_dir)
	{
		ft_displayfile(args->curr, options);
		return ;
	}
	directory = malloc(sizeof(t_dirlist));
	directory->name = args->curr;
	if (options->rec_op)
		directory = ft_getchildren(directory, options);
	i = 0;
	while (directory)
	{
		directory->total = 0;
		directory->head = ft_getinfo(directory, options);
		if (directory->head)
		{
			directory->head = ft_sortdir(directory->head, options);
			ft_displaydir(directory, options, i++);
		}
		directory = ft_nextfree(directory);
	}
}

int			main(int argc, const char **argv)
{
	t_opt	*options;
	t_args	*args;

	options = ft_newflags();
	args = ft_getargs(argc, argv, options);
	while (args)
	{
		ft_ls(args, options);
		args = args->next;
		// ft_nextarg(args);
	}
	free(options);
	return (0);
}
