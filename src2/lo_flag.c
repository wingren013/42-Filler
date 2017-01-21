/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lo_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:27:50 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 14:17:14 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

size_t	lo_flag(unsigned long num, char **ret)
{
	*ret = ft_itoa_base_u(num, 8);
	return (ft_strlen(*ret));
}
