/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 08:23:32 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/20 11:01:20 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define SWAP(x, y, T) { T swap = x; x = y; y = swap;}
# define SWAPC(a, b) {a^=b, b^=a, a^=b;}
# define MAX(a, b)  (((a) > (b)) ? (a) : (b))
# define MIN(a, b)  (((a) < (b)) ? (a) : (b))
# define ABS(x) ((x) < 0 ? -(x) : (x))

#endif
