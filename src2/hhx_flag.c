/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:48:12 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 18:26:19 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

size_t	hhx_flag(unsigned int num, char **ret)
{
	unsigned char	c;

	c = (unsigned char)num;
	if (num == 255)
		*ret = ft_strdup("ff");
	else
		*ret = ft_itoa_base(c, 16);
	return (ft_strlen(*ret));
}
