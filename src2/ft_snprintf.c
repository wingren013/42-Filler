/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 20:44:39 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/15 20:33:29 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"
#include <stdarg.h>

int		ft_snprintf(char *str, size_t size, const char *fmt, ...)
{
	char		*result;
	va_list		argp;
	int			ret;

	va_start(argp, fmt);
	ret = ft_vasprintf(&result, fmt, argp);
	result[size] = 0;
	if (ret > size)
		ret = size;
	str = ft_strcpy(str, result);
	free(result);
	return (ret);
}
