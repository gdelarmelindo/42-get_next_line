/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelarme <gdelarme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:31:52 by gdelarme          #+#    #+#             */
/*   Updated: 2022/03/23 20:30:28 by gdelarme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define ERROR (0)
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_counter
{
	size_t		i;
	size_t		j;
	size_t		k;
}	t_counter;

size_t	check_breakline(char *str);
char	*strjoin_size(char *s1, char *s2, size_t s2_size_max, t_counter head);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

#endif