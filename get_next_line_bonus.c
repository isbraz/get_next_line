/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:40:10 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/05/18 13:48:46 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	size_t		i;

	i = 0;
	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd <= FOPEN_MAX)
			while (buff[fd][i])
				buff[fd][i++] = 0;
		return (0);
	}
	while (buff[fd][0] || read(fd, buff[fd], BUFFER_SIZE))
	{
		line = ft_strjoin(line, buff[fd]);
		if (ft_is_newline(buff[fd]))
			break ;
	}
	return (line);
}
