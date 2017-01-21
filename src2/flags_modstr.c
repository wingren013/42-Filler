/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_modstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 12:22:57 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/28 20:43:25 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

static char		*specialmod(char *str, t_holder *holder, unsigned char conver)
{
	if (holder->prec == -1UL && NUMERCON(conver) && str[0] == '0' &&
			str[1] == 0)
		holder->size = 0;
	if (OCTFLAG(conver) && ft_atoi(str) == 0 && holder->pound_flag)
	{
		free(str);
		str = ft_strdup("0");
		holder->size = 1;
	}
	if (holder->null && holder->prec && holder->width < 2)
	{
		free(str);
		PR_MALLOC(str, char*, char, 1);
		str[0] = 0;
		holder->size = 1;
	}
	return (str);
}

static char		*precspecial(char *str, t_holder *holder, unsigned char conver)
{
	if (holder->prec != -1UL && conver == 'S' && holder->prec)
	{
		holder->size = p_ls(holder->wstr, holder->prec, &str);
	}
	if (holder->prec == -1UL && conver == 'p' && str[2] == '0')
	{
		free(str);
		str = ft_strdup("0x");
		holder->size = 2;
	}
	if ((holder->prec != -1UL && conver == 'p' && str[2] == '0'
				&& holder->prec))
	{
		str = ft_realc_str(&str, holder->prec + 2);
		holder->size = holder->prec + 2;
		while (holder->prec - 1)
		{
			str = ft_strcat(str, ft_strdup("0"));
			holder->prec -= 1;
		}
	}
	return (str);
}

static char		*nextstep(char *str, t_holder *holder,
		unsigned char conver)
{
	if ((holder->size > holder->prec && holder->prec && (!NUMERCON(conver))
				&& conver != 'p' && conver != 'S') ||
			(holder->prec == -1UL && conver != 'p' && !NUMERCON(conver)))
	{
		if (holder->prec == -1UL && conver != '%')
			holder->size = 0;
		else if (conver != '%')
		{
			PR_REALLOC(str, char*, holder->prec, holder->size);
			(str)[holder->prec] = 0;
			holder->size = holder->prec;
		}
	}
	if (holder->size < holder->prec && holder->prec && NUMERCON(conver)
			&& holder->prec != -1UL)
	{
		if (0 > ft_atoi(str))
			holder->prec += 1;
		PR_REALLOC(str, char*, holder->prec, holder->size);
		str = ft_rightjustify(str, holder->prec, holder->size);
		str = ft_charfillfromleft('0', str, holder->prec, holder->size);
		holder->size = holder->prec;
		str = negative_handle_printf(str, ft_atoi(str), holder);
	}
	return (str);
}

char			*flags_modstr(char *str, t_holder *holder, unsigned char conver)
{
	size_t	textlen;

	if (holder->space_flag || holder->plus_flag)
	{
		if (holder->plus_flag)
			str = plusmod(str, conver, holder);
		else
			str = spacemod(str, conver, holder);
		MALLOC_GUARD(str);
	}
	if (holder->pound_flag)
	{
		str = poundmod(str, conver, holder);
		MALLOC_GUARD(str);
	}
	str = nextstep(str, holder, conver);
	MALLOC_GUARD(str);
	str = precspecial(str, holder, conver);
	MALLOC_GUARD(str);
	str = widthmod(str, holder, conver, &textlen);
	MALLOC_GUARD(str);
	str = specialmod(str, holder, conver);
	return (str);
}
