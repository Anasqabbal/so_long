/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_open_start_window_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:09:57 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/11 14:14:10 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	implement_the_move(t_win *v, t_position *p1, t_position *p)
{
	ft_text(v, 1);
	v->line[p1->y][p1->i] = 'P';
	v->line[p->y][p->i] = '0';
	v->line[v->y][v->i] = 'E';
	if (v->line[p->y][p->i] != v->line[v->y][v->i])
		mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
			v->floor, p->i * v->w, p->y * v->h);
	if (v->line[p->y][p->i] == v->line[v->y][v->i])
	{
		mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
			v->floor, p->i * v->w, p->y * v->h);
		mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
			v->exit, p->i * v->w, p->y * v->h);
	}
	mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
		v->floor, p1->i * v->w, p1->y * v->h);
	mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
		v->player, p1->i * v->w, p1->y * v->h);
}

void	sl_open_window(t_win	*var)
{
	int	x;
	int	y;
	int	len;

	var->start_mlx = mlx_init();
	if (!var->start_mlx)
		exit (1);
	len = ft_strlen(var->line[0]) - 1;
	if (!(mlx_xpm_file_to_image(var->start_mlx, "./textures/Wall.xpm", &x, &y)))
		ft_exit(var, 1);
	var->wind_mlx = mlx_new_window(var->start_mlx,
			len * x, var->f_len * y, "./so_long");
	if (!var->wind_mlx)
		exit (1);
}

int	with_keys(int key, t_win *var)
{
	if (check_e_c(var->f_len, var->line, 'C'))
	{
		if (!(render_element("./textures/Openexit.xpm", var, var->i, var->y)))
			ft_exit(var, 1);
	}
	if (key == 53 || key == 12)
		ft_exit(var, 0);
	else if (key == 124 || key == 2)
		left_move(var);
	else if (key == 123 || key == 0)
		right_move(var);
	else if (key == 126 || key == 13)
		up_move(var);
	else if (key == 125 || key == 1)
		down_move(var);
	return (1);
}

int	destroy(void)
{
	exit (0);
	return (0);
}

void	start_the_game(int ac, char **av, t_win *v)
{
	t_position	e;

	sl_open_window(v);
	render_the_map(check_map_name(ac, av), v);
	v->count = 0;
	get_position(v->f_len, v->line, &e, 'E');
	v->i = e.i;
	v->y = e.y;
	ft_text(v, 0);
	mlx_hook(v->wind_mlx, 2, 0, with_keys, v);
	mlx_loop_hook(v->start_mlx, render_enemies, v);
	mlx_hook(v->wind_mlx, 17, 0, destroy, v);
	mlx_loop(v->start_mlx);
}
