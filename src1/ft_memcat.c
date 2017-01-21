/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:02:10 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 17:30:00 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcat(void *chunk1, void *chunk2, size_t index, size_t size)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	dst = (unsigned char*)chunk1;
	src = (unsigned char*)chunk2;
	while (i < size)
	{
		dst[index] = src[i];
		index++;
		i++;
	}
	return (chunk1);
}
