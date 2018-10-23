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

static t_list	*get_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int) tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	return (*file);
}

static int	read_line(const int fd, char **buf)
{
	char	*str1;
	int		bytes_read;

	MALLCHECK((str1 = ft_strnew(BUFF_SIZE)));
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(*buf, '\n') == NULL)
	{
		bytes_read = read(fd, str1, BUFF_SIZE);
		if (bytes_read < 0)
			return (-1);
		*(str1 + bytes_read) = '\0';
		*buf = ft_strjoin(*buf, (const char *) str1);
		ft_bzero(str1, BUFF_SIZE);
	}
	return (bytes_read);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf;
	char		*str;
	int			bytes_read;

	if (fd < 0 || line == NULL || (-1 == read(fd, buf, 0)))
		return (-1);
	if (!buf)
		buf = ft_strnew(BUFF_SIZE);
	bytes_read = read_line(fd, &buf);
	if (bytes_read == -1)
		return (-1);
	if ((str = ft_strchr(buf, '\n')))
	{
		*(str) = '\0';
		*line = ft_strdup(buf);
		buf = str + 1;
		return (1);
	}
	*line = ft_strdup(buf);
	buf = NULL;
	return (ft_strlen(*line) == 0 ? : 1);
}
