/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:48:12 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 14:26:31 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

size_t	x_flag(unsigned int num, char **ret)
{
	*ret = ft_itoa_base_u(num, 16);
	return (ft_strlen(*ret));
}
