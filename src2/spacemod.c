/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacemod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:28:44 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 12:32:41 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

char	*spacemod(char *str, unsigned char conver, t_holder *holder)
{
	if (SIGNEDCONVERP(conver))
	{
		if (ft_atoi(str) > 0)
		{
			PR_REALLOC(str, char*, holder->size + 1, holder->size);
			ft_rightjustify(str, holder->size + 1, holder->size);
			str[0] = ' ';
			holder->size += 1;
		}
		if (ft_atoi(str) == 0)
		{
			free(str);
			str = ft_strdup(" 00");
			holder->size = 3;
		}
	}
	return (str);
}
