/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:46:46 by smifsud           #+#    #+#             */
/*   Updated: 2017/01/20 18:58:52 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <float.h>
#include <stdio.h>
#include "libft.h"

/*
** -1^sign * 2^exponent-bias * 1.fraction
*/

long		getfraction(double d)
{
	long	extract;

	extract = 0;
	ft_memcpy(&extract, &d, sizeof(double));
	ft_putendl("itoa_base1:");
	ft_putendl(ft_itoa_base(extract, 2));
	extract &= 0xFFFFFFFFFFFFF;
	ft_putendl("itoa_base2:");
	ft_putendl(ft_itoa_base(extract, 2));
	printf("exxx %ld\n", extract << 1);
	return (extract);
}

long		getexponent(double d)
{
	long	extract;

	extract = 0;
	ft_memcpy(&extract, &d, sizeof(double));
	extract &= 0x7FF0000000000000;
	extract = extract >> 52;
	extract -= 1023;
	return (extract);
}

char		*ft_dtoa(double d, size_t prec)
{
	char	*ret;
	size_t	size;
	long	exponent;
	long	fraction;

	size = 10;
	PR_MALLOC(ret, char*, char, size);
	if (prec == 0)
		prec = 6;
	if (prec == -1ul)
		prec = 0;
	return (ret);
}

int			main(void)
{
	double	manual;
	double	con;
	long	num;

	con = 5.2;
	manual = 0xFFFF & 0xF00F;
	printf("%ld\n", manual);
	printf("%f\n", manual);
	ft_dtoa(5.2, 0);
	printf("%ld\n", sizeof(double));
	printf("%f\n", 5.2);
	printf("%lX\n", 5.2);
	printf("%A\n", 5.2);
	ft_memcpy(&num, &con, sizeof(double));
	ft_putendl(0);
	ft_putendl(ft_itoa_base(num, 2));
	ft_putendl(0);
	ft_dtoa(5.5, 0);
	printf("%f\n", 5.5);
}
