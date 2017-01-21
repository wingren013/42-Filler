/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 08:48:38 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 22:16:09 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *d, const char *s)
{
	char	*dest;
	char	*src;

	dest = d;
	src = (char*)s;
	while (*dest != 0)
	{
		dest++;
	}
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (d);
}
