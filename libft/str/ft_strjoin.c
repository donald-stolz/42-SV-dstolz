/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:45:40 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 17:45:52 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  i;
    char    *str;

    i = ft_strlen(s1);
    i += ft_strlen(s2);
    str = ft_strnew(i);
    ft_strcpy(str, s1);
    ft_strcat(str, s2);
    return (str);
}