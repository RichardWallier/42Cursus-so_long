/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 04:01:39 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/11 04:01:40 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rows_len(const char *file)
{
	char	*temp;
	int		index;
	int		fd;

	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	index = 0;
	index++;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		index++;
	}
	free(temp);
	close(fd);
	return (index);
}

void	clean_collectable(t_data *data)
{
	data->map.collectable_count--;
	if (data->map.collectable_count == 0)
	{
		if (data->map.exit_image)
			mlx_destroy_image(data->mlx, data->map.exit_image);
		data->map.exit_image = mlx_xpm_file_to_image(data->mlx,
				"./assets/door_open.xpm",
				&data->map.exit_width, &data->map.exit_height);
	}
	data->map.coordenates[data->player.ber_y][data->player.ber_x] = '0';
}

int	game_over(t_data *data)
{
	ft_printf("enemy killed you!\n");
	destroy_all(data);
	return (1);
}

int	get_map(t_data *data)
{
	int	fd_map;
	int	index;

	fd_map = open(data->map.file, O_RDONLY);
	data->map.coordenates = (char **)malloc(sizeof(char *) * data->map.ber_x);
	data->map.coordenates[0] = get_next_line(fd_map);
	index = 0;
	while (data->map.coordenates[index])
	{
		index++;
		data->map.coordenates[index] = get_next_line(fd_map);
	}
	close(fd_map);
	return (1);
}

int	set_player_x_y(t_data *data, int x, int y)
{
	data->player.x = y * 56;
	data->player.y = x * 56;
	data->player.ber_x = y;
	data->player.ber_y = x;
	return (1);
}
