/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:30:19 by anqabbal          #+#    #+#             */
/*   Updated: 2024/03/12 11:19:59 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdio.h>
# include "./libft/libft.h"
# include <mlx.h>

typedef struct s_valid
{
	int		f_len;
	char	**line;
	int		player;
	int		wall;
	int		coins;
	int		exit;
	int		road;
	int		enemies;
}	t_valid;

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
	t_valid	*ui;
	int		i;
	int		y;
	int		color;
	int		ci;
	int		cy;
}	t_win;

typedef struct s_position
{
	int	i;
	int	y;
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
char	**duplicate_res(char **res, int f_len);
void	get_position(int f_len, char **res, t_position *element, int indice);
int		check_e_c(int f_len, char **dup, int indice);
void	down_move(t_win *var);
void	up_move(t_win *var);
void	left_move(t_win *var);
void	right_move(t_win *var);
void	ft_exit(t_win *v, int indice);
void	ft_text(t_win *s, int indice);
int		render_enemies(t_win *v);
int		render_coins(t_win *v);
#endif