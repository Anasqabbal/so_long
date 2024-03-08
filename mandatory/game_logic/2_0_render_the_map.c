/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_0_render_the_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:15:22 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/07 21:26:21 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*render_element(char *dst, t_win *var, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(var->start_mlx, dst, &var->w, &var->h);
	if (!img)
		exit (1);
	if (!(mlx_put_image_to_window(var->start_mlx, var->wind_mlx,
		img, x * var->w, y * var->h)))
			exit (1);
	return (img);
}

void	render_the_row(char *res, t_win *var, int y)
{
	int	i;

	i = 0;
	while (res[i] || res[i] == '\n')
	{
		render_element("../game_images/Stones.xpm", var, i, y);
		if (res[i] == '1')
			var->wall = render_element("../game_images/Wall.xpm", var, i, y);
		else if (res[i] == '0')
			var->floor = render_element("../game_images/Stones.xpm", var, i, y);
		else if (res[i] == 'E')
			var->exit = render_element("../game_images/Exit.xpm", var, i, y);
		else if (res[i] == 'C')
			var->coin = render_element("../game_images/Coins.xpm", var, i, y);
		else if (res [i] == 'P')
			var->player = render_element("../game_images/Character.xpm", var,
					i, y);
		i++;
	}
	if (!var->player || !var->coin || !var->exit || !var->floor)
	{
		ft_printf("Error\n");
		exit (1);
	}
}

void	render_the_map(int fd, t_win *var)
{
	char	*res;
	int		y;

	y = 0;
	var->floor = &y;
	var->wall = &y;
	var->player = &y;
	var->coin = &y;
	var->exit = &y;
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
