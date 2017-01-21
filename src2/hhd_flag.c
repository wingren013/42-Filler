/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 13:54:02 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 14:09:58 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

size_t		hhd_flag(unsigned int nb, char **ret)
{
	char	c;

	c = (char)nb;
	*ret = ft_itoa(c);
	return (ft_strlen(*ret));
}
