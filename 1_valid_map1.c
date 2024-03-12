/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_valid_map1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:09:00 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/07 16:43:11 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(int f_len, char **res, t_position *element, int indice)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	element->i = 0;
	element->y = 0;
	while (++j < f_len - 1)
	{
		i = 1;
		len = ft_strlen(res[j]);
		while (i < len - 2)
		{
			if (res[j][i] == indice)
			{
				element->i = i;
				element->y = j;
				return ;
			}
			i++;
		}
	}
}

int	it_is_valide(int y, int x, char **res, int f_len)
{
	if (res[y][x] == '1' || res[y][x] == 'V')
		return (0);
	res[y][x] = 'V';
	if (y > 0)
		it_is_valide(y - 1, x, res, f_len);
	if (y < f_len - 1)
		it_is_valide(y + 1, x, res, f_len);
	if (x > 0)
		it_is_valide(y, x - 1, res, f_len);
	if (x < (int)ft_strlen(res[y]) - 1)
		it_is_valide(y, x + 1, res, f_len);
	return (1);
}

char	**duplicate_res(char **res, int f_len)
{
	int		i;
	char	**dup;
	int		len;

	i = 0;
	dup = malloc(sizeof(char *) * f_len + 1);
	if (!dup)
		return (split_free(res, f_len), (char **) NULL);
	while (i < f_len)
	{
		len = ft_strlen(res[i]);
		dup[i] = malloc(sizeof(char) * len + 1);
		if (!dup[i])
			return (split_free(res, f_len), split_free(dup, i), (char **) NULL);
		ft_memcpy(dup[i], (const char *)res[i], len);
		dup[i][len] = '\0';
		i++;
	}
	return (dup);
}

int	check_e_c(int f_len, char **dup, int indice)
{
	int	i;
	int	j;
	int	len;

	j = 1;
	while (j < f_len - 1)
	{
		i = 1;
		len = ft_strlen(dup[j]);
		while (i < len - 2)
		{
			if (dup[j][i] == indice)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_valid_road(int f_len, char **res, t_valid *valid)
{
	t_position	player;
	char		**dup;

	(void)valid;
	get_position(f_len, res, &player, 'P');
	dup = duplicate_res(res, f_len);
	it_is_valide(player.y, player.i, dup, f_len);
	if (!check_e_c(f_len, dup, 'C') || !check_e_c(f_len, dup, 'E'))
		return (split_free(dup, f_len), split_free(res, f_len), 0);
	split_free(dup, f_len);
	return (1);
}
