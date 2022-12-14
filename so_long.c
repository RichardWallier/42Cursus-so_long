/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 13:46:08 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/30 08:45:17 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		exit (EXIT_FAILURE);
	data.map.file = argv[1];
	map_check_name(&data);
	data.mlx = mlx_init();
	map_parse(&data);
	data.window.ptr = mlx_new_window(data.mlx, (data.map.ber_y - 1) * TILE_SIZE,
			(data.map.ber_x - 1) * TILE_SIZE, GAME_NAME);
	collectable_parse(&data);
	player_parse(&data);
	map_draw(&data);
	player_draw(&data);
	collectable_draw(&data);
	mlx_do_key_autorepeaton(data.mlx);
	mlx_key_hook(data.window.ptr, keyboard_event, &data);
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
	mlx_destroy_image(data->mlx, data->map.wall_image);
	mlx_destroy_image(data->mlx, data->map.exit_image);
	mlx_destroy_image(data->mlx, data->map.floor_image);
	mlx_destroy_image(data->mlx, data->map.collectable_image);
	mlx_destroy_window(data->mlx, data->window.ptr);
	free(data->mlx);
	exit(0);
}
