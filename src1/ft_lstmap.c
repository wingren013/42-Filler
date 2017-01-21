/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 13:14:36 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/26 16:40:54 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*ret;
	t_list	*cur;

	if (!lst)
		return (0);
	cur = f(lst);
	newlst = ft_lstnew(cur->content, cur->content_size);
	if (!newlst)
		return (0);
	ret = newlst;
	lst = lst->next;
	while (lst)
	{
		cur = f(lst);
		newlst->next = ft_lstnew(cur->content, cur->content_size);
		if (!newlst)
			return (0);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (ret);
}
