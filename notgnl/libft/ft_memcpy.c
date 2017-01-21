/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:27:21 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/25 11:05:36 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dst;

	if ((d != 0 && s == 0) && n == 0)
		return (d);
	if ((d == 0 && s == 0) && n == 0)
		return (0);
	dst = (unsigned char*)d;
	src = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	return (d);
}
