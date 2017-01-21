/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:50:55 by smifsud           #+#    #+#             */
/*   Updated: 2016/12/02 16:22:28 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char		*min_base_switch(int base)
{
	if (base == 10)
		return (ft_strdup("-9223372036854775808"));
	if (base == 16)
		return (ft_strdup("8000000000000000"));
	if (base == 8)
		return (ft_strdup("1000000000000000000000"));
	return (ft_strdup("base not supported for LONG_MIN"));
}

static void		normstr_base(long long n, char **ret, int base)
{
	size_t		i;
	int			sign;
	long long	save;

	sign = 0;
	i = 0;
	if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	while (n)
	{
		save = n % base;
		(*ret)[i++] = ft_hexup(save);
		n = n / base;
	}
	if (sign == -1 && base == 10)
		(*ret)[i++] = '-';
	(*ret)[i] = 0;
}

char			*ft_itoa_base_up(long long n, int base)
{
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == LONG_MIN)
		return (min_base_switch(base));
	ret = (char*)malloc(sizeof(char) * 66);
	MALLOC_GUARD(ret);
	normstr_base(n, &ret, base);
	ret = ft_reversestr(ret);
	PR_REALLOC(ret, char*, (ft_strlen(ret) + 1), 66);
	return (ret);
}
