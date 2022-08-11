/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:01:25 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/11 04:01:26 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyboard_event(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		destroy_all(data);
	if (keycode == W_KEY)
		player_w(data);
	else if (keycode == A_KEY)
		player_a(data);
	else if (keycode == S_KEY)
		player_s(data);
	else if (keycode == D_KEY)
		player_d(data);
	if (data->map.coordenates[data->player.ber_y][data->player.ber_x] == 'C')
		clean_collectable(data);
	if (data->map.coordenates[data->player.ber_y][data->player.ber_x] == 'E'
		&& data->map.collectable_count == 0)
		destroy_all(data);
	refresh(data);
	return (0);
}

int	player_w(t_data *data)
{
	if (data->map.coordenates[data->player.ber_y - 1]
		[data->player.ber_x] == '1')
		return (1);
	if (data->map.coordenates[data->player.ber_y - 1]
		[data->player.ber_x] == 'X')
		game_over(data);
	data->player.ber_y--;
	data->player.y -= data->player.velocity_y;
	return (1);
}

int	player_a(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player.image);
	data->player.image = mlx_xpm_file_to_image(data->mlx,
			"./assets/demon_reflect.xpm",
			&data->player.width, &data->player.height);
	if (data->map.coordenates[data->player.ber_y]
		[data->player.ber_x - 1] == '1')
		return (1);
	if (data->map.coordenates[data->player.ber_y]
		[data->player.ber_x - 1] == 'X')
		game_over(data);
	data->player.ber_x--;
	data->player.x -= data->player.velocity_x;
	return (1);
}

int	player_s(t_data *data)
{
	if (data->map.coordenates[data->player.ber_y + 1]
		[data->player.ber_x] == '1')
		return (1);
	if (data->map.coordenates[data->player.ber_y + 1]
		[data->player.ber_x] == 'X')
		game_over(data);
	data->player.ber_y++;
	data->player.y += data->player.velocity_y;
	return (1);
}

int	player_d(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player.image);
	data->player.image = mlx_xpm_file_to_image(data->mlx, "./assets/demon.xpm",
			&data->player.width, &data->player.height);
	if (data->map.coordenates[data->player.ber_y]
		[data->player.ber_x + 1] == '1')
		return (1);
	if (data->map.coordenates[data->player.ber_y]
		[data->player.ber_x + 1] == 'X')
		game_over(data);
	data->player.ber_x++;
	data->player.x += data->player.velocity_x;
	return (1);
}
