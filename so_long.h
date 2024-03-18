/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:30:19 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/16 13:57:53 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./libft/libft.h"
# include <stdio.h>
# include <mlx.h>

typedef struct s_win
{
	int		w;
	int		h;
	int		f_len;
	char	**line;
	void	*start_mlx;
	void	*wind_mlx;
	void	*coin;
	void	*wall;
	void	*player;
	void	*floor;
	void	*exit;
	int		count;
	int		i;
	int		y;
	int		fd;
}	t_win;

typedef struct s_valid
{
	int		f_len;
	char	**line;
	int		player;
	int		wall;
	int		coins;
	int		exit;
	int		road;
}	t_valid;

typedef struct s_position
{
	int		i;
	int		y;
}	t_position;

int		check_map_name(int ac, char **av);
int		open_map(char *res);
int		check_valid_map(int fd, int ac, char **av, t_win *var);
int		the_file_len(int fd, t_valid *valid);
int		check_valid_road(int f_len, char **res, t_valid *valid);
void	start_the_game(int ac, char **av, t_win *var);
void	implement_the_move(t_win *v, t_position *p1, t_position *p);
void	render_the_map(int fd, t_win *var);
void	*render_element(char *dst, t_win *var, int x, int y);
void	get_position(int f_len, char **res, t_position *element, int indice);
int		check_e_c(int f_len, char **dup, int indice);
void	down_move(t_win *var);
void	up_move(t_win *var);
void	left_move(t_win *var);
void	right_move(t_win *var);
void	ft_exit(t_win *v, int indice);
#endif
