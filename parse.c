/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:01:36 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/11 04:01:40 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parse(t_data *data)
{
	data->map.game_loop = 0;
	data->map.game_frame = 0;
	data->map.ber_x = rows_len("./map.ber");
	get_map(data);
	data->map.ber_y = ft_strlen(data->map.coordenates[0]);
	data->map.floor_width = 56;
	data->map.floor_height = 56;
	data->map.exit_width = 56;
	data->map.exit_height = 56;
	data->map.wall_width = 56;
	data->map.wall_height = 56;
	data->map.floor_image = mlx_xpm_file_to_image(data->mlx,
			"./assets/floor.xpm",
			&data->map.floor_width, &data->map.floor_height);
	data->map.wall_image = mlx_xpm_file_to_image(data->mlx,
			"./assets/wall.xpm",
			&data->map.wall_width, &data->map.wall_height);
}

void	enemy_parse(t_data *data)
{
	data->map.collectable_width = 48;
	data->map.collectable_height = 54;
	data->map.enemy_image = mlx_xpm_file_to_image(data->mlx,
			"./assets/knight0.xpm",
			&data->map.enemy_width, &data->map.enemy_height);
}

void	collectable_parse(t_data *data)
{
	int	x;
	int	y;

	data->map.collectable_count = 0;
	x = 0;
	y = 0;
	while (data->map.coordenates[x])
	{
		y = 0;
		while (data->map.coordenates[x][y])
		{
			if (data->map.coordenates[x][y] == 'C')
				data->map.collectable_count++;
			y++;
		}
		x++;
	}
	data->map.collectable_width = 28;
	data->map.collectable_height = 28;
	set_collectable_images(data);
}

void	player_parse(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.coordenates[x])
	{
		y = 0;
		while (data->map.coordenates[x][y])
		{
			if (data->map.coordenates[x][y] == 'P')
				set_player_x_y(data, x, y);
			y++;
		}
		x++;
	}
	data->player.width = 48;
	data->player.height = 54;
	data->player.velocity_x = 56;
	data->player.velocity_y = 56;
	data->player.image = mlx_xpm_file_to_image(data->mlx,
			"./assets/demon.xpm",
			&data->player.width, &data->player.height);
}

int	set_collectable_images(t_data *data)
{
	data->map.collectable_image = mlx_xpm_file_to_image(data->mlx,
			"./assets/coin0.xpm",
			&data->map.collectable_width, &data->map.collectable_height);
	if (data->map.collectable_count > 0)
		data->map.exit_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/door_close.xpm",
				&data->map.exit_width, &data->map.exit_height);
	else
		data->map.exit_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/door_open.xpm",
				&data->map.exit_width, &data->map.exit_height);
	return (1);
}
