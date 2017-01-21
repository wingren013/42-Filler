/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:22:01 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 14:25:02 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t	u_flag(unsigned int num, char **ret)
{
	*ret = ft_itoa_base_u(num, 10);
	return (ft_strlen(*ret));
}
