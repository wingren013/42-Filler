/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 14:03:22 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/19 16:30:27 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t	c_flag(unsigned int c, char **ret, t_holder *holder)
{
	if (c == 0)
		holder->null = 1;
	*ret = (char*)malloc(sizeof(char));
	(*ret)[0] = c;
	return (1);
}
