/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 20:44:39 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/19 13:11:18 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"
#include <stdarg.h>

int		ft_printf(const char *fmt, ...)
{
	char		*str;
	va_list		argp;
	size_t		ret;

	va_start(argp, fmt);
	ret = ft_vasprintf(&str, fmt, argp);
	write(1, str, ret);
	free(str);
	return (ret);
}
