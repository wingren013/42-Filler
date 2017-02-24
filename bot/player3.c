/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:43:49 by smifsud           #+#    #+#             */
/*   Updated: 2017/02/14 18:59:07 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <bot.h>

#define MP(c) (c == g_piece || c == g_piece + 32)
#define EP(c) (c == g_enemy || c == g_enemy + 32)
#define PIECE(c) (c == 'x' || c == 'X' || c == 'o' || c == 'O')

int			validp2(size_t x, size_t y, t_game game, char **piece)
{
	game.piecex += 1;
	x++;
	while (piece[game.piecey])
	{
		if (piece[game.piecey][game.piecex] == '*' && PIECE(game.board[y][x]))
			return (0);
		if (piece[game.piecey][game.piecex] == 0)
		{
			x = game.savedx;
			game.piecex = 0;
			game.piecey += 1;
			y++;
		}
		else
		{
			x++;
			game.piecex += 1;
		}
	}
	return (1);
}

int			validcheck(size_t x, size_t y, t_game *game, char **piece)
{
	game->piecey = 0;
	game->piecex = 0;
	game->savedx = x;
	while (piece[game->piecey])
	{
		if (piece[game->piecey][game->piecex] == '*' && EP(game->board[y][x]))
			return (0);
		if (piece[game->piecey][game->piecex] == '*' && MP(game->board[y][x]))
			break ;
		if (piece[game->piecey][game->piecex] == 0)
		{
			x = game->savedx;
			game->piecex = 0;
			game->piecey += 1;
			y++;
		}
		else
		{
			x++;
			game->piecex += 1;
		}
	}
	if (piece[game->piecey] == 0)
		return (0);
	return (validp2(x, y, *game, piece));
}

size_t		*returnamabobber(size_t x, size_t y)
{
	size_t	*ret;

	PR_MALLOC(ret, size_t*, size_t, 2);
	ret[0] = y;
	ret[1] = x;
	return (ret);
}

size_t		*piecechooser(t_game *game, char **piece)
{
	ssize_t	x;
	ssize_t	y;

	x = 0;
	y = game->height - 1;
	while (1)
	{
		if (game->pieceheight > 1 && y == game->height - 1)
			y -= game->pieceheight - 1;
		if (validcheck(x, y, game, piece))
		{
			*game = pieceplacer(x, y, *game, piece);
			return (returnamabobber(x, y));
		}
		if (x + game->piecewidth > game->width ||
				y - game->pieceheight <= 0)
			return (returnamabobber(0, 0));
		if (x < game->width && x + game->piecewidth < game->width)
			x++;
		else if (y > 0)
		{
			x = 0;
			y--;
		}
	}
}

/*
** bottom left move
*/
