/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:01:36 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/30 08:17:41 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parse(t_data *data)
{
	data->map.game_loop = 0;
	data->map.game_frame = 0;
	data->player.moves = 0;
	data->map.ber_x = rows_len(data->map.file);
	get_map(data);
	data->map.ber_y = ft_strlen(data->map.coordenates[0]);
	data->map.floor_width = TILE_SIZE;
	data->map.floor_height = TILE_SIZE;
	data->map.exit_width = TILE_SIZE;
	data->map.exit_height = TILE_SIZE;
	data->map.wall_width = TILE_SIZE;
	data->map.wall_height = TILE_SIZE;
	data->map.floor_image = mlx_xpm_file_to_image(data->mlx,
			"./assets/floor.xpm",
			&data->map.floor_width, &data->map.floor_height);
	data->map.wall_image = mlx_xpm_file_to_image(data->mlx,
			"./assets/wall.xpm",
			&data->map.wall_width, &data->map.wall_height);
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
			{
				set_player_x_y(data, x, y);
			}
			y++;
		}
		x++;
	}
	data->player.width = 48;
	data->player.height = 54;
	data->player.velocity_x = TILE_SIZE;
	data->player.velocity_y = TILE_SIZE;
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
