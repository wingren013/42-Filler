/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lx_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:50:16 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 17:29:30 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t	lx_flag(unsigned long num, char **ret)
{
	*ret = ft_itoa_base_u(num, 16);
	return (ft_strlen(*ret));
}
