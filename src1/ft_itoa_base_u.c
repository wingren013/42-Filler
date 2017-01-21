/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:50:55 by smifsud           #+#    #+#             */
/*   Updated: 2016/12/02 16:21:32 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char		*max_base_switch(int base)
{
	if (base == 10)
		return (ft_strdup("18446744073709551615"));
	if (base == 16)
		return (ft_strdup("ffffffffffffffff"));
	if (base == 8)
		return (ft_strdup("1777777777777777777777"));
	return (ft_strdup("base not supported for ULLONG_MAX"));
}

static void		normstr_base_u(unsigned long long n, char **ret, int base)
{
	size_t		i;
	long long	save;

	i = 0;
	while (n)
	{
		save = n % base;
		(*ret)[i++] = ft_hexchar(save);
		n = n / base;
	}
	(*ret)[i] = 0;
}

char			*ft_itoa_base_u(unsigned long long n, int base)
{
	int		exit;
	char	*ret;

	exit = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == ULLONG_MAX)
		return (max_base_switch(base));
	ret = (char*)malloc(sizeof(char) * 66);
	MALLOC_GUARD(ret);
	normstr_base_u(n, &ret, base);
	ret = ft_reversestr(ret);
	PR_REALLOC(ret, char*, (ft_strlen(ret) + 1), 66);
	return (ret);
}
