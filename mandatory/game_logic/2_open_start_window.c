/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_open_start_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:09:57 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/07 16:44:14 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy(void)
{
	exit(1);
	return (0);
}

void	sl_open_window(t_win	*var)
{
	int	x;
	int	y;
	int	len;

	var->start_mlx = mlx_init();
	if (!var->start_mlx)
	{
		ft_printf("failed in init\n");
		exit (1) ;
	}
	len = ft_strlen(var->line[0]) - 1;
	mlx_xpm_file_to_image(var->start_mlx, "../game_images/wall.xpm", &x, &y);
	var->wind_mlx = mlx_new_window(var->start_mlx,
			len * x, var->f_len * y, "so_long");
	if (!var->wind_mlx)
	{
		ft_printf("var->wind_mlx == NULL");
		exit (1);
	}
}

int	with_keys(int key, t_win *var)
{
	if (key == 53)
		return (ft_destroy());
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

void	start_the_game(int ac, char **av, t_win *var)
{
	t_position e;
	
	sl_open_window(var);
	render_the_map(check_map_name(ac, av), var);
	var->count = 0;
	get_position(var->f_len, var->line, &e, 'E');
	var->i = e.i;
	var->y = e.y;
	printf("the position of exit[%d][%d]\n", var->y, var->i);
	mlx_hook(var->wind_mlx, 2, 0, with_keys, var);
	mlx_hook(var->wind_mlx, 17, 0, ft_destroy, var);
	mlx_loop(var->start_mlx);
}
