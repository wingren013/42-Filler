/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:03:38 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/22 16:03:40 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_hexchar(char c)
{
	if (c + '0' <= '9' && c + '0' >= '0')
		return (c + '0');
	if (c + '0' == 58)
		return ('a');
	if (c + '0' == 59)
		return ('b');
	if (c + '0' == 60)
		return ('c');
	if (c + '0' == 61)
		return ('d');
	if (c + '0' == 62)
		return ('e');
	if (c + '0' == 63)
		return ('f');
	return (0);
}

char	ft_hexup(char c)
{
	return (ft_toupper(ft_hexchar(c)));
}
