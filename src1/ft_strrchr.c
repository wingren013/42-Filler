/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:27:31 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 21:53:30 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen(s);
	while (i > 0 && s[i - 1] != 0)
	{
		if (s[i - 1] == (unsigned char)c)
		{
			return ((char*)(s + i - 1));
		}
		i--;
	}
	if ((unsigned char)c == 0)
		return ((char*)(s + ft_strlen(s)));
	return (0);
}
