/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plusmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:50:46 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 15:44:23 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

char	*plusmod(char *str, unsigned char conver, t_holder *holder)
{
	if (SIGNEDCONVERP(conver) && str[0] == ' ')
	{
		if (ft_atoi(str) < 0)
			str[0] = '-';
		else
			str[0] = '+';
	}
	else if (SIGNEDCONVERP(conver))
	{
		str = ft_realc((void**)&str, holder->size + 1, holder->size);
		MALLOC_GUARD(str);
		if (ft_atoi(str) > 0)
			ft_rightjustify(str, holder->size + 1, holder->size);
		if (ft_atoi(str) > 0)
			str[0] = '+';
		holder->size += 1;
		if (ft_atoi(str) == 0)
		{
			free(str);
			str = ft_strdup("+00");
			holder->size = 3;
		}
	}
	return (str);
}
