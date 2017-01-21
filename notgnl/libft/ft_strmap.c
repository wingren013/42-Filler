/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:06:28 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/25 13:36:36 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*ret;

	i = 0;
	len = ft_strlen(s);
	ret = (char*)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	while (s[i] != 0)
	{
		ret[i] = f(s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
