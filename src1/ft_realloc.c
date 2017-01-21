/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:11:12 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/25 22:52:48 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *buf, size_t buf_cap)
{
	void	*newbuf;

	newbuf = malloc(buf_cap);
	if (newbuf == 0)
		return (0);
	ft_memcpy(newbuf, buf, (sizeof(buf) + 3));
	free(buf);
	return (newbuf);
}
