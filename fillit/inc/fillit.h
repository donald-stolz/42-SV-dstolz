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

#define CHECK(x, y){(!(*(uint64_t *)x & y))}
#define TOGGLE(x,y){(*(uint64_t *)x ^= y);}
#define FAIL(str){ft_putendl(str); return 1;}

typedef struct s_etromino t_et;

struct s_etromino
{
	uint64_t 		value;
	unsigned char	id;
	unsigned char	x;
	unsigned char	y;
	unsigned char	width;
	unsigned char	height;
	t_et			*last;
};

int	read_file(const int fd, t_et *piece);
int	solve(uint16_t *map, t_et *piece, const int count);

#endif