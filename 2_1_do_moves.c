/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_1_do_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:45:23 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/10 14:45:55 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	apply_moves(t_win *v, t_position *p, int indice)
{
	t_position	p1;

	p1 = *p;
	if (indice == 'L')
		p1.i += 1;
	else if (indice == 'R')
		p1.i -= 1;
	else if (indice == 'D')
		p1.y += 1;
	else if (indice == 'U')
		p1.y -= 1;
	if (v->line[p1.y][p1.i] == v->line[v->y][v->i])
	{
		ft_printf("Move %d\n", ++v->count);
		v->line[p->y][p->i] = '0';
		v->line[p1.y][p1.i] = 'P';
		mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
			v->floor, p->i * v->w, p->y * v->h);
		mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
			v->player, p1.i * v->w, p1.y * v->h);
	}
	else if (v->line[p1.y][p1.i] != v->line[v->y][v->i])
		implement_the_move(v, &p1, p);
}

void	left_move(t_win *v)
{
	t_position	p;

	get_position(v->f_len, v->line, &p, 'P');
	if ((v->line[p.y][p.i + 1] == 'E' || v->line[p.y][p.i] == 'E')
		&& check_e_c(v->f_len, v->line, 'C'))
	{
		ft_printf("You win");
		ft_exit(v, 0);
	}
	if (v->line[p.y][p.i + 1] != '1')
		apply_moves(v, &p, 'L');
}

void	right_move(t_win *v)
{
	t_position	p;

	get_position(v->f_len, v->line, &p, 'P');
	if ((v->line[p.y][p.i - 1] == 'E' || v->line[p.y][p.i] == 'E')
		&& check_e_c(v->f_len, v->line, 'C'))
	{
		ft_printf("You win");
		ft_exit(v, 0);
	}
	if (v->line[p.y][p.i - 1] != '1')
		apply_moves(v, &p, 'R');
}

void	up_move(t_win *v)
{
	t_position	p;

	get_position(v->f_len, v->line, &p, 'P');
	if ((v->line[p.y - 1][p.i] == 'E' || v->line[p.y][p.i] == 'E')
		&& check_e_c(v->f_len, v->line, 'C'))
	{
		ft_printf("You win");
		ft_exit(v, 0);
	}
	if (v->line[p.y - 1][p.i] != '1')
		apply_moves(v, &p, 'U');
}

void	down_move(t_win *v)
{
	t_position	p;

	get_position(v->f_len, v->line, &p, 'P');
	if ((v->line[p.y + 1][p.i] == 'E' || v->line[p.y][p.i] == 'E')
		&& check_e_c(v->f_len, v->line, 'C'))
	{
		ft_printf("You win");
		ft_exit(v, 0);
	}
	if (v->line[p.y + 1][p.i] != '1')
		apply_moves(v, &p, 'D');
}
