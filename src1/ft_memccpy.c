/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:55:01 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/25 15:13:03 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	if ((d != 0 && s == 0) && n == 0)
		return (d);
	if ((d == 0 && s == 0) && n == 0)
		return (0);
	dst = (unsigned char*)d;
	src = (unsigned char*)s;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == (unsigned char)c)
		{
			return ((void*)(d + i + 1));
		}
		i++;
	}
	return (0);
}
