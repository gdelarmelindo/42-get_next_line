/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelarme <gdelarme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:50:51 by gdelarme          #+#    #+#             */
/*   Updated: 2022/03/30 21:08:24 by gdelarme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*line;
	size_t		i;
	size_t		last_position;
	t_counter	head;

	head.i = 0;
	head.j = 0;
	head.k = 0;
	line = NULL;
	i = 1;
	while (i > 0 && !(read(fd, NULL, 0) == -1) && BUFFER_SIZE > 0)
	{
		if (buff[0] == '\0')
			i = read(fd, buff, BUFFER_SIZE);
		last_position = check_breakline(buff);
		if (i > 0)
		{
			if (buff[last_position - 1] == '\n')
				i = 0;
			line = strjoin_size(line, buff, last_position, head);
		}
	}
	return (line);
}
