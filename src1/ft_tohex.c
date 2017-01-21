/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:02:40 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/01 16:38:33 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tohex(size_t num)
{
	char	*ret;
	size_t	i;
	size_t	len;

	i = 0;
	len = 2;
	PR_MALLOC(ret, char*, char, len + 1);
	while (num)
	{
		ret[i] = ft_hexchar(num % 16);
		i++;
		num /= 16;
		if (len - 1 == i)
		{
			PR_REALLOC(ret, char*, len, len * 2 + 1);
			len = len * 2 + 1;
		}
	}
	ret[i] = 0;
	ret = ft_reversestr(ret);
	return (ret);
}
