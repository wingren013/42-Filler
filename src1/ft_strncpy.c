/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:55:07 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 22:13:29 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t				i;
	char				*d;

	i = 0;
	d = dest;
	while (i < n && *src)
	{
		*dest++ = *src++;
		i++;
	}
	while (i < n)
	{
		*dest++ = 0;
		i++;
	}
	return (d);
}
