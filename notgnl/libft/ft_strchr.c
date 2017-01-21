/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:09:14 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 21:47:24 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;
	char	search;

	if (s == 0)
		return (0);
	search = (char)c;
	ret = (char*)s;
	while (*ret != 0)
	{
		if (*ret == search)
			return (ret);
		ret++;
	}
	if (search == 0)
		return (ret);
	return (0);
}
