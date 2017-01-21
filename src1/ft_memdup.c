/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:41:07 by smifsud           #+#    #+#             */
/*   Updated: 2016/10/25 13:48:04 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *mem, size_t size)
{
	unsigned char	*ret;

	PR_MALLOC(ret, unsigned char*, unsigned char, size);
	ret = ft_memcpy(ret, mem, size);
	return (ret);
}
