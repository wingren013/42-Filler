/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentpercent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 11:32:31 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/19 15:42:52 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <libft.h>

size_t	percentpercent(char **ret)
{
	*ret = ft_strdup("%");
	MALLOC_GUARD(ret);
	return (1);
}
