/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:25:07 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/30 09:05:29 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_checker(t_data *data)
{
	char	letters[3];
	int		rows;
	int		cows;
	int		index;

	rows = 0;
	cows = 0;
	index = 0;
	while (data->map.coordenates[rows])
	{
		if (rows > 0)
		{
			if (ft_strlen(data->map.coordenates[rows])
				!= ft_strlen(data->map.coordenates[rows - 1]))
				map_format_error("map isn't rectangle");
		}
		cows = 0;
		while (data->map.coordenates[rows][cows])
			map_check_cow(data, rows, cows++, letters);
		rows++;
	}
	if (letters[0] != 'P' || letters[1] != 'E' || letters[2] != 'C')
		map_format_error("Missing P, E or C char's in map file");
	map_check_border(data, rows, cows);
}

void	map_check_cow(t_data *data, int row, int cow, char *letters)
{
	if (data->map.coordenates[row][cow] == 'P')
	{
		if (letters[0] == 'P')
			map_format_error("Extra P letter in map file");
		else
			letters[0] = data->map.coordenates[row][cow];
	}
	if (data->map.coordenates[row][cow] == 'E')
	{
		if (letters[1] == 'E')
			map_format_error("Extra E letter in map file");
		else
			letters[1] = data->map.coordenates[row][cow];
	}
	if (data->map.coordenates[row][cow] == 'C')
		letters[2] = data->map.coordenates[row][cow];
	return ;
}

void	map_check_name(t_data *data)
{
	int	name_len;

	name_len = ft_strlen(data->map.file);
	if (name_len < 5)
		map_format_error("invalid file name");
	name_len--;
	if (!(data->map.file[name_len - 3] == '.'
			&& data->map.file[name_len - 2] == 'b'
			&& data->map.file[name_len - 1] == 'e'
			&& data->map.file[name_len] == 'r'))
		map_format_error("File isn't a .ber");
}

void	map_check_border(t_data *data, int rows_lenght, int cows_lenght)
{
	int	index;

	index = 0;
	while (index < cows_lenght - 1)
	{
		if (data->map.coordenates[0][index] != '1')
			map_format_error("map not closed with 1");
		index++;
	}
	index = 1;
	while (index < (rows_lenght - 1))
	{
		if (data->map.coordenates[index][0] != '1')
			map_format_error("map not closed with 1");
		if (data->map.coordenates[index][cows_lenght - 2] != '1')
			map_format_error("map not closed with 1");
		index++;
	}
	index = 0;
	while (index < cows_lenght - 1)
	{
		if (data->map.coordenates[rows_lenght - 1][index] != '1')
			map_format_error("map not closed with 1");
		index++;
	}
}
