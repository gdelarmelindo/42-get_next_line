/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelarme <gdelarme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:31:48 by gdelarme          #+#    #+#             */
/*   Updated: 2022/03/29 21:39:20 by gdelarme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

size_t	check_breakline(char *str)
{
	size_t	last_position;

	last_position = 0;
	while (*str)
	{
		if (*str == '\n')
			return (last_position + 1);
		str++;
		last_position++;
	}
	return (last_position);
}

char	*strjoin_size(char *s1, char *s2, size_t s2_size_max, t_counter head)
{
	char	*s3;

	s3 = malloc(sizeof(s3) * (ft_strlen(s1) + s2_size_max + 1));
	if (!s3)
		return (NULL);
	while (s1 && s1[head.i])
	{
		s3[head.i] = s1[head.i];
		head.i++;
	}
	while (s2[head.j])
	{
		if (head.j < s2_size_max)
			s3[head.i++] = s2[head.j];
		else
			s2[head.k++] = s2[head.j];
		s2[head.j++] = '\0';
	}
	s3[head.i] = '\0';
	if (s1)
		free(s1);
	return (s3);
}
