/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:37:47 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/22 16:10:05 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*itow(unsigned long val)
{
	static wchar_t	buf[30];
	wchar_t			*wcp;

	wcp = &buf[29];
	*wcp = L'\0';
	while (val != 0)
	{
		*(--wcp) = ft_btowc('0' + val % 10);
		val /= 10;
	}
	if (wcp == &buf[29])
		*(--wcp) = L'\0';
	return (wcp);
}
