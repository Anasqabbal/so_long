/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:32:05 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/11 15:32:06 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*get_a(int nb, char **nb11)
{
	static char	*nb1;
	char		*str;
	char		*str1;

	nb1 = ft_itoa(nb);
	if (!nb1)
		return (NULL);
	str = ft_strjoin("./textures/fire_idle_", nb1);
	if (!str)
		return (NULL);
	str1 = ft_strjoin(str, ".xpm");
	if (!str1)
		return (NULL);
	free(nb1);
	free(str);
	*nb11 = str1;
	return (str1);
}

static int	draw_animation(t_position *en1, t_win *v, int count, int k)
{
	static int	j;
	char		*nb;
	static int	i;

	if (j++ == 1450)
	{
		if (++i < 5)
		{
			while (++k < count)
			{
				if (!get_a(i, &nb))
					return (free(en1), 0);
				if (!(render_element("./textures/Stones.xpm", v,
							en1[k].i, en1[k].y)))
					return (free(en1), 0);
				if (!(render_element(nb, v, en1[k].i, en1[k].y)))
					return (free(en1), 0);
				free(nb);
			}
		}
		j = 0;
	}
	if (i == 5)
		i = -1;
	return (free(en1), 1);
}

static void	*define_positions(int count, t_win *v)
{
	t_position	en;
	t_position	*en1;
	char		**dup;
	int			i;

	i = 0;
	dup = duplicate_res(v->line, v->f_len);
	if (!dup)
		return (NULL);
	en1 = malloc((count + 1) * sizeof(t_position));
	if (!en1)
		return (split_free(dup, v->f_len), NULL);
	while (check_e_c(v->f_len, dup, 'M') == 0)
	{
		get_position(v->f_len, dup, &en, 'M');
		en1[i].i = en.i;
		en1[i].y = en.y;
		dup[en.y][en.i] = '0';
		i++;
	}
	split_free(dup, v->f_len);
	if (!draw_animation(en1, v, count, -1))
		ft_exit(v, 1);
	return (v->line);
}

static int	calculate_enemies(t_win *v)
{
	t_position	en;
	char		**dup;
	int			count;

	count = 0;
	dup = duplicate_res(v->line, v->f_len);
	if (!dup)
		ft_exit (v, 1);
	while (check_e_c(v->f_len, dup, 'M') == 0)
	{
		get_position(v->f_len, dup, &en, 'M');
		dup[en.y][en.i] = '0';
		count++;
	}
	split_free(dup, v->f_len);
	return (count);
}

int	render_enemies(t_win *v)
{
	if (!define_positions(calculate_enemies(v), v))
		ft_exit(v, 1);
	render_coins(v);
	return (1);
}
