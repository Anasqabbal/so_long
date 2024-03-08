/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:39:58 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/07 21:13:34 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_exit(t_win *v, int indice)
{
	split_free(v->line, v->f_len);
	mlx_destroy_image(v->start_mlx, v->floor);
	mlx_destroy_image(v->start_mlx, v->wall);
	mlx_destroy_image(v->start_mlx, v->exit);
	mlx_destroy_image(v->start_mlx, v->player);
	mlx_destroy_image(v->start_mlx, v->coin);
	mlx_destroy_window(v->start_mlx, v->wind_mlx);
	free(v->start_mlx);
	free(v->wind_mlx);
	if (indice == 0)
		exit(0);
	else
		exit (1);
}