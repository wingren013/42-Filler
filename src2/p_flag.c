/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 13:58:24 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 19:28:20 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"
#include <stdio.h>

static char		*ft_finishhex(char *ret, char *hexstr)
{
	hexstr = ft_reversestr(hexstr);
	ret = ft_realc_str(&ret, ft_strlen(hexstr) + 2);
	ret = ft_strcat(ret, hexstr);
	return (ret);
}

static char		*p_tohex(size_t num)
{
	char	*ret;
	size_t	i;
	size_t	len;
	char	*hexstr;

	i = 0;
	len = 2;
	PR_MALLOC(hexstr, char*, char, len + 3);
	while (num)
	{
		hexstr[i++] = ft_hexchar(num % 16);
		num /= 16;
		if (len - 1 == i)
		{
			hexstr = (char*)ft_realc((void**)&hexstr, len * 2 + 1, len);
			MALLOC_GUARD(hexstr);
			len = len * 2 + 1;
		}
	}
	hexstr[i] = 0;
	ret = ft_strdup("0x");
	ret = ft_finishhex(ret, hexstr);
	free(hexstr);
	return (ret);
}

size_t			p_flag(void *ptr, char **ret)
{
	size_t	p;

	if (!ptr)
	{
		*ret = ft_strdup("0x0");
	}
	else
	{
		p = (size_t)ptr;
		*ret = p_tohex(p);
	}
	return (ft_strlen(*ret));
}
