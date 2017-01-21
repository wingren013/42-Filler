/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 12:09:48 by smifsud           #+#    #+#             */
/*   Updated: 2016/11/19 16:29:18 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	clearholder(t_holder *holder)
{
	holder->width = 0;
	holder->prec = 0;
	holder->pound_flag = 0;
	holder->zero_flag = 0;
	holder->minus_flag = 0;
	holder->space_flag = 0;
	holder->plus_flag = 0;
	holder->error = 0;
	holder->wstr = 0;
	holder->size = 0;
	holder->null = 0;
}
