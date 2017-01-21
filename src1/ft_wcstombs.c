/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:24:33 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/28 13:09:01 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <locale.h>

static char	*decode_switch(wchar_t wc, char **ret, size_t *size)
{
	if (wc <= 0x007F)
	{
		*ret = ft_realloc_nptr(*ret, (*size + 1), *size);
		MALLOC_GUARD(ret);
		(*ret)[*size - 1] = (char)wc;
		(*ret)[*size] = 0;
		*size += 1;
		return (*ret);
	}
	if (wc <= 0x07FF)
	{
		*ret = encode_two(wc, *ret, size);
		return (*ret);
	}
	if (wc <= 0xFFFF)
	{
		*ret = encode_three(wc, *ret, size);
		return (*ret);
	}
	if (wc <= 0x10FFFF)
	{
		*ret = encode_four(wc, *ret, size);
		return (*ret);
	}
	return (0);
}

char		*ft_wcstombs(wchar_t *w)
{
	char	*ret;
	size_t	size;
	char	*holder;

	PR_MALLOC(ret, char*, char, 1);
	ret[0] = 0;
	size = 1;
	if (!w)
		return (ft_strdup("(null)"));
	while (*w)
	{
		holder = decode_switch(*w, &ret, &size);
		if (!holder)
			return (ft_strdup("�"));
		w++;
	}
	return (ret);
}
