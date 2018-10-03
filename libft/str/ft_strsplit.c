/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:46:39 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/30 17:46:52 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*word_builder(char const *str, char c, size_t *index)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*word;

	i = *index;
	while (*(str + i) == c)
		i++;
	start = i;
	while (*(str + i) != c && *(str + i) != '\0')
		i++;
	end = i;
	*index = i;
	word = ft_strnew(end - start);
	i = 0;
	while (start < end)
		*(word + i++) = *(str + start++);
	*(word + i) = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**rtn;

	i = 0;
	words = 0;
	if (!s)
		return (NULL);
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c && (*(s + (i + 1)) == c || *(s + (i + 1)) == '\0'))
			words++;
		i++;
	}
	i = 0;
	j = 0;
	rtn = (char**)malloc(sizeof(char*) * (words + 1));
	if (!rtn)
		return (NULL);
	while (i < words)
		*(rtn + i++) = word_builder(s, c, &j);
	*(rtn + i) = 0;
	return (rtn);
}
