/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_open_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:16:59 by anqabbal          #+#    #+#             */
/*   Updated: 2024/02/25 18:29:37 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *open_window(void)
{
	void *start_mlx;
	void *open_win;
	
	start_mlx = mlx_init();
	// if (!start_mlx)
	// 	printf("the pointer of mlx is NULL\n");
	open_win = mlx_new_window(start_mlx, 1920, 1080, "so_long");
	mlx_loop(start_mlx);
	return (open_win);
}