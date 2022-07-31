#include "so_long.h"
#include <fcntl.h>
#include "mlx.h"

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
	return (index);
}

void	map_parse(t_data *data)
{
	int	fd_map;
	int	index;

	fd_map = open("./map.ber", O_RDONLY);
	data->map.ber_x = rows_len("./map.ber") - 1;
	data->map.coordenates = (char **)malloc(sizeof(char *) * data->map.ber_x);
	data->map.coordenates[0] = get_next_line(fd_map);
	data->map.ber_y = ft_strlen(data->map.coordenates[0]) - 1;
	data->map.floor_width = 56;
	data->map.floor_height = 56;
	data->map.exit_width = 56;
	data->map.exit_height = 56;
	data->map.wall_width = 56;
	data->map.wall_height = 56;
	index = 0;
	while (data->map.coordenates[index])
	{
		index ++;
		data->map.coordenates[index] = get_next_line(fd_map);
	}
}

void	map_draw(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->map.floor_image = mlx_xpm_file_to_image(data->mlx, "./assets/floor.xpm", &data->map.floor_width, &data->map.floor_height);
	data->map.wall_image = mlx_xpm_file_to_image(data->mlx, "./assets/wall.xpm", &data->map.wall_width, &data->map.wall_height);
	if (data->map.collectable_count > 0)
		data->map.exit_image = mlx_xpm_file_to_image(data->mlx, "./assets/door_close.xpm", &data->map.exit_width, &data->map.exit_height);
	else
		data->map.exit_image = mlx_xpm_file_to_image(data->mlx, "./assets/door_open.xpm", &data->map.exit_width, &data->map.exit_height);
	while (data->map.coordenates[x])
	{
		y = 0;
		while (data->map.coordenates[x][y])
		{
			if (data->map.coordenates[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->window.ptr, data->map.wall_image, y * data->map.wall_width, x * data->map.wall_height);
			else if (data->map.coordenates[x][y] == '0' || data->map.coordenates[x][y] == 'P' || data->map.coordenates[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->window.ptr, data->map.floor_image, y * data->map.floor_width, x * data->map.floor_height);
			else if (data->map.coordenates[x][y] == 'E')
				mlx_put_image_to_window(data->mlx, data->window.ptr, data->map.exit_image, y * data->map.exit_width, x * data->map.exit_height);
			y++;
		}
		x++;
	}
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
	data->map.collectable_image = mlx_xpm_file_to_image(data->mlx, "./assets/coin.xpm", &data->map.collectable_width, &data->map.collectable_height);
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
				mlx_put_image_to_window(data->mlx, data->window.ptr, data->map.collectable_image, (y * data->map.floor_width) + (data->map.collectable_width / 2), (x * data->map.floor_height) + (data->map.collectable_height / 2));
			y++;
		}
		x++;
	}
}

void	player_parse(t_data *data)
{
	int	index;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map.coordenates[x])
	{
		y = 0;
		while (data->map.coordenates[x][y])
		{
			if (data->map.coordenates[x][y] == 'P')
			{
				data->player.x = y * 56;
				data->player.y = x * 56;
				data->player.ber_x = y;
				data->player.ber_y = x;
			}
			y++;
		}
		x++;
	}
	data->player.width = 48;
	data->player.height = 54;
	data->player.velocity_x = 56;
	data->player.velocity_y = 56;
	data->player.image = mlx_xpm_file_to_image(data->mlx, "./assets/demon.xpm", &data->player.width, &data->player.height);
}

void	player_draw(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->window.ptr, data->player.image, data->player.x, data->player.y);
}

void	destroy_all(t_data *data)
{
	int	index;

	index = 0;
	while(data->map.coordenates[index])
	{
		free(data->map.coordenates[index]);
		index++;
	}
	free(data->map.coordenates);
	free(data->map.floor_image);
	free(data->map.wall_image);
	free(data->player.image);
	mlx_destroy_image(data->mlx, data->window.ptr);
	free(data->mlx);
	exit(0);
}

void	refresh(t_data *data)
{
	mlx_clear_window(data->mlx, data->window.ptr);
	map_draw(data);
	player_draw(data);
	collectable_draw(data);
}

void	end(t_data *data)
{
	mlx_clear_window(data->mlx, data->window.ptr);
	destroy_all(data);
}

void	clean_collectable(t_data *data)
{
	data->map.collectable_count--;
	data->map.coordenates[data->player.ber_y][data->player.ber_x] = '0';
}

int	keyboard_event(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		destroy_all(data);
	if (keycode == W_KEY)
	{
		if (data->map.coordenates[data->player.ber_y - 1][data->player.ber_x] == '1')
			return (1);
		data->player.ber_y--;
		data->player.y -= data->player.velocity_y;
	}
	else if (keycode == A_KEY)
	{
		if (data->map.coordenates[data->player.ber_y][data->player.ber_x - 1] == '1')
			return (1);
		data->player.ber_x--;
		data->player.x -= data->player.velocity_x;
	}
	else if (keycode == S_KEY)
	{
		if (data->map.coordenates[data->player.ber_y + 1][data->player.ber_x] == '1')
			return (1);
		data->player.ber_y++;
		data->player.y += data->player.velocity_y;
	}
	else if (keycode == D_KEY)
	{
		if (data->map.coordenates[data->player.ber_y][data->player.ber_x + 1] == '1')
			return (1);
		data->player.ber_x++;
		data->player.x += data->player.velocity_x;
	}
	if (data->map.coordenates[data->player.ber_y][data->player.ber_x] == 'C')
		clean_collectable(data);
	if (data->map.coordenates[data->player.ber_y][data->player.ber_x] == 'E' && data->map.collectable_count == 0)
		end(data);
	refresh(data);
	return (0);
}

int	main(void)
{
	t_data	data;
	char	*temp;
	int		fd_map;
	int		index;

	data.mlx = mlx_init();
	map_parse(&data);
	data.window.ptr = mlx_new_window(data.mlx, data.map.ber_y * 56, data.map.ber_x * 56, "Hello Magrao");
	collectable_parse(&data);
	player_parse(&data);
	map_draw(&data);
	player_draw(&data);
	collectable_draw(&data);
	mlx_key_hook(data.window.ptr, keyboard_event, &data);
	mlx_loop(data.mlx);
	return (0);
}
