/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_0_render_the_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:15:22 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/14 14:00:17 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_win *v, int indice)
{
	mlx_destroy_window(v->start_mlx, v->wind_mlx);
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

static void	render_the_row(char *res, t_win *var, int y)
{
	int	i;

	i = 0;
	while (res[i] || res[i] == '\n')
	{
		render_element("./textures/Stones.xpm", var, i, y);
		if (res[i] == '1')
			var->wall = render_element("./textures/Wall.xpm", var, i, y);
		else if (res[i] == '0')
			var->floor = render_element("./textures/Stones.xpm", var, i, y);
		else if (res[i] == 'E')
			var->exit = render_element("./textures/Exit.xpm", var, i, y);
		else if (res[i] == 'C')
			var->coin = render_element("./textures/coin_rotate_0.xpm",
					var, i, y);
		else if (res [i] == 'P')
			var->player = render_element("./textures/Character.xpm", var, i, y);
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
