/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:48:12 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 14:14:22 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

size_t		hx_flag(unsigned int num, char **ret)
{
	unsigned short	s;

	s = (unsigned short)num;
	*ret = ft_itoa_base(s, 16);
	return (ft_strlen(*ret));
}
