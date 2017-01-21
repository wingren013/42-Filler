/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 19:18:15 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 19:53:52 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*b_begin;
	char	*l;
	size_t	i;

	i = 0;
	b = (char*)big;
	if (!ft_strlen(b) && !ft_strlen(little))
		return (b);
	while (*b && i < len)
	{
		l = (char*)little;
		b_begin = b;
		while (*b != 0 && *l != 0 && *b == *l && i < len)
		{
			b++;
			l++;
			i++;
		}
		if (*l == 0)
			return (b_begin);
		b = b_begin + 1;
		i++;
	}
	return (0);
}
