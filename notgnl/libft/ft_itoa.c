/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:50:55 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/25 23:01:49 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		zerostr(int *exit, int n, char **ret)
{
	if (!n)
	{
		*ret = (char*)malloc(sizeof(char*) * 2);
		if (!(*ret))
		{
			*exit = 1;
			return ;
		}
		(*ret)[0] = '0';
		(*ret)[1] = 0;
	}
}

static void		minstr(int *exit, int n, char **ret)
{
	if (n <= -2147483648)
	{
		*ret = ft_strdup("-2147483648");
		if (!(*ret))
		{
			*exit = 1;
			return ;
		}
	}
}

static void		normstr(int n, char **ret)
{
	int		i;
	int		sign;
	int		save;

	sign = 0;
	i = 0;
	if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	while (n)
	{
		save = n % 10;
		(*ret)[i++] = save + '0';
		n = n / 10;
	}
	if (sign == -1)
		(*ret)[i++] = '-';
	(*ret)[i] = 0;
}

char			*ft_itoa(int n)
{
	int		exit;
	char	*ret;

	exit = 0;
	zerostr(&exit, n, &ret);
	if (exit)
		return (0);
	if (n == 0)
		return (ret);
	minstr(&exit, n, &ret);
	if (exit)
		return (0);
	if (n <= -2147483648)
		return (ret);
	ret = (char*)malloc(sizeof(char) * 12);
	if (!ret)
		return (0);
	normstr(n, &ret);
	ret = ft_reversestr(ret);
	return (ret);
}
