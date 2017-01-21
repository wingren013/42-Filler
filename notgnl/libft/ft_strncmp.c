/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:44:56 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 22:13:12 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*is1;
	unsigned char	*is2;

	i = 0;
	is1 = (unsigned char*)s1;
	is2 = (unsigned char*)s2;
	while (i < n && is1[i] != 0 && is2[i] != 0)
	{
		if (is1[i] != is2[i])
			return (is1[i] - is2[i]);
		i++;
	}
	if (i == n && i != 0)
		return (is1[i - 1] - is2[i - 1]);
	else
		return (is1[i] - is2[i]);
}
