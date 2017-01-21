/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lupperhex_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:55:42 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 19:23:56 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

size_t	lupperhex_flag(unsigned long num, char **ret)
{
	*ret = ft_itoa_base_up_u(num, 16);
	return (ft_strlen(*ret));
}
