/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widthmod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:30:58 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/28 20:43:55 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

static char	*innerloop(char *str, t_holder *holder,
		unsigned char conver, size_t *textlen)
{
	if (holder->zero_flag && holder->null && holder->prec == -1UL)
	{
		str = ft_rightjustify(str, holder->width - 1, *textlen);
		str = ft_charfillfromleft('0', str, holder->width - 1,
				*textlen);
	}
	else
	{
		str = ft_rightjustify(str, holder->width, *textlen);
		if (holder->zero_flag && (!NUMERCON(conver)))
			str = ft_charfillfromleft('0', str, holder->width,
					*textlen);
	}
	return (str);
}

static char	*restofit(char *str, t_holder *holder,
		unsigned char conver, size_t *textlen)
{
	if (holder->size < holder->width)
	{
		*textlen = holder->size;
		PR_REALLOC(str, char*, holder->width + 1, *textlen);
		holder->size = holder->width;
		str[holder->size] = 0;
		if (!(holder->minus_flag))
			str = innerloop(str, holder, conver, textlen);
		else if (holder->zero_flag && (!NUMERCON(conver)) && holder->null == 0)
			str = ft_charfillfromright('0', str, holder->width, *textlen);
		else
			str = ft_charfillfromright(' ', str, holder->width, *textlen);
	}
	return (str);
}

static char	*p_conver(char *str, t_holder *holder,
		unsigned char conver, size_t *textlen)
{
	if (holder->size < holder->width && conver == 'p' && ft_atoi(str + 2) == 0)
	{
		PR_REALLOC(str, char*, holder->width + 1, holder->size);
		str[holder->width] = 0;
		if (holder->zero_flag)
			str = ft_charfillfromright('0', str, holder->width, holder->size);
		else if (holder->minus_flag)
			str = ft_charfillfromright(' ', str, holder->width, holder->size);
		else
		{
			ft_rightjustify(str, holder->width, holder->size);
			str = ft_charfillfromleft(' ', str, holder->width, holder->size);
		}
		holder->size = holder->width;
	}
	return (restofit(str, holder, conver, textlen));
}

char		*widthmod(char *str, t_holder *holder,
		unsigned char conver, size_t *textlen)
{
	if (holder->width > holder->size && !holder->prec &&
			NUMERCON(conver) && holder->zero_flag && !holder->minus_flag)
	{
		*textlen = holder->size;
		PR_REALLOC(str, char*, holder->width + 1, *textlen);
		holder->size = holder->width;
		str[holder->width] = 0;
		str = ft_rightjustify(str, holder->width, *textlen);
		str = ft_charfillfromleft('0', str, holder->width, *textlen);
		str = negative_handle_printf(str, ft_atoi(str), holder);
	}
	return (p_conver(str, holder, conver, textlen));
}
