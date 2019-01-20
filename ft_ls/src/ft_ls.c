/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:44:35 by dstolz            #+#    #+#             */
/*   Updated: 2019/01/20 12:44:37 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_dirlist	*ft_parseargs(int argc, const char **argv, t_opt *options)
{
	t_dirlist	*curr;
	t_dirlist	*head;
	size_t		i;

	head = NULL;
	i = 1;
	while (argv[i] && *(*(argv + i) + 0) == '-' && *(*(argv + i) + 1))
		ft_setflags(argv[i++], options);
	while (argv[i])
	{
		curr = malloc(sizeof(struct s_dirlist));
		curr->name = ft_checkname((char *)argv[i++]);
		curr->next = head;
		head = curr;
	}
	if (argc == 1 || head == NULL)
	{
		curr = malloc(sizeof(struct s_dirlist));
		curr->name = ft_strdup("./");
		curr->next = NULL;
		return (curr);
	}
	return (ft_revnames(head));
}

char		*ft_checkname(char *str)
{
	int		i;
	char	c;

	i = ft_strlen(str);
	c = *(str + (i - 1));
	if (c != '/')
		return (ft_strjoin(str, "/"));
	return (str);
}

void		ft_setflags(const char *flags, t_opt *options)
{
	if (*(flags + 1) != '-')
	{
		options->l_op = ft_strchr(flags, 'l') ? true : options->l_op;
		options->a_op = ft_strchr(flags, 'a') ? true : options->a_op;
		options->r_op = ft_strchr(flags, 'r') ? true : options->r_op;
		options->t_op = ft_strchr(flags, 't') ? true : options->t_op;
		options->rec_op = ft_strchr(flags, 'R') ? true : options->rec_op;
		return ;
	}
	ft_putstr("ft_ls: illegal option -- - \n");
	exit(1);
}

t_opt		*ft_newflags(void)
{
	t_opt *new;

	new = malloc(sizeof(t_opt));
	new->l_op = false;
	new->a_op = false;
	new->r_op = false;
	new->t_op = false;
	new->rec_op = false;
	return (new);
}

int			main(int argc, const char *argv[])
{
	t_dirlist	*directory;
	t_opt		*options;
	int			i;

	options = ft_newflags();
	directory = ft_parseargs(argc, argv, options);
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
	free(options);
	return (0);
}
