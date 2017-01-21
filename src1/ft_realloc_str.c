/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:41:49 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/02 13:51:34 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_str(char *str, size_t newsize)
{
	char	*newstr;

	PR_MALLOC(newstr, char*, char, newsize + 1);
	newstr = ft_strcpy(newstr, str);
	return (newstr);
}
