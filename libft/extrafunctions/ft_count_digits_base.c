/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:08:19 by rwallier          #+#    #+#             */
/*   Updated: 2022/08/18 11:08:20 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_digits_base(long long int number, int base)
{
	int	index;

	index = 0;
	if (!number)
		return (1);
	while (number != 0)
	{
		index++;
		number /= base;
	}
	return (index);
}
