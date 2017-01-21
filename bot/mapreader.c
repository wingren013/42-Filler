/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:55:57 by smifsud           #+#    #+#             */
/*   Updated: 2017/01/20 20:18:46 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <fcntl.h>
#include <bot.h>

#define NOMEMLEAK y = 0; x= 0

void	parse_buf(char *buf, size_t *x, size_t *y)
{
	while (!ISDIGIT(*buf))
		buf++;
	*y = ft_atoi(buf);
	while (*buf != ' ')
		buf++;
	*x = ft_atoi(buf);
}

char	*somethingbeautiful(size_t i, size_t s, size_t y, char *ret)
{
	char	*buf;

	while (i < y)
	{
		get_next_line(0, &buf);
		s += ft_strlen(buf);
		ft_strcat(ret, buf);
		ret[s] = '\n';
		s++;
		free(buf);
		i++;
	}
	return (ret);
}

char	*mapreader(size_t i, size_t s, int fd, t_game *game)
{
	char	*ret;
	char	*buf;
	size_t	x;
	size_t	y;

	NOMEMLEAK;
	get_next_line(fd, &buf);
	parse_buf(buf, &x, &y);
	PR_MALLOC(ret, char*, char, (x + 3 + (y * (6 + x))));
	ft_bzero(ret, (x + 3 + (y * (6 + x))));
	free(buf);
	(*game).width = x;
	(*game).height = y;
	get_next_line(fd, &buf);
	free(buf);
	return (somethingbeautiful(i, s, y, ret));
}

char	*shapereader(size_t i, size_t s, int fd, t_game *game)
{
	char	*ret;
	char	*buf;
	size_t	x;
	size_t	y;

	NOMEMLEAK;
	if (get_next_line(fd, &buf) == 0)
		return (0);
	parse_buf(buf, &x, &y);
	free(buf);
	PR_MALLOC(ret, char*, char, (((x + 1) * y) + 1));
	ft_bzero(ret, (((x + 1) * y) + 1));
	(*game).piecewidth = x;
	(*game).pieceheight = y;
	while (i < y)
	{
		get_next_line(fd, &buf);
		s += ft_strlen(buf);
		ft_strcat(ret, buf);
		ret[s] = '\n';
		s++;
		free(buf);
		i++;
	}
	return (ret);
}
