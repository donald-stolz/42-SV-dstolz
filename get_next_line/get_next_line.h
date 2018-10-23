/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:46:31 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/22 08:46:35 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 32
#define MALLCHECK(x) if (!x) return (-1);


int get_next_line(const int fd, char **line);

#endif
