/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 09:59:20 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 22:15:29 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *d, const char *s, size_t nb)
{
	size_t	i;
	char	*dest;
	char	*src;

	dest = d;
	src = (char*)s;
	i = 0;
	while (*dest != 0)
	{
		dest++;
	}
	while (*src != 0 && i < nb)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (d);
}
