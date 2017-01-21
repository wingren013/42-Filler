/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:40:34 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 22:24:45 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char*)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	while (i < len && s[start] != 0)
	{
		ret[i] = s[start];
		start++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
