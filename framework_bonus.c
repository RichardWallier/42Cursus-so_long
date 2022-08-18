/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framework_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:01:33 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/18 11:04:43 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	refresh(t_data *data)
{
	mlx_clear_window(data->mlx, data->window.ptr);
	map_draw(data);
	player_draw(data);
	collectable_draw(data);
	enemy_draw(data);
	mlx_string_put(data->mlx, data->window.ptr, 56, 24, 0xFFFFFF, "moves: ");
	mlx_string_put(data->mlx, data->window.ptr, 100, 24, 0xFFFFFF,
		ft_itoa(data->player.moves));
}

void	map_draw(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.coordenates[x])
	{
		y = 0;
		while (data->map.coordenates[x][y])
		{
			if (data->map.coordenates[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->window.ptr,
					data->map.wall_image, y * data->map.wall_width,
					x * data->map.wall_height);
			else if (data->map.coordenates[x][y] == 'E')
				mlx_put_image_to_window(data->mlx, data->window.ptr,
					data->map.exit_image, y * data->map.exit_width,
					x * data->map.exit_height);
			else
				mlx_put_image_to_window(data->mlx, data->window.ptr,
					data->map.floor_image, y * data->map.floor_width,
					x * data->map.floor_height);
			y++;
		}
		x++;
	}
}

void	player_draw(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window.ptr,
		data->player.image, data->player.x, data->player.y);
}

void	collectable_draw(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map.coordenates[x])
	{
		y = 0;
		while (data->map.coordenates[x][y])
		{
			if (data->map.coordenates[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->window.ptr,
					data->map.collectable_image,
					(y * data->map.floor_width)
					+ (data->map.collectable_width / 2),
					(x * data->map.floor_height)
					+ (data->map.collectable_height / 2));
			y++;
		}
		x++;
	}
}

void	enemy_draw(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map.coordenates[x])
	{
		y = 0;
		while (data->map.coordenates[x][y])
		{
			if (data->map.coordenates[x][y] == 'X')
				mlx_put_image_to_window(data->mlx, data->window.ptr,
					data->map.enemy_image,
					(y * data->map.floor_width), (x * data->map.enemy_height));
			y++;
		}
		x++;
	}
}
