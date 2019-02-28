/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 08:42:23 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 08:42:59 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_PRINTF_H
# define B_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		b_printf(const char *restrict format, ...);
#endif
