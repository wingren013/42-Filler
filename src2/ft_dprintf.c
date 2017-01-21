/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:34:17 by smifsud           #+#    #+#             */
/*   Updated: 2017/01/19 20:21:00 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"
#include <stdarg.h>

int		ft_dprintf(int fd, const char *fmt, ...)
{
	char		*str;
	va_list		argp;
	int			ret;

	va_start(argp, fmt);
	ret = ft_vasprintf(&str, fmt, argp);
	write(fd, str, ret);
	free(str);
	return (ret);
}
