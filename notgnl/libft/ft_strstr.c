/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:03:14 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 11:49:35 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*b;
	char	*b_begin;
	char	*l;

	b = (char*)big;
	if (!ft_strlen(b) && !ft_strlen(little))
		return (b);
	while (*b)
	{
		l = (char*)little;
		b_begin = b;
		while (*b != 0 && *l != 0 && *b == *l)
		{
			b++;
			l++;
		}
		if (*l == 0)
			return (b_begin);
		b = b_begin + 1;
	}
	return (0);
}
