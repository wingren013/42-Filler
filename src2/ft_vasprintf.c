/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 20:31:15 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/28 16:18:58 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

static int		handle_pw(unsigned char **fmt, t_holder *holder)
{
	if (**fmt != '.')
		holder->width = (size_t)ft_atoi((char*)*fmt);
	while (!(FUNCS[**fmt]) && **fmt != '.' && **fmt)
		(*fmt)++;
	if (**fmt == '.')
	{
		(*fmt)++;
		if (!ISDIGIT(**fmt))
		{
			holder->prec = -1;
			if (**fmt == '-')
				(*fmt)++;
			return (1);
		}
		holder->prec = (size_t)ft_atoi((char*)*fmt);
		if (holder->prec == 0)
			holder->prec = -1;
	}
	while ((!(FUNCS[**fmt]) && **fmt != 'l' && **fmt != 'h') && **fmt)
		(*fmt)++;
	return (1);
}

static void		flag_switch(unsigned char **fmt, t_holder *holder)
{
	while (FLAG(**fmt))
	{
		if (**fmt == '#')
			holder->pound_flag = 1;
		if (**fmt == '0')
			holder->zero_flag = 1;
		if (**fmt == '-')
			holder->minus_flag = 1;
		if (**fmt == ' ')
			holder->space_flag = 1;
		if (**fmt == '+')
			holder->plus_flag = 1;
		(*fmt)++;
	}
}

static int		handlepercent(va_list argp, unsigned char **fmt, char **ret,
		t_holder *holder)
{
	char	*str;

	clearholder(holder);
	if (FLAG(**fmt))
		flag_switch(fmt, holder);
	if (ISDIGIT(**fmt) || **fmt == '.')
	{
		handle_pw(fmt, holder);
	}
	length_modifiers(fmt);
	if (FUNCS[**fmt])
	{
		holder->size = func_switch(argp, *fmt, holder, &str);
		MALLOC_GUARD(str);
		str = flags_modstr(str, holder, **fmt);
		ft_realc((void**)ret, holder->size + holder->ip + 1, holder->ret);
		*ret = ft_memcat(*ret, str, holder->ret, holder->size);
		holder->ret = holder->size + holder->ret;
		free(str);
	}
	return (1);
}

static size_t	loop(char **strp, unsigned char *fmt, t_holder *holder,
		va_list argp)
{
	int		i;

	i = 0;
	while (*fmt)
	{
		if (!STOP(*fmt) && *fmt)
		{
			(*strp)[i] = *fmt;
			i++;
			holder->ret += 1;
		}
		if (*fmt == '%')
		{
			fmt++;
			if (handlepercent(argp, &fmt, strp, holder) == 0 || holder->error)
				return (-1);
			i += holder->size;
			holder->ip += holder->ret;
			(*strp)[i] = 0;
			clearholder(holder);
		}
		fmt++;
	}
	(*strp)[i] = 0;
	return (holder->ret);
}

int				ft_vasprintf(char **strp, const char *fmtstr, va_list argp)
{
	size_t				i;
	t_holder			*holder;
	unsigned char		*fmt;

	i = 0;
	setup_funcs();
	fmt = (unsigned char*)ft_strdup(fmtstr);
	holder = (t_holder*)malloc(sizeof(t_holder) * 1);
	MALLOC_GUARD(holder);
	clearholder(holder);
	holder->ret = 0;
	MALLOC_GUARD(fmt);
	holder->ip = ft_strlen(fmtstr);
	PR_MALLOC(*strp, char*, char, holder->ip + 1);
	ft_bzero(*strp, (ft_strlen((char*)fmt) + 1));
	return (loop(strp, fmt, holder, argp));
}
