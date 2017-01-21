/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:22:01 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/19 15:49:18 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t	ho_flag(unsigned int num, char **ret)
{
	unsigned short	s;

	s = (unsigned short)num;
	*ret = ft_itoa_base(s, 8);
	return (ft_strlen(*ret));
}
