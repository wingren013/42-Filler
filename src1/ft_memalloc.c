/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:03:37 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 11:56:35 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;

	ret = malloc(sizeof(char) * size);
	MALLOC_GUARD(ret);
	ft_bzero(ret, size);
	return ((void*)ret);
}
