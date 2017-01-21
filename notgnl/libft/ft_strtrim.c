/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 10:12:18 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 21:59:23 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;
	int		len;
	int		x;

	i = 0;
	x = 0;
	len = ft_strlen(s);
	ret = (char*)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	while (SPACE(s[len - 1]))
		len--;
	while (SPACE(s[i]))
		i++;
	while (i < len)
	{
		ret[x] = s[i];
		i++;
		x++;
	}
	ret[x] = 0;
	return (ret);
}
