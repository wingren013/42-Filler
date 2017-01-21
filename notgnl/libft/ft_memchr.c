/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:16:38 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 22:20:44 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)s;
	while (str[i] != 0 && i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((unsigned char*)(s + i));
		i++;
	}
	if ((unsigned char)c == 0)
		return (str + i);
	return (0);
}
