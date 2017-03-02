/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:24:20 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/01 15:24:22 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bot.h>
#include <printf.h>

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

size_t		*returnamabobber(size_t x, size_t y, t_game *game)
{
	ft_printf("%ld %ld\n", y - game->heightoffset, x - game->widthoffset);
	game->chosey = y;
	game->chosex = x;
	return (0);
}
