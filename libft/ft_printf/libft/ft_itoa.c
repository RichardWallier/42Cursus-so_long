/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:30:09 by rwallier          #+#    #+#             */
/*   Updated: 2022/05/18 12:04:06 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlcat_nonnull(char *dest, const char *src, size_t maxlen)
{
	unsigned int	dsize;
	unsigned int	index;

	if (maxlen <= ft_strlen(dest))
		return (maxlen + ft_strlen(src));
	dsize = ft_strlen(dest);
	if (dsize > 1)
		dsize--;
	index = 0;
	while (src[index] && dsize < maxlen - 1)
		dest[dsize++] = src[index++];
	return (ft_strlen(dest) + ft_strlen(&src[index]));
}

static	void	ft_writenbr(unsigned int nb, char *strnbr, size_t maxsize)
{
	char	character;

	character = '\0';
	if (nb < 10)
	{
		character = nb + 48;
		ft_strlcat_nonnull(strnbr, &character, maxsize);
		return ;
	}
	else
		ft_writenbr(nb / 10, strnbr, maxsize);
	ft_writenbr(nb % 10, strnbr, maxsize);
	strnbr[maxsize] = '\0';
}

static	unsigned int	set_nbr(int n)
{
	unsigned int	nbr;

	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	return (nbr);
}

static	size_t	set_ret_lenght(int nbr)
{
	size_t	ret_lenght;

	ret_lenght = 0;
	while (nbr)
	{
		ret_lenght++;
		nbr /= 10;
	}
	return (ret_lenght);
}

char	*ft_itoa(int n)
{
	char			*ret;
	size_t			ret_lenght;
	unsigned int	nbr;

	nbr = set_nbr(n);
	ret_lenght = set_ret_lenght(nbr);
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		ret = (char *)ft_calloc(ret_lenght + 1 + 1, sizeof(char));
		if (!ret)
			return (NULL);
		ret[0] = '-';
		ret_lenght++;
	}
	else
		ret = (char *)ft_calloc(ret_lenght + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_writenbr(nbr, ret, ret_lenght + 1);
	return (ret);
}
