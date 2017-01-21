/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:24:33 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/28 13:34:46 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <locale.h>
#include "printf.h"

static char	*decode_second(wchar_t wc, char **ret, size_t *size,
		ssize_t *prec)
{
	if (wc <= 0xFFFF && *prec - 3 >= 0)
	{
		*ret = encode_three(wc, *ret, size);
		*prec -= 3;
		return (*ret);
	}
	if (wc <= 0x10FFFF && *prec - 4 >= 0)
	{
		*ret = encode_four(wc, *ret, size);
		*prec -= 4;
		return (*ret);
	}
	return (0);
}

static char	*decode_switch(wchar_t wc, char **ret, size_t *size,
		ssize_t *prec)
{
	if (wc <= 0x007F)
	{
		*ret = ft_realloc_nptr(*ret, (*size + 1), *size);
		MALLOC_GUARD(ret);
		(*ret)[*size - 1] = (char)wc;
		(*ret)[*size] = 0;
		*size += 1;
		*prec -= 1;
		return (*ret);
	}
	if (wc <= 0x07FF && *prec - 2 >= 0)
	{
		*ret = encode_two(wc, *ret, size);
		*prec -= 2;
		return (*ret);
	}
	if (0 == decode_second(wc, ret, size, prec))
	{
		*prec = 0;
		return (0);
	}
	return (*ret);
}

size_t		p_ls(wchar_t *w, size_t prec, char **ret)
{
	size_t	size;
	char	*holder;
	ssize_t	sprec;

	free(*ret);
	PR_MALLOC(*ret, char*, char, 1);
	(*ret)[0] = 0;
	size = 1;
	sprec = (ssize_t)prec;
	if (!w)
	{
		*ret = ft_strdup("(null)");
		return (6);
	}
	while (*w && sprec)
	{
		holder = decode_switch(*w, ret, &size, &sprec);
		if (!holder && sprec != 0)
		{
			*ret = ft_strdup("�");
			return (1);
		}
		w++;
	}
	return (ft_strlen(*ret));
}
