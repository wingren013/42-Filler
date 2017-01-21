/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:59:51 by smifsud           #+#    #+#             */
/*   Updated: 2017/01/20 19:00:17 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbits_qword(unsigned long num)
{
	int		i;

	i = 0;
	while (i < sizeof(unsigned long) * 8)
	{
		ft_putnbr(num & 0x01);
		num = num >> 1;
		i++;
	}
}

void	ft_printbits_dword(unsigned int num)
{
	int		i;

	i = 0;
	while (i < sizeof(unsigned int) * 8)
	{
		ft_putnbr(num & 0x01);
		num = num >> 1;
		i++;
	}
}

void	ft_printbits_word(unsigned short num)
{
	int		i;

	i = 0;
	while (i < sizeof(unsigned short) * 8)
	{
		ft_putnbr(num & 0x01);
		num = num >> 1;
		i++;
	}
}

void	ft_printbits_byte(unsigned char num)
{
	int		i;

	i = 0;
	while (i < sizeof(unsigned char) * 8)
	{
		ft_putnbr(num & 0x01);
		num = num >> 1;
		i++;
	}
}
