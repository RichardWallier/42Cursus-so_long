/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:03:47 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/18 12:35:39 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1 
# define D_KEY 2
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define ESC_KEY 53

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "./minilibx/mlx.h"
# include "libft/libft.h"

typedef struct s_player
{
	void	*image;
	int		ber_x;
	int		ber_y;
	int		x;
	int		y;
	int		width;
	int		height;
	int		velocity_x;
	int		velocity_y;
	int		moves;
}				t_player;

typedef struct s_window
{
	void	*ptr;
	int		width;
	int		height;
}				t_window;

typedef struct s_map
{
	char	*file;
	char	**coordenates;
	void	*wall_image;
	int		game_loop;
	int		game_frame;
	int		wall_width;
	int		wall_height;
	void	*exit_image;
	int		exit_width;
	int		exit_height;
	void	*floor_image;
	int		floor_width;
	int		floor_height;
	void	*collectable_image;
	int		collectable_count;
	int		collectable_width;
	int		collectable_height;
	void	*enemy_image;
	int		ber_x;
	int		ber_y;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	t_window	window;
	t_map		map;
	t_player	player;
}				t_data;

int		rows_len(const char *file);

int		get_map(t_data *data);

void	map_parse(t_data *data);

void	enemy_parse(t_data *data);

int		set_collectable_images(t_data *data);

void	collectable_parse(t_data *data);

int		set_player_x_y(t_data *data, int x, int y);

void	player_parse(t_data *data);

void	map_draw(t_data *data);

void	enemy_draw(t_data *data);

void	collectable_draw(t_data *data);

void	player_draw(t_data *data);

void	refresh(t_data *data);

int		end(t_data *data);

int		destroy_all(t_data *data);

void	clean_collectable(t_data *data);

int		game_over(t_data *data);

int		change_coin_image(t_data *data);

int		change_enemy_image(t_data *data);

int		game_loop(t_data *data);

int		player_w(t_data *data);

int		player_a(t_data *data);

int		player_s(t_data *data);

int		player_d(t_data *data);

int		keyboard_event(int keycode, t_data *data);

void	map_checker(t_data *data);

void	map_open_error(void);

void	map_format_error(char *error);

void	map_check_cow(t_data *data, int row, int cow, char *letters);

void	map_check_name(t_data *data);

void	map_check_border(t_data *data, int rows_lenght, int cows_lenght);

#endif
