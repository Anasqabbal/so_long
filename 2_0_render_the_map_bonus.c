/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_0_render_the_map_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:15:22 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/18 10:35:24 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit(t_win *v, int indice)
{
	close(v->fd);
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

static void	render_the_row(char *res, t_win *v, int y)
{
	int	i;

	i = 0;
	while (res[i] || res[i] == '\n')
	{
		render_element("./Stones.xpm", v, i, y);
		if (res[i] == '1')
			v->wall = render_element("./Wall.xpm", v, i, y);
		else if (res[i] == '0')
			v->floor = render_element("./Stones.xpm", v, i, y);
		else if (res[i] == 'E')
			v->exit = render_element("./Exit.xpm", v, i, y);
		else if (res[i] == 'C')
			v->coin = render_element("./coin_rotate_0.xpm",
					v, i, y);
		else if (res [i] == 'P')
			v->player = render_element("./Character.xpm",
					v, i, y);
		else if (res [i] == 'M')
			render_element("./fire_idle_0.xpm", v, i, y);
		else if (!mlx_xpm_file_to_image(v->start_mlx,
				"./Openexit.xpm", &v->w, &v->h))
			ft_exit(v, 1);
		i++;
	}
}

void	render_the_map(int fd, t_win *var)
{
	char	*res;
	int		y;

	y = 0;
	var->fd = fd;
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
