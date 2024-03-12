/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:09:48 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/12 09:21:33 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear(t_win *v, int indice)
{
	(void) indice;
	mlx_destroy_image(v->start_mlx, v->coin);
	mlx_destroy_window(v->start_mlx, v->wind_mlx);
}