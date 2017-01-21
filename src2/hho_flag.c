/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:22:01 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 18:26:34 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t		hho_flag(unsigned int num, char **ret)
{
	unsigned char	c;

	c = (unsigned char)num;
	*ret = ft_itoa_base((unsigned char)c, 8);
	return (ft_strlen(*ret));
}
