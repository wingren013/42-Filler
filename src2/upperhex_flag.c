/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upperhex_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:52:26 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 19:24:27 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t		upperhex_flag(unsigned int num, char **ret)
{
	*ret = ft_itoa_base_up_u(num, 16);
	return (ft_strlen(*ret));
}
