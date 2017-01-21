/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:17:37 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/25 15:39:22 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reversestr(char *s)
{
	int		len;
	char	*ret;
	int		i;

	i = 0;
	len = ft_strlen(s);
	ret = (char*)malloc(sizeof(char) * (len + 1));
	while (len)
	{
		ret[i] = s[len - 1];
		len--;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
