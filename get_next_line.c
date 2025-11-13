/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:56:55 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/13 15:01:30 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

void	*ft_calloc(int nmemb, int size)
{
	void	*alloc;
	int		i;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *) alloc)[i] = '\0';
		i++;
	}
	return (alloc);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static s_file	*files;
	s_file			*f_data;
	char			*read_data;
	char			*line;
	int				read_val;

	f_data = saved_file_data(fd, &files);
	if (newline_in_string(f_data->last_read))
		return (get_lastread_string(f_data));
	else
	{
		if (!(f_data->read_complete == 0))
			return (NULL);
		read_data = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		line = ft_calloc(1, 1);
		line = concat(f_data, line);
		read_val = BUFFER_SIZE;
		while (!newline_in_string(line) && read_val != 0)
		{
			read_data = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
			read_val = read(fd, read_data, BUFFER_SIZE);
			line = concat_line(line, read_data, f_data, read_val);
		}
		// f_data->last_read = "ZZ";
	}
	return (line);
}
