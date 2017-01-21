/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:33:07 by smifsud           #+#    #+#             */
/*   Updated: 2016/09/25 12:31:10 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;

	ret = (char*)malloc((sizeof(char) * (ft_strlen(s1) + 1)));
	if (!ret)
		return (0);
	ret = ft_strcpy(ret, (char*)s1);
	return (ret);
}
