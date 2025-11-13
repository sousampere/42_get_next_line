/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:56:55 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/12 14:13:12 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

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
		read_data = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		line = ft_calloc(1, 1);
		line = concat(f_data, line);
		read_val = 1;
		while (!newline_in_string(line) && read_val != 0)
		{
			read_val = read(fd, read_data, BUFFER_SIZE);
			line = concat_line(line, read_data, f_data);
		}
	}
	if (read_val == 0 && ft_strlen(line) == 0)
		return (NULL);
	return (line);
}