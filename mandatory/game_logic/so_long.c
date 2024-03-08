/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:29:41 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/08 12:54:55 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f()
{
	system("leaks so_long");
}

int main(int ac,  char **av)
{
	//atexit(f);
	int		fd;
	t_win	var;
	
	fd = check_map_name(ac, av);
	if (fd > OPEN_MAX)
		return (1);
	if (!check_valid_map(fd, ac, av, &var))
		return(1);
	start_the_game(ac, av, &var);
	close (fd);
	return (0);
}
