/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upperhex_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:52:26 by smifsud           #+#    #+#             */
/*   Updated: 2017/01/20 19:01:59 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t		jupperhex_flag(uintmax_t num, char **ret)
{
	*ret = ft_itoa_base_up_u(num, 16);
	return (ft_strlen(*ret));
}
