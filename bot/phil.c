/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:34:00 by smifsud           #+#    #+#             */
/*   Updated: 2017/02/27 16:32:59 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bot.h>
#include <libft.h>
#include <fcntl.h>
#include <get_next_line.h>
#include <printf.h>

#define PIECE(c) (c == 'x' || c == 'X' || c == 'o' || c == 'O')
#define NORMBS(m) i = 0; x = 0; y = 0; MALLOC_GUARD(m)
#define EVIL ret[y][x]= 0; y++; x = 0
#define PM ((game->piecewidth-game->widthoffset)*(game->pieceheight-game->heightoffset))

char	**maptranslate(char *map)
{
	char	**ret;
	size_t	i;
	size_t	x;
	size_t	y;

	NORMBS(map);
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

	NORMBS(piece);
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
	i = 0;
	l = 0;
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

	flag = 0;
	y = 0;
	x = 0;
	game->widthoffset = 0;
	game->heightoffset = 0;
	MALLOC_GUARD(piece);
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
		x = 0;
		y++;
	}
	return (copyover(piece, game, x, y));
}
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

void	showpiece(char **piece)
{
	size_t	y = 0;
	size_t	x = 0;
	while (piece[y])
	{
		while (piece[y][x])
		{
			dprintf(2, "%c", piece[y][x]);
			x++;
		}
		x = 0;
		y++;
		dprintf(2, "\n");
	}
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
		/*
		** for (int i = 0; i < 200000000; i++)
		** i++;
		*/
	}
	return (0);
}
