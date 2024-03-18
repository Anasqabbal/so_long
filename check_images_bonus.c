/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:59:48 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/18 10:37:06 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	valid_coins(t_win *v)
{
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./coin_rotate_0.xpm", &v->w, &v->h))
		ft_exit(v, 1);
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./coin_rotate_1.xpm", &v->w, &v->h))
		ft_exit(v, 1);
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./coin_rotate_2.xpm", &v->w, &v->h))
		ft_exit(v, 1);
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./coin_rotate_3.xpm", &v->w, &v->h))
		ft_exit(v, 1);
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./coin_rotate_4.xpm", &v->w, &v->h))
		ft_exit(v, 1);
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./coin_rotate_5.xpm", &v->w, &v->h))
		ft_exit(v, 1);
}

void	valid_images_bonus(t_win *v)
{
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./fire_idle_0.xpm", &v->w, &v->h))
		ft_exit(v, 1);
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./fire_idle_1.xpm", &v->w, &v->h))
		ft_exit(v, 1);
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./fire_idle_2.xpm", &v->w, &v->h))
		ft_exit(v, 1);
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./fire_idle_3.xpm", &v->w, &v->h))
		ft_exit(v, 1);
	if (!mlx_xpm_file_to_image(v->start_mlx,
			"./fire_idle_4.xpm", &v->w, &v->h))
		ft_exit(v, 1);
	valid_coins(v);
}
