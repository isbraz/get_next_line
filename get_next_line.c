/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:03:33 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/08/24 11:54:12 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	size_t		i;

	i = 0;
	line = NULL;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buff[i])
		{
			buff[i] = 0;
			i++;
		}
		return (0);
	}
	while (buff[0] || read(fd, buff, BUFFER_SIZE))
	{
		line = ft_strjoin(line, buff);
		if (ft_is_newline(buff))
			break ;
	}
	return (line);
}

/*
int main(void)
{
	int fd;
	char *line;

	fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Erro ao abrir o arquivo.\n");
		return 1;
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}*/