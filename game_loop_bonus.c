/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:01:28 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/18 09:16:10 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	game_loop(t_data *data)
{
	if (data->map.game_loop < 2100)
	{
		data->map.game_loop++;
		return (1);
	}
	if (!data->window.ptr)
		ft_printf("close window\n");
	data->map.game_loop = 0;
	change_coin_image(data);
	change_enemy_image(data);
	if (data->map.game_frame >= 3)
		data->map.game_frame = 0;
	else
		data->map.game_frame++;
	refresh(data);
	return (0);
}

int	change_coin_image(t_data *data)
{
	mlx_destroy_image(data->mlx, data->map.collectable_image);
	if (data->map.game_frame == 0)
		data->map.collectable_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/coin0.xpm",
				&data->map.collectable_width, &data->map.collectable_height);
	else if (data->map.game_frame == 1)
		data->map.collectable_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/coin1.xpm",
				&data->map.collectable_width, &data->map.collectable_height);
	else if (data->map.game_frame == 2)
		data->map.collectable_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/coin2.xpm",
				&data->map.collectable_width, &data->map.collectable_height);
	else if (data->map.game_frame == 3)
		data->map.collectable_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/coin3.xpm",
				&data->map.collectable_width, &data->map.collectable_height);
	return (1);
}

int	change_enemy_image(t_data *data)
{
	mlx_destroy_image(data->mlx, data->map.enemy_image);
	if (data->map.game_frame == 0)
		data->map.enemy_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/knight0.xpm",
				&data->map.enemy_width, &data->map.enemy_height);
	else if (data->map.game_frame == 1)
		data->map.enemy_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/knight1.xpm",
				&data->map.enemy_width, &data->map.enemy_height);
	else if (data->map.game_frame == 2)
		data->map.enemy_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/knight2.xpm",
				&data->map.enemy_width, &data->map.enemy_height);
	else if (data->map.game_frame == 3)
		data->map.enemy_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/knight3.xpm",
				&data->map.enemy_width, &data->map.enemy_height);
	return (1);
}
