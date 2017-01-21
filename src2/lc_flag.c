/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 14:10:17 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/21 15:31:45 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>
#include <wchar.h>

size_t		lc_flag(wint_t c, char **ret, t_holder *holder)
{
	wchar_t	*wstr;

	wstr = (wchar_t*)malloc(sizeof(wchar_t) * 2);
	wstr[0] = c;
	wstr[1] = 0;
	*ret = ft_wcstombs(wstr);
	if (c == 0)
	{
		holder->null = 1;
		return (1);
	}
	return (ft_strlen(*ret));
}
