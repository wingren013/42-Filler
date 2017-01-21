/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poundflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:20:07 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/22 16:26:50 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

char	*poundmod(char *str, unsigned char conver, t_holder *holder)
{
	if (HEXCONVERP(conver))
	{
		if (ft_atoi(str))
		{
			PR_REALLOC(str, char*, holder->size + 2, holder->size);
			ft_rightjustify(str, holder->size + 2, holder->size);
			str[0] = '0';
			if (conver == '{' || conver == 'y'
					|| conver == 'x' || conver - 32 == '{')
				str[1] = 'x';
			else
				str[1] = 'X';
			holder->size += 2;
		}
	}
	if (OCTFLAG(conver))
		if (ft_atoi(str))
		{
			PR_REALLOC(str, char*, holder->size + 1, holder->size);
			ft_rightjustify(str, holder->size + 1, holder->size);
			str[0] = '0';
			holder->size += 1;
		}
	return (str);
}
