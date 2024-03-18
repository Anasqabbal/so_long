/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:23:38 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/18 10:43:23 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	initial_s(t_win *s, int indice)
{
	if (indice == 0)
	{
		s->color = 0x000000;
		s->ci = 0 * s->w + 5;
		s->cy = (s->f_len - 1) * s->h + 30;
	}
	else
	{
		s->color = 0xE32800;
		s->ci = (1 * s->w) + 10;
		s->cy = (s->f_len - 1) * s->h + 30;
	}
}

void	ft_text(t_win *v, int indice)
{
	char	*res;

	if (indice == 0)
	{
		initial_s(v, indice);
		mlx_string_put(v->start_mlx, v->wind_mlx, v->ci,
			v->cy, v->color, "Moves: ");
	}
	else
	{
		initial_s(v, indice);
		++v->count;
		res = ft_itoa(v->count);
		if (!res)
			ft_exit(v, 1);
		mlx_put_image_to_window(v->start_mlx, v->wind_mlx,
			v->wall, 1 * v->w, (v->f_len - 1) * v->h);
		mlx_string_put(v->start_mlx, v->wind_mlx, v->ci, v->cy, v->color, res);
		free(res);
	}
}
