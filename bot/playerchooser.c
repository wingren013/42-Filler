/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerchooser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:51:39 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/01 15:52:09 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <bot.h>
#include <get_next_line.h>

void	playerchooser(int fd)
{
	char	*buf;

	while (get_next_line(fd, &buf) > 0)
	{
		if (ft_strstr(buf, "filler"))
		{
			if (ft_strstr(buf, "$$$ exec p1"))
			{
				g_enemy = 'X';
				g_piece = 'O';
				free(buf);
				return ;
			}
			else if (ft_strstr(buf, "$$$ exec p2"))
			{
				free(buf);
				g_enemy = 'O';
				g_piece = 'X';
				return ;
			}
		}
	}
}
