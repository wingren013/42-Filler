/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:02:36 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/28 13:33:26 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*encode_four(wchar_t wc, char *ret, size_t *size)
{
	char	firstbyte;
	char	secondbyte;
	char	thirdbyte;
	char	fourthbyte;

	ret = ft_realloc_nptr(ret, *size + 4, *size);
	MALLOC_GUARD(ret);
	*size += 4;
	firstbyte = 0xF0 + ((wc & 0x1C0000) >> 18);
	secondbyte = 0x80 + ((wc & 0x3F000) >> 12);
	thirdbyte = 0x80 + ((wc & 0xFC0) >> 6);
	fourthbyte = 0x80 + (wc & 0x3F);
	(ret)[*size - 5] = firstbyte;
	(ret)[*size - 4] = secondbyte;
	(ret)[*size - 3] = thirdbyte;
	(ret)[*size - 2] = fourthbyte;
	(ret)[*size - 1] = 0;
	return (ret);
}

char	*encode_three(wchar_t wc, char *ret, size_t *size)
{
	char	firstbyte;
	char	secondbyte;
	char	thirdbyte;

	ret = ft_realloc_nptr(ret, *size + 3, *size);
	MALLOC_GUARD(ret);
	*size += 3;
	firstbyte = 0xE0 + ((wc & 0xF000) >> 12);
	secondbyte = 0x80 + ((wc & 0xFC0) >> 6);
	thirdbyte = 0x80 + (wc & 0x3F);
	(ret)[*size - 4] = firstbyte;
	(ret)[*size - 3] = secondbyte;
	(ret)[*size - 2] = thirdbyte;
	(ret)[*size - 1] = 0;
	return (ret);
}

char	*encode_two(wchar_t wc, char *ret, size_t *size)
{
	char	firstbyte;
	char	secondbyte;

	ret = ft_realloc_nptr(ret, *size + 2, *size);
	MALLOC_GUARD(ret);
	*size += 2;
	firstbyte = 0xC0 + ((wc & 0x7C0) >> 6);
	secondbyte = 0x80 + (wc & 0x3F);
	(ret)[*size - 3] = firstbyte;
	(ret)[*size - 2] = secondbyte;
	(ret)[*size - 1] = 0;
	return (ret);
}
