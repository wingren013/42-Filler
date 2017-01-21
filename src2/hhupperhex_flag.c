/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upperhex_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:52:26 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 19:23:42 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t		hhupperhex_flag(unsigned int num, char **ret)
{
	unsigned char	c;

	c = (unsigned char)num;
	if (num == 255)
		*ret = ft_strdup("FF");
	else
		*ret = ft_itoa_base_up(c, 16);
	return (ft_strlen(*ret));
}
