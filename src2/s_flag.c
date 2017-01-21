/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 10:51:15 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 14:24:20 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t		s_flag(const char *str, char **ret)
{
	if (str)
		*ret = ft_strdup(str);
	else
		*ret = ft_strdup("(null)");
	return (ft_strlen(*ret));
}
