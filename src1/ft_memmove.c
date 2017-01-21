/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:08:44 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 22:20:24 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			((unsigned char*)dst)[len - 1] = ((unsigned char*)src)[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
	}
	return (dst);
}
