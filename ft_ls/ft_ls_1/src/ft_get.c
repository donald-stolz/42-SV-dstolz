/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 09:35:16 by dstolz            #+#    #+#             */
/*   Updated: 2019/03/19 09:35:19 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

//TODO: Error file?
static t_dir *ft_nofile(char *name)
{
	b_printf("ft_ls: %s: No such file or directory\n", name);
	return (NULL);
}
/*
 * 0. Start with head of list
 * 1. Send to name dirstream
 * 2. Get file names, check is_dir and a_op
 * 3. Create t_dir list of children
 * 4. Return list of children
 * 
 *  
 */
t_dir	*ft_set_children(char *p_name, t_bool a_op)
{
	DIR *dirstream;
	struct dirent *curr;
	t_dir result;

	dirstream = opendir(p_name);
	if (dirstream == NULL)
		return *ft_nofile(p_name);
	while((curr = readdir(dirstream)) != NULL)
	{

	}
	
}

void ft_get_children(t_opt *options, t_dir *parents)
{
	while(parents){
		if(parents->is_dir)
			parents->children = ft_set_children(parents->name, options->a_op);
		parents = parents->next;
	}
	//TODO: Check if head gets lost in other functions
}