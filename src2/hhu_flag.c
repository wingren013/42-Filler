/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:22:01 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 17:01:16 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t		hhu_flag(unsigned int num, char **ret)
{
	unsigned char	c;

	if (num == 255)
		*ret = ft_strdup("255");
	else
	{
		c = (unsigned char)num;
		*ret = ft_itoa_base_u(c, 10);
	}
	return (ft_strlen(*ret));
}
