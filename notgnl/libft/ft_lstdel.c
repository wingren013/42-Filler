/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:26:04 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 12:34:35 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*sn;

	while (*alst)
	{
		sn = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = sn;
	}
}
