/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:26:15 by smifsud           #+#    #+#             */
/*   Updated: 2017/01/20 19:35:27 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOT_H
# define BOT_H

# include <libft.h>

typedef struct		s_game
{
	size_t			points;
	char			**board;
	size_t			width;
	size_t			height;
	size_t			pieceheight;
	size_t			piecewidth;
	size_t			piecex;
	size_t			piecey;
	size_t			savedx;
}					t_game;

extern char			g_enemy;
extern char			g_piece;

size_t				*piecechooser(t_game *game, char **piece);
char				*shapereader(size_t i, size_t s, int fd, t_game *game);
char				*mapreader(size_t i, size_t s, int fd, t_game *game);
t_game				pieceplacer(size_t x, size_t y, t_game game, char **piece);

#endif
