/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 13:38:46 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/08 21:53:04 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realc(void **buf, size_t new_size, size_t old_size)
{
	void	*newptr;

	newptr = malloc(new_size);
	MALLOC_GUARD(newptr);
	ft_memcpy(newptr, *buf, old_size);
	free(*buf);
	*buf = newptr;
	return (newptr);
}
