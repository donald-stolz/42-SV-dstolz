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

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int     b_printf(const char *restrict format, ...);
char    *ft_itoa(long long value, int base);
int     ft_putchar(char c);
char    ft_tochar(int num);
int     ft_puts(char *s);
int     ft_putptr(va_list arg);
int     ft_lookup(va_list arg, char c);
int	    ft_strlen(const char *s);
int     ft_numlen(long long n, int base);
char    *ft_strrev(char *str);
#endif