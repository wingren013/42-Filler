/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 18:51:32 by ebouther          #+#    #+#             */
/*   Updated: 2017/02/15 20:00:03 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_test_placement_core(t_placement *p, t_env *e)
{
	if ((p->pos_content = (e->map)[(p->y_pos * e->b_x) + p->x_pos]) != '.')
	{
		if (p->pos_content == e->letter || p->pos_content == e->letter + 32)
		{
			p->touch++;
			if (p->touch > 1)
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int			ft_test_placement(int i, int n, t_env *e)
{
	t_placement	p;

	p.touch = 0;
	p.x_center = n % e->p_x;
	p.y_center = n / e->p_x;
	p.x_i = i % e->b_x;
	p.y_i = i / e->b_x;
	p.c = 0;
	while ((e->piece)[p.c])
	{
		if ((e->piece)[p.c] == '*')
		{
			p.x_pos = p.x_i + ((p.c % e->p_x) - p.x_center);
			p.y_pos = p.y_i + ((p.c / e->p_x) - p.y_center);
			if ((p.y_pos * e->b_x) + p.x_pos < 0)
				return (0);
			if (ft_test_placement_core(&p, e) == 0)
				return (0);
		}
		p.c++;
	}
	return (1);
}

static void	ft_init_ai(t_ai *s)
{
	s->x_b = 0;
	s->y_b = 0;
	s->x_p = 0;
	s->y_p = 0;
	s->i = 0;
	s->ret = -1;
}

void		ft_ai_core(t_ai *s, t_env *e)
{
	//while piece
	while ((e->piece)[s->n])
	{
		//if piece = *
		if ((e->piece)[s->n] == '*')
		{
			s->x_p = s->n % e->p_x;
			s->y_p = s->n / e->p_x;
			s->x_b = s->i % e->b_x;
			s->y_b = s->i / e->b_x;
			if (((s->ret = ft_test_placement(s->i, s->n, e)) == 1)
					&& ((s->x_b - s->x_p) >= 0)
					&& ((s->y_b - s->y_p) >= 0)
					&& ((s->x_b - s->x_p) + e->p_x < e->b_x)
					&& ((s->y_b - s->y_p) + e->p_y < e->b_y))
				break ;
			else
				s->ret = 0;
		}
		s->n++;
	}
}

void		ft_ai(t_env *e)
{
	t_ai	s;
//init
	ft_init_ai(&s);
	//while map
	while ((e->map)[s.i])
	{
		// if map equals our piece
		if ((e->map)[s.i] == e->letter || (e->map)[s.i] == e->letter + 32)
		{
			s.n = 0;
			//ai core
			ft_ai_core(&s, e);
			if (s.ret == 1)
				break ;
		}
		s.i++;
	}
	s.x = s.x_b - s.x_p;
	s.y = s.y_b - s.y_p;
	ft_putnbr(s.y);
	ft_putchar(' ');
	ft_putnbr(s.x);
	ft_putchar('\n');
}
