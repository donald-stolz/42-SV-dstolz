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
/**	TODOS:
 * [x] setup -a option in getinfo		(Today)
 * [x] concat '/' to dirs if nesscary	(Today)
 * [ ] ft_freelist						(Start Today)
 * [x] handle dirstream error case		(Today)
 * [ ] Simplify/Clean up and write out	(Pre-Exam)
 **/
/**	BONUS:
 * [ ] -R								(Post-Exam)
 **/

t_dirlist	*ft_parseargs(int argc, const char **argv, t_opt *options)
{
	t_dirlist	*curr;
	t_dirlist	*head;
	size_t		i;

	curr = malloc(sizeof(struct s_dirlist));
	head = NULL;
	i = 1;
	while (argv[i] && *(*(argv + i) + 0) == '-')
	{
		ft_setflags(argv[i], options);
		i++;
	}
	while (argv[i])
	{
		curr->name = ft_checkname((char *)argv[i]);
		curr->next = head;
		head = curr;
		i++;
	}
	if (argc == 1 || head == NULL)
	{
		curr->name = "./";
		curr->next = NULL;
		ft_setflags("-", options);
		return (curr);
	}
	return (head);
}

char *ft_checkname(char *str)
{
	int i;
	char c;

	i = ft_strlen(str);
	c = *(str + (i - 1));
	if (c != '/')
		return (ft_strcat(ft_strcpy(ft_strnew(++i), str), "/"));
	return (str);
}

void	ft_setflags(const char *flags, t_opt *options)
{
	if (*(flags) == '-')
	{
		options->l_op = ft_strchr(flags, 'l') ? true : options->l_op;
		options->a_op = ft_strchr(flags, 'a') ? true : options->a_op;
		options->r_op = ft_strchr(flags, 'r') ? true : options->r_op;
		options->t_op = ft_strchr(flags, 't') ? true : options->t_op;
	}
}

int		main(int argc, const char *argv[])
{
	t_dirlist	*directory;
	t_opt		*options;
	int			i;

	options = malloc(sizeof(t_opt));
	options->l_op = false; // Not auto setting to false for some reason
	options->a_op = false;
	options->r_op = false;
	options->t_op = false;
	directory = ft_parseargs(argc, argv, options);
	i = 0;
	while(directory){
		directory->total = 0;
		directory->head = ft_getinfo(directory, options);
		directory->head = ft_sortdir(directory->head, options);	
		ft_displaydir(directory, options);
	 	// ft_freelist(directory->head);
		directory = directory->next;
	}
    return (0);
}

