/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_valid_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:09:14 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/18 10:34:25 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	the_file_len(int fd, t_valid *valid)
{
	char		*res;
	size_t		i;
	size_t		len;

	i = -1;
	len = 0;
	res = (char *)&i;
	valid->f_len = 0;
	while (res)
	{
		i++;
		res = get_next_line(fd);
		if (!res)
			break ;
		len = ft_strlen(res);
		if (len >= 130)
			return (close(fd), 0);
		free(res);
	}
	if (len == 0)
		return (close(fd), 0);
	close(fd);
	valid->f_len = i;
	return (i);
}

int	open_map(char *res)
{
	char	*res1;
	int		fd;

	res1 = ft_strjoin("./", res);
	fd = open(res1, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		free(res1);
		exit (1);
	}
	free(res1);
	return (fd);
}

static int	check_extention(char *map)
{
	int	len;

	len = ft_strlen(map) - 4;
	if (len == 0)
		return (0);
	if (!ft_strncmp(map + len, ".ber", 4))
		return (1);
	else
		return (0);
}

int	check_map_name(int ac, char **av)
{
	(void) ac;
	if (check_extention(av[1]))
		return (open_map(av[1]));
	else
		return (ft_printf("Error\nInvalide extension\n"), OPEN_MAX + 1);
}
