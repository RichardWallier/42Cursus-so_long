/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:10:34 by rwallier          #+#    #+#             */
/*   Updated: 2022/07/30 22:26:13 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int		treat_trash(char **trash, char **line);

char	*treat_read(int fd, int *size_read);

char	*make_line_no_nl(char *line, char *buffer);

char	*make_line_with_nl(char *buffer, char **trash, char *line);

size_t	end_line(char *buffer);

size_t	next_nl(char *buffer);

size_t	ft_strlen2(const char *str);

char	*ft_strjoin2(char const *s1, char const *s2);

char	*ft_substr2(char const *str, unsigned int start, size_t len);

#endif
