/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 10:20:18 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 22:33:58 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		strcpyr(char *dest, char *src, char c)
{
	int		i;

	i = 0;
	while (src[i] != 0 && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = 0;
	return (i);
}

static char		**split(char **current, char *ori, int words, char c)
{
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	while (i < words)
	{
		temp = strcpyr(current[i], ori, c);
		if (temp != 1)
			i++;
		while (temp-- > 0)
			ori++;
	}
	current[i] = 0;
	return (current);
}

char static		**shame(char **array, int wordcount, int big)
{
	int		i;

	i = -1;
	while (++i < (wordcount))
	{
		array[i] = (char*)malloc(sizeof(char) * (big + 10));
		MALLOC_GUARD(array[i]);
		ft_bzero(array[i], (big + 10));
	}
	return (array);
}

static char		**splitr(char **array, char *str, int wordcount, char c)
{
	int		i;
	int		total;
	int		biggestword;

	total = 0;
	biggestword = 0;
	i = 0;
	while (str[++total])
	{
		if (str[total] == c)
		{
			biggestword = i > biggestword ? i : biggestword;
			i = 0;
			wordcount += (str[total - 1] == c) ? 0 : 1;
		}
		i++;
	}
	wordcount += (str[total - 1] == c) ? 0 : 1;
	array = (char**)malloc(sizeof(char*) * (wordcount + 1));
	MALLOC_GUARD(array);
	if (shame(array, wordcount, biggestword))
		return (split(array, str, wordcount, c));
	else
		return (0);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**strarray;
	int		wordcount;

	wordcount = 0;
	if (!(*str))
	{
		strarray = (char**)malloc(sizeof(char*) * 1);
		MALLOC_GUARD(strarray);
		strarray[0] = 0;
		return (strarray);
	}
	strarray = (char**)malloc(sizeof(char*) * 1);
	MALLOC_GUARD(strarray);
	return (splitr(strarray, (char*)str, wordcount, c));
}
