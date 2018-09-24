/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 08:00:03 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/24 11:24:21 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "macros.h"

# ifndef T_UINT
#  define T_UINT

typedef	unsigned int	t_uint;

# endif

# ifndef T_ULONG
#  define T_ULONG

typedef unsigned long	t_long;

# endif

int		b_printf(char *format, ...);
int		ft_putchar(char c);
int		ft_puts(char *s);
int		ft_putnbr(va_list arg);
int		ft_putoct(va_list arg);
int		ft_putunbr(va_list arg);
int		ft_puthex(va_list arg);
int		ft_printitoa(int value, int base);
int		ft_printuitoa(t_uint value, int base);
int		ft_printltoa(t_long	value, int base);
int		ft_numdigits(int value, int base);
int		ft_searchflags(char option, va_list arg);
int		ft_putptr(va_list arg);
int		ft_putarg(va_list arg);
int		ft_putstr(va_list arg);
char	ft_tochar(int num);

typedef struct			s_flag
{
	char	c;
	int		(*func)(va_list);
}						t_flag;

static const t_flag	g_flag_table[] =
{
	{'d', &ft_putnbr},
	{'i', &ft_putnbr},
	{'s', &ft_putstr},
	{'c', &ft_putarg},
	{'o', &ft_putoct},
	{'u', &ft_putunbr},
	{'x', &ft_puthex},
	{'p', &ft_putptr},
};

#endif
