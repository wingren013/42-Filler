/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieceplacer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:15:32 by smifsud           #+#    #+#             */
/*   Updated: 2017/01/20 19:16:32 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <bot.h>

t_game		pieceplacer(size_t x, size_t y, t_game game, char **piece)
{
	size_t	i;
	size_t	l;
	int		savedx;

	savedx = x;
	i = 0;
	l = 0;
	while (piece[i])
	{
		if (piece[i][l] == '*')
			game.board[y][x] = g_piece + 32;
		l++;
		x++;
		if (piece[i][l] == 0)
		{
			x = savedx;
			l = 0;
			y++;
			i++;
		}
	}
	game.points += 1;
	return (game);
}
