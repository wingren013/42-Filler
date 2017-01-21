/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 13:16:50 by smifsud           #+#    #+#             */
/*   Updated: 2016/10/18 13:55:43 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"
#include <stdlib.h>

wchar_t		*ft_wchardup(wchar_t *w)
{
	wchar_t		*ret;

	ret = (wchar_t*)malloc(sizeof(wchar_t) * (ft_wcharlen(w) + 1));
	ret = ft_memcpy(w, ret, sizeof(wchar_t) * ft_wcharlen(w));
	ret[ft_wcharlen(w) * sizeof(wchar_t)] = 0;
	return (ret);
}
