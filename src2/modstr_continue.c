/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modstr_continue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:54:23 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/22 17:05:51 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

char		*negative_handle_printf(char *str, int y, t_holder *holder)
{
	size_t	i;
	size_t	start;

	i = 0;
	if (y > 0)
		return (str);
	while (i < holder->size - 1 && str[i] != '0')
		i++;
	start = i;
	while (i < holder->size - 1)
	{
		if (str[i] == '-')
		{
			str[start] = '-';
			str[i] = '0';
		}
		i++;
	}
	return (str);
}
