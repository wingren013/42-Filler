/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:34:00 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/01 16:36:01 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bot.h>
#include <libft.h>
#include <fcntl.h>
#include <get_next_line.h>
#include <printf.h>

#define PIECE(c) (c == 'x' || c == 'X' || c == 'o' || c == 'O')
#define NORMBS(i, x, y, m) i = 0; x = 0; y = 0; MALLOC_GUARD(m)
#define EVIL ret[y][x]= 0; y++; x = 0
#define PM ((game->piecewidth-game->widthoffset)*BS)
#define BS (game->pieceheight-game->heightoffset)
#define INC x = 0; y++
#define NORMER NORMBS(flag, x, y, piece); BSER
#define BSER game->widthoffset = 0; game->heightoffset = 0

char	**maptranslate(char *map)
{
	char	**ret;
	size_t	i;
	size_t	x;
	size_t	y;

	NORMBS(i, x, y, map);
	PR_MALLOC(ret, char**, char*, ft_strlen(map) + 2);
	PR_MALLOC(ret[y], char*, char, ft_strlen(map) + 2);
	while (map[i])
	{
		if (map[i] == '\n')
		{
			EVIL;
			PR_MALLOC(ret[y], char*, char, ft_strlen(map) + 2);
		}
		else if (PIECE(map[i]) || map[i] == '.')
		{
			ret[y][x] = map[i];
			x++;
		}
		i++;
	}
	ret[y] = 0;
	return (ret);
}

char	**piecetranslate(char *piece)
{
	char	**ret;
	size_t	i;
	size_t	x;
	size_t	y;

	NORMBS(i, x, y, piece);
	MALLOC_GUARD(piece);
	PR_MALLOC(ret, char**, char*, ft_strlen(piece) + 2);
	PR_MALLOC(ret[y], char*, char, ft_strlen(piece) + 2);
	while (piece[i])
	{
		if (piece[i] == '\n')
		{
			EVIL;
			PR_MALLOC(ret[y], char*, char, ft_strlen(piece) + 2);
		}
		else
		{
			ret[y][x] = piece[i];
			x++;
		}
		i++;
	}
	ret[y] = 0;
	return (ret);
}

char	**copyover(char **piece, t_game *game, ssize_t x, ssize_t y)
{
	char	**ret;
	ssize_t	i;
	ssize_t	l;

	NORMBS(i, l, i, piece);
	x = game->widthoffset;
	y = game->heightoffset;
	PR_MALLOC(ret, char**, char*, PM + 1);
	while (piece[y])
	{
		PR_MALLOC(ret[i], char*, char, game->piecewidth + 1);
		while (piece[y][x])
		{
			ret[i][l] = piece[y][x];
			x++;
			l++;
		}
		ret[i][l] = 0;
		x = game->widthoffset;
		l = 0;
		y++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	**pieceparse(char **piece, t_game *game)
{
	ssize_t	x;
	ssize_t	y;
	int		flag;

	NORMER;
	while (piece[y])
	{
		while (piece[y][x])
		{
			if (piece[y][x] == '*')
			{
				if (flag != 1)
				{
					game->heightoffset = y;
					game->widthoffset = x;
					flag = 1;
				}
				if (x < game->widthoffset)
					game->widthoffset = x;
			}
			x++;
		}
		INC;
	}
	return (copyover(piece, game, x, y));
}

int		main(void)
{
	t_game	*game;
	char	**piece;

	playerchooser(0);
	PR_MALLOC(game, t_game*, t_game, 1);
	game->updown = 0;
	while (1)
	{
		game->board = maptranslate(mapreader(0, 0, 0, game));
		if (game->board == 0)
			return (0);
		piece = piecetranslate(shapereader(0, 0, 0, game));
		if (piece == 0)
			return (0);
		piece = pieceparse(piece, game);
		piecechooser(game, piece);
		free(game->board);
	}
	return (0);
}
