/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:46:08 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/18 10:17:51 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		exit (EXIT_FAILURE);
	data.map.file = argv[1];
	map_check_name(&data);
	data.mlx = mlx_init();
	map_parse(&data);
	data.window.ptr = mlx_new_window(data.mlx, (data.map.ber_y - 1) * 56,
			(data.map.ber_x - 1) * 56, "so_long");
	collectable_parse(&data);
	enemy_parse(&data);
	player_parse(&data);
	map_draw(&data);
	player_draw(&data);
	collectable_draw(&data);
	enemy_draw(&data);
	mlx_do_key_autorepeaton(data.mlx);
	mlx_key_hook(data.window.ptr, keyboard_event, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_hook(data.window.ptr, 17, 0L, destroy_all, &data);
	mlx_loop(data.mlx);
	return (0);
}

int	destroy_all(t_data *data)
{
	int	index;

	index = 0;
	while (data->map.coordenates[index])
	{
		free(data->map.coordenates[index]);
		index++;
	}
	free(data->map.coordenates);
	mlx_destroy_image(data->mlx, data->player.image);
	mlx_destroy_image(data->mlx, data->map.enemy_image);
	mlx_destroy_image(data->mlx, data->map.wall_image);
	mlx_destroy_image(data->mlx, data->map.exit_image);
	mlx_destroy_image(data->mlx, data->map.floor_image);
	mlx_destroy_image(data->mlx, data->map.collectable_image);
	mlx_destroy_window(data->mlx, data->window.ptr);
	free(data->mlx);
	exit(0);
}
