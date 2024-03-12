/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_0_render_the_map_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:15:22 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/11 10:40:43 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit(t_win *v, int indice)
{
	split_free(v->line, v->f_len);
	exit (indice);
}

void	*render_element(char *dst, t_win *var, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(var->start_mlx, dst, &var->w, &var->h);
	if (!img)
		ft_exit (var, 1);
	mlx_put_image_to_window(var->start_mlx, var->wind_mlx,
		img, x * var->w, y * var->h);
	return (img);
}

static void	render_the_row2(char *res, t_win *var, int y, int i)
{
	if (res[i] == 'E')
	{
		var->exit = render_element("./textures/Exit.xpm", var, i, y);
		if (!var->exit)
			ft_exit(var, 1);
	}
	else if (res[i] == 'C')
	{
		var->coin = render_element("./textures/coin_rotate_0.xpm", var, i, y);
		if (!var->coin)
			ft_exit(var, 1);
	}
	else if (res [i] == 'P')
	{
		var->player = render_element("./textures/Character.xpm", var, i, y);
		if (!var->player)
			ft_exit(var, 1);
	}
}

static void	render_the_row(char *res, t_win *var, int y)
{
	int	i;

	i = 0;
	while (res[i] || res[i] == '\n')
	{
		if (!render_element("./textures/Stones.xpm", var, i, y))
			ft_exit(var, 1);
		if (res[i] == '1')
		{
			var->wall = render_element("./textures/Wall.xpm", var, i, y);
			if (!var->wall)
				ft_exit(var, 1);
		}
		else if (res[i] == '0')
		{
			var->floor = render_element("./textures/Stones.xpm", var, i, y);
			if (!var->floor)
				ft_exit(var, 1);
		}
		render_the_row2(res, var, y, i);
		i++;
	}
}

void	render_the_map(int fd, t_win *var)
{
	char	*res;
	int		y;

	y = 0;
	var->floor = NULL;
	var->wall = NULL;
	var->player = NULL;
	var->coin = NULL;
	var->exit = NULL;
	while (1)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		render_the_row(res, var, y);
		y++;
		free(res);
	}
}
