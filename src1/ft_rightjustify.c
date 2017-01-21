/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rightjustify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 21:07:15 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 12:07:02 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rightjustify(char *str, size_t width, size_t textlen)
{
	size_t	emptyspace;
	size_t	i;

	i = 0;
	emptyspace = width - textlen;
	while (textlen + 1)
	{
		str[width] = str[textlen];
		textlen--;
		width--;
	}
	i = 0;
	while (i < emptyspace)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}
