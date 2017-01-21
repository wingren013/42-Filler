/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smifsud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:56 by smifsud           #+#    #+#             */
/*   Updated: 2016/12/15 15:45:10 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define STOR(val) (*stor)->val

static int	eol(t_stor *stor)
{
	while (stor->n > stor->str - stor->spill && *(stor->str) != '\n')
		(stor->str)++;
	if (*(stor->str) == '\n')
		return (stor->n > stor->str - stor->spill);
	return (0);
}

static int	increase_spill(t_stor *stor)
{
	char	*new_spill;
	ssize_t	new_size;

	new_size = stor->len * 2;
	if (new_size < stor->len + BUFF_SIZE)
		new_size += BUFF_SIZE;
	new_spill = (char*)malloc(sizeof(char) * (new_size + 1));
	MALLOC_GUARD(new_spill);
	ft_strcpy(new_spill, stor->spill);
	new_spill[new_size] = 0;
	stor->str = new_spill + (stor->str - stor->spill);
	free(stor->spill);
	stor->spill = new_spill;
	stor->len = new_size;
	return (1);
}

static int	setup(t_stor **stor)
{
	*stor = (t_stor*)malloc(sizeof(t_stor) * 1);
	MALLOC_GUARD(*stor);
	STOR(len) = BUFF_SIZE;
	STOR(spill) = (char*)malloc(sizeof(char) * (STOR(len) + 1));
	MALLOC_GUARD(STOR(spill));
	(*stor)->spill[(*stor)->len] = 0;
	STOR(n) = 0;
	STOR(str) = STOR(spill);
	STOR(x) = 1;
	return (1);
}

static int	returns(t_stor **ptr, t_stor *stor, char **line)
{
	if (stor->x < 0)
		return (-1);
	*line = ft_strsub(stor->spill, 0, stor->str - stor->spill);
	if (stor->x <= 0 && stor->n <= 0)
	{
		if (stor->spill)
			free(stor->spill);
		free(stor);
		*ptr = 0;
		return (0);
	}
	stor->n += stor->spill - stor->str
		- (stor->x > 0 && *(stor->str) == '\n' && stor->n !=
				stor->str - stor->spill);
	ft_memcpy(stor->spill, stor->str + 1, stor->n);
	stor->str = stor->spill;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_stor	*stor[MAX_FD];

	if (fd >= MAX_FD || fd < 0 || line == 0)
		return (-1);
	if (stor[fd] && (stor[fd])->x == 0)
		return (0);
	if (!(stor[fd]) && !(setup(&(stor[fd]))))
		return (-1);
	while (stor[fd]->x > 0 && !(eol(stor[fd])))
	{
		while ((stor[fd])->n + BUFF_SIZE > (stor[fd])->len)
			if (!(increase_spill(stor[fd])))
				return (-1);
		(stor[fd])->x = read(fd, (stor[fd])->spill + (stor[fd])->n,
				BUFF_SIZE);
		(stor[fd])->n += (stor[fd])->x;
	}
	return (returns(&(stor[fd]), stor[fd], line));
}
