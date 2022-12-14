/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:49:33 by rwallier          #+#    #+#             */
/*   Updated: 2022/07/30 22:24:27 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	fullsize;
	int		index;
	int		offset;

	if (!s1 || !s2)
		return (NULL);
	fullsize = (ft_strlen2(s1) + ft_strlen2(s2)) + 1;
	newstr = (char *)malloc(fullsize * sizeof(char));
	if (!newstr)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		newstr[index] = s1[index];
		index++;
	}
	offset = 0;
	while (s2[offset])
	{
		newstr[index++] = s2[offset];
		offset++;
	}
	newstr[index] = '\0';
	return (newstr);
}

size_t	ft_strlen2(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_substr2(char const *str, unsigned int start, size_t len)
{
	char		*ret;
	size_t		sz_temp;
	size_t		sz_str;

	if (!str)
		return (NULL);
	if (len > ft_strlen2(str))
		ret = (char *)malloc(ft_strlen2(str) + 1);
	else
		ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	sz_temp = 0;
	sz_str = 0;
	while (str[sz_str] != '\0')
	{
		if (sz_str >= start && sz_temp < len)
			ret[sz_temp++] = str[sz_str];
		sz_str++;
	}
	ret[sz_temp] = '\0';
	return (ret);
}

size_t	next_nl(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] != '\n')
	{
		if (!buffer[index])
			return (0);
		index++;
	}
	return (1);
}

size_t	end_line(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	return (index);
}
