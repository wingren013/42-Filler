/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:54:02 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 14:09:52 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

size_t		hd_flag(unsigned int nb, char **ret)
{
	short	s;

	s = (short)nb;
	*ret = ft_itoa(s);
	return (ft_strlen(*ret));
}
