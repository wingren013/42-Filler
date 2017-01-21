/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printevery.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:29:01 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/11 16:34:35 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	debug_printevery(char *str, char c)
{
	ft_putstr("debug_printeverystart ::  ");
	while (*str)
	{
		ft_putchar(*str);
		ft_putchar(c);
		str++;
	}
	ft_putendl(" ;;  debug no crash");
}
