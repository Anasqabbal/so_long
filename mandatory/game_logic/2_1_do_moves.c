/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_1_do_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:45:23 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/07 17:08:42 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_exit(t_win *v, t_position *p, int indice)
{
	t_position p1;

	p1 = *p;
	if (indice == 'L')
		p1.i += 1;
	else if (indice == 'R')
		p1.i -= 1;
	else if (indice == 'D')
		p1.y += 1;
	else if (indice == 'U')
		p1.y -= 1;
	v->line[p1.y][p1.i] = 'E';
	v->line[p1.y][p1.i] = 'P';
	mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
		v->floor, p->i * v->w, p->y * v->h);
	mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
		v->exit, p1.i * v->w, p1.y * v->h);
	mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
		v->player, p1.i * v->w, p1.y * v->h);
}
void	apply_moves(t_win *v, t_position *p , int indice)
{
	t_position p1;

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
		v->line[p->y][p->i] = '0';
		v->line[p1.y][p1.i] = 'P';
		mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
			v->floor, p->i * v->w, p->y * v->h);
		mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
			v->player, p1.i * v->w, p1.y * v->h);
	}
	else if (v->line[p1.y][p1.i] != v->line[v->y][v->i])
	{
		v->line[v->y][v->i] = 'E';
		v->line[p1.y][p1.i] = 'P';
		v->line[p->y][p->i] = '0';
		ft_printf("move %d\n", ++v->count);
		if (v->line[p->y][p->i] != v->line[v->y][v->i])
		{
			//printf("value of p -- v->line[%d][%d] == %c --\nvalue of e -- v->line[%d][%d] == %c\n", p->y, p->i,v->line[p->y][p->i],e->y, e->i,v->line[v->y][v->i] );
			mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
				v->floor, p->i * v->w, p->y * v->h);
		}
		mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
			v->player, p1.i * v->w, p1.y * v->h);
	}
}


void	left_move(t_win *v)
{
	t_position p;

	get_position(v->f_len, v->line, &p, 'P');
	if (v->line[p.y][p.i + 1] == 'E')
		if_exit(v, &p, 'L');
	else if (v->line[p.y][p.i + 1] != '1' && v->line[p.y][p.i + 1] != 'E')
		apply_moves(v, &p, 'L');
	if ((check_e_c(v->f_len, v->line, 'C') && v->line[p.y][p.i + 1] == 'E'))
	{
		apply_moves(v, &p, 'L');
		split_free(v->line, v->f_len);
		exit (0);
	}
}

void	right_move(t_win *v)
{
	t_position	p;

	get_position(v->f_len, v->line, &p, 'P');
	if (v->line[p.y][p.i - 1] == 'E')
		if_exit(v, &p, 'R');
	else if (v->line[p.y][p.i - 1] != '1')
		apply_moves(v, &p, 'R');
	if ((check_e_c(v->f_len, v->line, 'C') && v->line[p.y][p.i - 1] == 'E'))
	{
		apply_moves(v, &p, 'R');
		exit(0);
	}
}

void	up_move(t_win *v)
{
	t_position	p;

	get_position(v->f_len, v->line, &p, 'P');
	if (v->line[p.y - 1][p.i] == 'E')
		if_exit(v, &p, 'U');
	else if (v->line[p.y - 1][p.i] != '1')
		apply_moves(v, &p, 'U');
	if ((check_e_c(v->f_len, v->line, 'C') && v->line[p.y - 1][p.i] == 'E'))
	{
		apply_moves(v, &p, 'U');
		exit(0);
	}
}

void	down_move(t_win *v)
{
	t_position	p;

	get_position(v->f_len, v->line, &p, 'P');
	if ((check_e_c(v->f_len, v->line, 'C') && v->line[p.y + 1][p.i] == 'E'))
	{
		apply_moves(v, &p, 'D');
		exit(0);
	}
	else if ( v->line[p.y + 1][p.i] != '1')
		apply_moves(v, &p, 'D');
}
