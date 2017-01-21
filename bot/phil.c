/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:34:00 by smifsud           #+#    #+#             */
/*   Updated: 2017/01/20 20:21:51 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bot.h>
#include <libft.h>
#include <fcntl.h>
#include <get_next_line.h>
#include <printf.h>

#define PIECE(c) (c == 'x' || c == 'X' || c == 'o' || c == 'O')
#define NORMBS i = 0; x = 0; y = 0
#define EVIL ret[y][x]= 0; y++; x = 0

char	**maptranslate(char *map)
{
	char	**ret;
	size_t	i;
	size_t	x;
	size_t	y;

	NORMBS;
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

	NORMBS;
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

int		main(void)
{
	t_game	*game;
	char	**piece;
	size_t	*coords;

	playerchooser(0);
	PR_MALLOC(game, t_game*, t_game, 1);
	while (1)
	{
		game->board = maptranslate(mapreader(0, 0, 0, game));
		if (game->board == 0)
			return (0);
		piece = piecetranslate(shapereader(0, 0, 0, game));
		if (piece == 0)
			return (0);
		coords = piecechooser(game, piece);
		ft_printf("%ld %ld\n", coords[0], coords[1]);
		free(game->board);
	}
	return (0);
}
