/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 20:44:39 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/18 14:58:39 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"
#include <stdarg.h>

int		ft_sprintf(char *str, const char *fmt, ...)
{
	char		*result;
	va_list		argp;
	int			ret;

	va_start(argp, fmt);
	ret = ft_vasprintf(&result, fmt, argp);
	str = ft_strcpy(str, result);
	free(result);
	return (ret);
}
