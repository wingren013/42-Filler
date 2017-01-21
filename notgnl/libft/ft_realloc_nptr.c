/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:11:12 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/24 21:23:58 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc_nptr(void *buf, size_t new_size, size_t old_size)
{
	void	*newptr;

	newptr = malloc(new_size);
	if (newptr == 0)
		return (0);
	ft_memcpy(newptr, buf, old_size);
	free(buf);
	return (newptr);
}
