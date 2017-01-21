/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upperhex_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:52:26 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 19:22:50 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t	hupperhex_flag(unsigned int num, char **ret)
{
	unsigned short	s;

	s = (unsigned short)num;
	*ret = ft_itoa_base_up(s, 16);
	return (ft_strlen(*ret));
}
