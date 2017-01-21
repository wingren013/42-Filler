/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:43:29 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/28 20:45:07 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

static void		z_length(unsigned char **fmt)
{
	if (**fmt == 'z' || **fmt == 'Z')
	{
		(*fmt)++;
		if (**fmt == 'x')
			**fmt = '{' + 64;
		else if (**fmt == 'X')
			**fmt = '}' + 64;
		else
			**fmt += 96;
		if (ISUPPER(**fmt - 96) && **fmt != '}' + 64)
			**fmt += 32;
	}
}

static void		h_length(unsigned char **fmt)
{
	if (**fmt == 'h')
	{
		(*fmt)++;
		if (**fmt == 'h')
		{
			(*fmt)++;
			if (**fmt == 'x')
				**fmt = '{' + 32;
			else if (**fmt == 'X')
				**fmt = '}' + 32;
			else if (!CAPFORM(**fmt))
				**fmt += 64;
		}
		else if (**fmt == 'x')
			**fmt = '{';
		else if (**fmt == 'X')
			**fmt = '}';
		else if (!CAPFORM(**fmt))
			**fmt += 32;
	}
	z_length(fmt);
}

void			length_modifiers(unsigned char **fmt)
{
	if (**fmt == 'l')
	{
		(*fmt)++;
		if (**fmt == 'l')
			(*fmt)++;
		if (**fmt != 'x' && **fmt != 'X' && **fmt != 'U' && **fmt != 'D'
				&& **fmt != 'p')
			**fmt -= 32;
		else if (**fmt == 'U')
			**fmt = 2;
		else if (**fmt == 'D')
			**fmt = 3;
		else if (**fmt != 'p')
			(**fmt)++;
	}
	h_length(fmt);
}
