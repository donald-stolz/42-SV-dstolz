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
#define MAX_PIECES 26
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./libft/libft.h"

#define CHECK(x, y) (!(*(uint64_t *)x & y))
#define TOGGLE(x, y) ((*(uint64_t *)x ^= y))

typedef struct s_etromino t_et;

struct s_etromino
{
	uint64_t value;
	unsigned char id;
	unsigned char x;
	unsigned char y;
	unsigned char width;
	unsigned char height;
	int placed;
	int pos;
	t_et *last;
};

int read_file(const int fd, t_et *piece);
int solve(uint16_t *map, t_et *piece, const int count);
void min_max_calc(const char *buf, char *m);
t_et set_piece(const char *buf, const char curr_id);
int check_surround(char *buf);
int check_chars(char *buf, int count);
int fail(void);
#endif
