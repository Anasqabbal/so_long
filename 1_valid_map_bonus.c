/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_valid_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:09:07 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/16 13:30:41 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**check_valid_len(int f_len, int fd)
{
	int		i;
	char	**res;
	size_t	len;

	i = -1;
	res = malloc(sizeof(char *) * f_len + 1);
	if (!res)
		return (close(fd), NULL);
	while (++i <= f_len)
	{
		res[i] = get_next_line(fd);
		if (!res[i] || i == f_len - 1)
			break ;
		if (i == 0)
			len = ft_strlen(res[i]);
		else if (i && len != ft_strlen(res[i]))
			return (close(fd), split_free(res, i + 1));
	}
	if (res[i] && len != ft_strlen(res[i]) + 1)
		return (close(fd), split_free(res, i + 1));
	else if (!res[i])
		return (close(fd), split_free(res, i + 1));
	return (close (fd), res);
}

static int	check_all_walls(int f_len, char **res, t_valid *valid)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < f_len)
	{
		len = ft_strlen(res[i]);
		j = 0;
		valid->wall = 0;
		while (res[i][j])
		{
			if (res[i][j] == '1')
				valid->wall++;
			if (res[i][0] != '1' || res[i][len - 2] != '1')
				return (split_free(res, f_len), 0);
			j++;
		}
		if ((i == 0 && valid->wall != len - 1)
			|| (i == f_len - 1 && valid->wall != len))
			return (split_free(res, f_len), 0);
		i++;
	}
	return (1);
}

static int	check_element1(int c, t_valid *valid)
{
	if (c == 'E')
		valid->exit++;
	else if (c == 'C')
		valid->coins++;
	else if (c == 'P')
		valid->player++;
	else if (c == '1')
		valid->wall++;
	else if (c == '0')
		valid->road++;
	else if (c == 'M')
		valid->enemies++;
	else if (c == '\n')
		return (1);
	else
		return (0);
	return (1);
}

int	check_element(int f_len, char **res, t_valid *valid)
{
	int	i;
	int	j;

	i = 0;
	valid->coins = 0;
	valid->exit = 0;
	valid->wall = 0;
	valid->player = 0;
	valid->road = 0;
	valid->enemies = 0;
	while (i < f_len)
	{
		j = 0;
		while (res[i][j])
		{
			if (!check_element1(res[i][j], valid))
				return (split_free(res, f_len), 0);
			j++;
		}
		i++;
	}
	if (valid->exit != 1 || valid->player != 1 || valid->coins == 0
		|| valid->enemies == 0)
		return (split_free(res, f_len), 0);
	return (1);
}

int	check_valid_map(int fd, int ac, char **av, t_win *var)
{
	t_valid	valid;

	if ((the_file_len(fd, &valid) <= 2) || valid.f_len > 128)
		return (ft_printf("Error\nInvalide map"), 0);
	valid.line = check_valid_len(valid.f_len, check_map_name(ac, av));
	if (!valid.line)
		return (ft_printf("Error\nyour map is not rectangular\n"), 0);
	if (!check_all_walls(valid.f_len, valid.line, &valid))
		return (ft_printf("Error\nInvalid Walls in your map\n"), 0);
	if (!check_element(valid.f_len, valid.line, &valid))
		return (ft_printf("Error\nInvalid elements in your map\n"), 0);
	if (!check_valid_road(valid.f_len, valid.line, &valid))
		return (ft_printf("Error\nPlayer can't reach Exit or Coins\n"), 0);
	var->line = valid.line;
	var->f_len = valid.f_len;
	return (1);
}
