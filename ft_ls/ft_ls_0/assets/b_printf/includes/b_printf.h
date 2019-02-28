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
char	*b_itoa(long long value, int base);
int		b_putchar(char c);
char	b_tochar(int num);
int		b_puts(char *s);
int		b_putptr(va_list arg);
int		b_lookup(va_list arg, char c);
int		b_strlen(const char *s);
int		b_numlen(long long n, int base);
char	*b_strrev(char *str);
#endif
