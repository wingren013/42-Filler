/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:43:49 by smifsud           #+#    #+#             */
/*   Updated: 2017/02/23 20:57:16 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <bot.h>

#define MP(c) (c == g_piece || c == g_piece + 32)
#define EP(c) (c == g_enemy || c == g_enemy + 32)
#define PIECE(c) (c == 'x' || c == 'X' || c == 'o' || c == 'O')

size_t		*piecechooser(t_game *game, char **piece)
{
	ssize_t	x;
	ssize_t	y;

	x = game->width - 1;
	y = game->height - 1;
	while (1)
	{
		if (game->pieceheight > 1 && y == game->height - 1)
			y -= game->pieceheight - 1;
		while (x + game->piecewidth > game->width)
			x--;
		if (validcheck(x, y, game, piece))
		{
			*game = pieceplacer(x, y, *game, piece);
			return (returnamabobber(x, y, game));
		}
		if (y == 0 && x == 0)
			return (returnamabobber(0, 0, game));
		if (x > 0)
			x--;
		else if (y > 0)
		{
			x = game->width - 1;
			y--;
		}
	}
}

/*
** bottom right move
*/
