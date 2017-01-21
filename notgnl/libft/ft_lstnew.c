/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:40:30 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 16:09:42 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	ret = (t_list*)malloc(sizeof(t_list));
	MALLOC_GUARD(ret);
	if (!content)
	{
		ret->content = 0;
		ret->content_size = 0;
	}
	else
	{
		ret->content = malloc(content_size);
		ret->content = ft_memcpy(ret->content, content, content_size);
		ret->content_size = content_size;
	}
	ret->next = 0;
	return (ret);
}
