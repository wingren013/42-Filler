/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 10:19:46 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 22:23:00 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	length(char *src)
{
	unsigned int	srclen;

	srclen = 0;
	while (src[srclen] != 0)
		srclen++;
	return (srclen);
}

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			i2;
	size_t			destlen;
	size_t			spaceleft;

	i = 0;
	i2 = 0;
	destlen = 0;
	while (dest[i] != 0)
	{
		i++;
		destlen++;
		if (i >= size)
			return (size + length((char*)src));
	}
	spaceleft = size - destlen;
	while (src[i2] != 0 && i < size)
	{
		if (spaceleft-- > 1)
			dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = 0;
	return (destlen + length((char*)src));
}
