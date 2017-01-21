/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 20:31:15 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/15 20:30:36 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "printf.h"

int				ft_asprintf(char **strp, const char *fmtstr, ...)
{
	va_list				argp;
	int					ret;

	va_start(argp, fmtstr);
	ret = ft_vasprintf(strp, fmtstr, argp);
	return (ret);
}
