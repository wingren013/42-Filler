/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:26:15 by smifsud           #+#    #+#             */
/*   Updated: 2017/03/01 15:52:44 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOT_H
# define BOT_H

# include <libft.h>
# define MP(c) (c == g_piece || c == g_piece + 32)
# define EP(c) (c == g_enemy || c == g_enemy + 32)
# define PIECE(c) (c == 'x' || c == 'X' || c == 'o' || c == 'O')

typedef struct		s_game
{
	size_t			points;
	char			**board;
	ssize_t			width;
	ssize_t			height;
	ssize_t			pieceheight;
	ssize_t			piecewidth;
	size_t			piecex;
	size_t			piecey;
	size_t			savedx;
	int				updown;
	size_t			chosey;
	size_t			chosex;
	ssize_t			widthoffset;
	ssize_t			heightoffset;
}					t_game;

extern char			g_enemy;
extern char			g_piece;

size_t				*piecechooser(t_game *game, char **piece);
char				*shapereader(size_t i, size_t s, int fd, t_game *game);
char				*mapreader(size_t i, size_t s, int fd, t_game *game);
t_game				pieceplacer(size_t x, size_t y, t_game game, char **piece);
int					validcheck(size_t x, size_t y, t_game *game, char **piece);
size_t				*returnamabobber(size_t x, size_t y, t_game *game);
void				playerchooser(int fd);

size_t				*rightchooser(t_game *game, char **piece);
size_t				*downchooser(t_game *game, char **piece);
size_t				*upchooser(t_game *game, char **piece);
size_t				*cornerchooser(t_game *game, char **piece);

#endif
