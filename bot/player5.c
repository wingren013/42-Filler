/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 12:43:49 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/01 16:33:43 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <bot.h>

/*
** top right  move
*/

#define FORNORM x = game->width - 1; y = game->height - 1

size_t		*rightchooser(t_game *game, char **piece)
{
	ssize_t	x;
	ssize_t	y;

	x = game->width - 1;
	y = 0;
	while (1)
	{
		while (x + game->piecewidth > game->width)
			x--;
		if (validcheck(x, y, game, piece))
		{
			*game = pieceplacer(x, y, *game, piece);
			return (returnamabobber(x, y, game));
		}
		if (y + game->pieceheight >= game->height ||
				(x == 0 && y == game->height - 1))
			return (returnamabobber(0, 0, game));
		if (x > 0)
			x--;
		else if (y < game->height && y + game->pieceheight <= game->height)
		{
			x = game->width - 1;
			y++;
		}
	}
}

/*
** bottom left move
*/

size_t		*downchooser(t_game *game, char **piece)
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
			return (returnamabobber(x, y, game));
		}
		if (x + game->piecewidth > game->width ||
				y - game->pieceheight <= 0)
			return (returnamabobber(0, 0, game));
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
** top left move
*/

size_t		*upchooser(t_game *game, char **piece)
{
	ssize_t	x;
	ssize_t	y;

	x = 0;
	y = 0;
	while (1)
	{
		if (x + game->piecewidth > game->width ||
				y + game->pieceheight >= game->height)
		{
			return (returnamabobber(0, 0, game));
		}
		if (validcheck(x, y, game, piece))
		{
			*game = pieceplacer(x, y, *game, piece);
			return (returnamabobber(x, y, game));
		}
		if (x < game->width && x + game->piecewidth < game->width)
			x++;
		else if (y < game->height && y + game->pieceheight <= game->height)
		{
			x = 0;
			y++;
		}
	}
}

/*
** bottom right move
*/

size_t		*cornerchooser(t_game *game, char **piece)
{
	ssize_t	x;
	ssize_t	y;

	FORNORM;
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
