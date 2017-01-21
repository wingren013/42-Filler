/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   S_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 11:34:45 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/19 13:38:38 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include <libft.h>

size_t		ls_flag(const wchar_t *str, char **ret)
{
	*ret = ft_wcstombs((wchar_t*)str);
	return (ft_strlen(*ret));
}
