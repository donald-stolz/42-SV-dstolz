/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 11:18:03 by dstolz            #+#    #+#             */
/*   Updated: 2018/11/04 11:18:05 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int main(int argc, char **argv)
{
	t_et		pieces[MAX_TETRI + 1];
	uint16_t	map[16];
	int			count;
	// int			size;

	if (argc != 2)
		FAIL("usage: ./fillit [file_path]");
	if ((count = read_file(open(argv[1], O_RDONLY), pieces)))
		FAIL("Invalid board");
	solve(map, pieces, count);
	/**
	 * 0. Check args for errors
	 * 1. Read map into list
	 * 2. Solve map
	 * 3. Print map
	 * 4. Free map & list
	 **/ 
}
