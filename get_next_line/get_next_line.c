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
#include "stdio.h"

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
	tmp = ft_lstnew(ft_strnew(1), fd); //MEMCHECK(1)
	ft_lstadd(file, tmp);
	return (*file);
}

static int		read_file(char **str, const int fd)
{
	char	buf[BUFF_SIZE + 1];
	ssize_t	bytes_read;
	char	*tmp;

	
	tmp = *str;
	if (ft_strlen(tmp) > 1)
		*str = ft_strchr((const char *)tmp, '\n') + 1;
	bytes_read = 0;
	while ((bytes_read = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		MALLCHECK((*str = ft_strjoin((const char *)(*str), (const char *)&buf)));
		free(tmp);
		if (ft_strchr((const char *)&buf, '\n'))
			break;
		else
			tmp = *str;
	}
	return (bytes_read);
}

static size_t	copy_line(char **line, const char *src)
{
	char	*str;
	char	*tmp;
	size_t	i;

	i = 0;
	while (*(src + i) != '\n' && *(src + i))
		i++;
	str = ft_strnew(i);
	ft_strncpy(str, src, i);
	tmp = *line;
	*line = ft_strjoin(tmp, str);
	free(str);
	free(tmp);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*buffers;
	t_list			*curr;
	char			buf[BUFF_SIZE + 1];
	ssize_t			bytes_read;

	if (fd < 0 || line == NULL || (-1 == read(fd, buf, 0)))
		return (-1);
	curr = get_list(&buffers, fd); //MEMCHECK(1)
	bytes_read = read_file((char **)(&curr->content), fd);
	if (bytes_read < BUFF_SIZE && !ft_strlen((const char *)curr->content))
	{
		// Free list
		return (0);
	}
	MALLCHECK((*line = ft_strnew(1)));
	bytes_read = copy_line(line, (const char *)curr->content);

	if (!((size_t)bytes_read < ft_strlen((const char *)curr->content)))
		ft_strclr((char *)curr->content);
	return (1);
}
