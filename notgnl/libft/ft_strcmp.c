/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:50:59 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 22:15:51 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*is1;
	unsigned char	*is2;

	is1 = (unsigned char*)s1;
	is2 = (unsigned char*)s2;
	i = 0;
	while (is1[i] != 0 && is2[i] != 0)
	{
		if (is1[i] != is2[i])
			return (is1[i] - is2[i]);
		i++;
	}
	return (is1[i] - is2[i]);
}
