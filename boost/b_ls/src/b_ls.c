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

t_dirlist	*ft_parseargs(int argc, const char **argv, t_opt *options)
{
	t_dirlist	*curr;
	t_dirlist	*head;
	size_t		i;

	head = NULL;
	i = 1;
	while (argv[i] && *(*(argv + i) + 0) == '-' && *(*(argv + i) + 1))
	{
		ft_setflags(argv[i], options);
		i++;
	}
	while (argv[i])
	{
		curr = malloc(sizeof(struct s_dirlist));
		curr->name = ft_checkname((char *)argv[i]);
		curr->next = head;
		head = curr;
		i++;
	}
	if (argc == 1 || head == NULL)
	{
		curr = malloc(sizeof(struct s_dirlist));
		curr->name = "./";
		curr->next = NULL;
		return (curr);
	}
	return (ft_revnames(head));
}

t_dirlist	*ft_revnames(t_dirlist *names)
{
	t_dirlist *current;
	t_dirlist *prev;
	t_dirlist *next;

	current = names;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	names = prev;
	return (names);
}

char *ft_checkname(char *str)
{
	int i;
	char c;

	i = ft_strlen(str);
	c = *(str + (i - 1));
	if (c != '/')
		return (ft_strjoin(str, "/"));
	return (str);
}

void ft_setflags(const char *flags, t_opt *options) 
{
	if (*(flags + 1) != '-')
	{
		options->l_op = ft_strchr(flags, 'l') ? true : options->l_op;
		options->a_op = ft_strchr(flags, 'a') ? true : options->a_op;
		options->r_op = ft_strchr(flags, 'r') ? true : options->r_op;
		options->t_op = ft_strchr(flags, 't') ? true : options->t_op;
		return ;
	}
	printf("b_ls: illegal option -- - \n");
	exit(1);
}

t_opt	*ft_newflags()
{
	t_opt *new;

	new = malloc(sizeof(t_opt));
	new->l_op = false;
	new->a_op = false;
	new->r_op = false;
	new->t_op = false;
	return (new);
}

int		main(int argc, const char *argv[])
{
	t_dirlist	*directory;
	t_opt		*options;
	int			i;

	options = ft_newflags();
	directory = ft_parseargs(argc, argv, options);
	i = 0;
	while(directory){
		directory->total = 0;
		directory->head = ft_getinfo(directory, options);
		if (directory->head)
		{
			directory->head = ft_sortdir(directory->head, options);
			ft_displaydir(directory, options);
			ft_freelist(directory->head);
		}
		directory = directory->next;
	}
	free(directory);
	free(options);
    return (0);
}
