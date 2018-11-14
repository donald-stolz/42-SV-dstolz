/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:15:00 by dstolz            #+#    #+#             */
/*   Updated: 2018/11/04 11:15:02 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H
#define MAX_TETRI 26
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

typedef struct s_etromino t_etromino;

struct s_etromino
{
	uint16_t 		value;
	unsigned char	id;
	unsigned char	x;
	unsigned char	y;
	unsigned char	width;
	unsigned char	height;
	t_etromino		*last;
};

int	read_file(const int fd, t_etromino *pieces);

#endif
