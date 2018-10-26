/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:46:09 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/22 08:46:13 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t		copy_line(char *dst, const char *src)
{
	char *tmp;
	size_t i;

	i = 0;
	while(*(src + i) != '\n' )
		i++;
	tmp = ft_strnew(i);
	ft_strncpy(tmp, src, i);
	dst = ft_strjoin(dst, tmp);
	free(tmp);
	return (i);
}

static t_list	*get_list(t_list **file, int fd)
{
	t_list *tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	return (*file);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*buffers;
	t_list			*curr;
	char			buf[BUFF_SIZE + 1];
	ssize_t			bytes_read;
	size_t			bytes_copied;

	if (fd < 0 || line == NULL || (-1 == read(fd, buf, 0)))
		return (-1);
	curr = get_list(&buffers, fd);
	while ((bytes_read = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		curr->content = ft_strjoin((const char *)curr->content,
						(const char *)&buf);
		MALLCHECK(curr->content);
		if(ft_strchr((const char *)&buf, '\n'))
			break;
	}
	if (bytes_read < BUFF_SIZE && !ft_strlen((const char *)curr->content))
		return (0);
	MALLCHECK((*line = ft_strnew(1)));
	bytes_copied = copy_line(*line, (const char *)curr->content);
	(bytes_copied < ft_strlen((const char *)curr->content)) 
		? curr->content += (bytes_copied + 1) 
		: ft_strclr((char *)curr->content);
	return (1);
}
