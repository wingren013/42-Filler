/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piecechooser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:26:15 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/01 16:20:59 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bot.h>
#include <libft.h>

size_t		*encirclefour(t_game *game, char **piece)
{
	if (game->updown < 4)
	{
		game->updown += 1;
		return (rightchooser(game, piece));
	}
	else if (game->updown < 6)
	{
		game->updown += 1;
		return (upchooser(game, piece));
	}
	else
	{
		game->updown += 1;
		if (game->updown == 8)
			game->updown = 4;
		return (downchooser(game, piece));
	}
}

size_t		*encirclethree(t_game *game, char **piece)
{
	if (game->updown == 1)
	{
		game->updown = 2;
		return (rightchooser(game, piece));
	}
	else
	{
		game->updown = 1;
		return (cornerchooser(game, piece));
	}
}

size_t		*encircletwo(t_game *game, char **piece)
{
	if (game->updown == 3)
	{
		game->updown = 1;
		return (cornerchooser(game, piece));
	}
	else
	{
		if (game->updown == 2)
			game->updown += 1;
		else
			game->updown = 2;
		return (rightchooser(game, piece));
	}
}

size_t		*encircleone(t_game *game, char **piece)
{
	if (game->updown < 4)
	{
		game->updown += 1;
		return (rightchooser(game, piece));
	}
	else if (game->updown < 6)
	{
		game->updown += 1;
		return (upchooser(game, piece));
	}
	else
	{
		game->updown += 1;
		if (game->updown == 8)
			game->updown = 4;
		return (downchooser(game, piece));
	}
}

size_t		*piecechooser(t_game *game, char **piece)
{
	if (game->width < 90)
	{
		if (MP('x'))
			return (encircleone(game, piece));
		else if (MP('o'))
			return (encircletwo(game, piece));
	}
	else
	{
		if (MP('x'))
			return (encirclethree(game, piece));
		else
			return (encirclefour(game, piece));
	}
	return (upchooser(game, piece));
}
