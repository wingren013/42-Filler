/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 10:49:50 by smifsud           #+#    #+#             */
/*   Updated: 2016/12/05 19:11:15 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <libft.h>

t_strfunc		g_strfuncs[256];
unsigned char	g_types[256];

/*
** flags are grouped into sections of 8
** (with 8 uppercase versions for a total of 16)
** with corresponding h and hh flags at +32 and +64 respectively
**
** placing
** non alphabetical flags  and x and X are handled specially
**
** y and Y are reserved as lx and lX
** { and { + 32 are reserved as hx and hhx
** } and } + 32 are reserved as hX and hhX
** 187 and beyond are for extra modifiers
** non printables should be used for special case flags
*/

size_t	func_switch4(char **ret, va_list argp,
		const unsigned char *fmt, t_strfunc func)
{
	if (g_types[*fmt] == 0x24)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x26)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x28)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x2A)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x2C)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x40)
		return (func(va_arg(argp, intmax_t), ret));
	if (g_types[*fmt] == 0)
		return (func(va_arg(argp, uintmax_t), ret));
	return (0);
}

size_t	func_switch3(char **ret, va_list argp,
		const unsigned char *fmt, t_strfunc func)
{
	if (g_types[*fmt] == 0x14)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x16)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x18)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x1A)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x1C)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x30)
		return (func(va_arg(argp, ssize_t), ret));
	if (g_types[*fmt] == 0x31)
		return (func(va_arg(argp, size_t), ret));
	if (g_types[*fmt] == 0x32)
		return (func(va_arg(argp, size_t), ret));
	if (g_types[*fmt] == 0x33)
		return (func(va_arg(argp, size_t), ret));
	if (g_types[*fmt] == 0x34)
		return (func(va_arg(argp, size_t), ret));
	return (func_switch4(ret, argp, fmt, func));
}

size_t	func_switch2(char **ret, va_list argp,
		const unsigned char *fmt, t_strfunc func)
{
	if (g_types[*fmt] == 0x7)
		return (func(va_arg(argp, unsigned long), ret));
	if (g_types[*fmt] == 0x8)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0x9)
		return (func(va_arg(argp, unsigned long), ret));
	if (g_types[*fmt] == 0xA)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0xB)
		return (func(va_arg(argp, unsigned long), ret));
	if (g_types[*fmt] == 0xC)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0xD)
		return (func(va_arg(argp, unsigned long), ret));
	if (g_types[*fmt] == 0x10)
		return (func(ret));
	return (func_switch3(ret, argp, fmt, func));
}

size_t	func_switch(va_list argp, const unsigned char *fmt,
		t_holder *holder, char **ret)
{
	t_strfunc	func;

	func = FUNCS[*fmt];
	if (g_types[*fmt] == 0x1)
		return (func(va_arg(argp, char*), ret));
	if (g_types[*fmt] == 0x2)
	{
		holder->wstr = va_arg(argp, wchar_t*);
		return (func(holder->wstr, ret));
	}
	if (g_types[*fmt] == 0x3)
		return (func(va_arg(argp, void*), ret));
	if (g_types[*fmt] == 0x4)
		return (func(va_arg(argp, int), ret));
	if (g_types[*fmt] == 0x5)
		return (func(va_arg(argp, long), ret));
	if (g_types[*fmt] == 0x6)
		return (func(va_arg(argp, unsigned int), ret));
	if (g_types[*fmt] == 0xE)
		return (func(va_arg(argp, unsigned int), ret, holder));
	if (g_types[*fmt] == 0xF)
		return (func(va_arg(argp, wint_t), ret, holder));
	return (func_switch2(ret, argp, fmt, func));
}
