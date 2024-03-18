/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_open_start_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:09:57 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/18 10:36:49 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	implement_the_move(t_win *v, t_position *p1, t_position *p)
{
	ft_printf("Move %d\n", ++v->count);
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
	{
		split_free(var->line, var->f_len);
		exit (1);
	}
	len = ft_strlen(var->line[0]) - 1;
	if (!(mlx_xpm_file_to_image(var->start_mlx,
				"./Wall.xpm", &x, &y)))
	{
		split_free(var->line, var->f_len);
		exit (1);
	}
	var->wind_mlx = mlx_new_window(var->start_mlx,
			len * x, var->f_len * y, "./so_long");
	if (!var->wind_mlx)
	{
		split_free(var->line, var->f_len);
		exit (1);
	}
}

int	with_keys(int key, t_win *var)
{
	if (check_e_c(var->f_len, var->line, 'C'))
	{
		if (!(render_element("./Openexit.xpm", var, var->i, var->y)))
			ft_exit(var, 1);
	}
	if (key == 53 || key == 12)
		ft_exit(var, 0);
	else if (key == 124 || key == 2)
		right_move(var);
	else if (key == 123 || key == 0)
		left_move(var);
	else if (key == 126 || key == 13)
		up_move(var);
	else if (key == 125 || key == 1)
		down_move(var);
	return (1);
}

int	destroy(t_win *var)
{
	close(var->fd);
	mlx_destroy_window(var->start_mlx, var->wind_mlx);
	split_free(var->line, var->f_len);
	exit (0);
	return (0);
}

void	start_the_game(int ac, char **av, t_win *var)
{
	t_position	e;

	sl_open_window(var);
	render_the_map(check_map_name(ac, av), var);
	var->count = 0;
	get_position(var->f_len, var->line, &e, 'E');
	var->i = e.i;
	var->y = e.y;
	mlx_hook(var->wind_mlx, 2, 0, with_keys, var);
	mlx_hook(var->wind_mlx, 17, 0, destroy, var);
	mlx_loop(var->start_mlx);
}
