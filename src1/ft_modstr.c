/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:55:23 by smifsud           #+#    #+#             */
/*   Updated: 2016/10/28 09:51:08 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_modstr(char *ret, size_t precision)
{
	if (precision < ft_strlen(ret))
		ret[precision] = 0;
	return (ret);
}
