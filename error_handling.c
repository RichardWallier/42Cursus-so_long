/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:29:20 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/30 08:15:14 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_open_error(void)
{
	ft_printf("ERROR\nInvalid map file : Invalid map file!\n");
	exit(errno);
}

void	map_format_error(char *error)
{
	ft_printf("ERROR\nInvalid map file! : ");
	ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}
