/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charfillfromleft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:02:11 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/01 15:29:36 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charfillfromleft(char c, char *str, size_t len, size_t textlen)
{
	size_t	fillsize;
	size_t	i;

	i = 0;
	fillsize = len - textlen;
	while (i < fillsize)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
