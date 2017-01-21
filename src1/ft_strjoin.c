/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:58:26 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/24 13:28:42 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*ret;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char*)malloc(sizeof(char) * len);
	str = ret;
	if (ret == 0)
	{
		return (0);
	}
	while (*s1 != 0)
	{
		*ret = *s1;
		s1++;
		ret++;
	}
	while (*s2 != 0)
	{
		*ret = *s2;
		s2++;
		ret++;
	}
	*ret = 0;
	return (str);
}
