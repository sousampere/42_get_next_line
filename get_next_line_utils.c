/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:57:59 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/13 15:20:42 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	newline_in_string(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

s_file *saved_file_data(int fd, s_file **files)
{
	s_file	*new_file;

	while ((*files) != NULL)
	{
		if ((*files)->fd == fd)
			return (*files);
		(*files) = (*files)->next;
	}
	new_file = malloc(sizeof(s_file) * 1);
	new_file->fd = fd;
	new_file->last_read = ft_calloc(BUFFER_SIZE + 1, sizeof(s_file));
	new_file->next = NULL;
	new_file->read_complete = 0;
	(*files) = new_file;
	return (*files);
}

char	*get_lastread_string(s_file	*f_data)
{
	int		i;
	char	*line;
	
	i = -1;
	line = ft_calloc(ft_strlen(f_data->last_read) + 1, sizeof(char));
	while (f_data->last_read[++i] && f_data->last_read[i] != '\n')
		line[i] = f_data->last_read[i];
	if (f_data->last_read[i] == '\n')
	{
		f_data->last_read = &f_data->last_read[i + 1];
		line[i] = '\n';
	}
	else
	{
		f_data->last_read = &f_data->last_read[i];
	}
	return (line);
}

char	*concat(s_file	*f_data, char *read)
{
	int		i;
	int		ii;
	char	*line;

	i = -1;
	ii = ft_strlen(f_data->last_read);
	line = ft_calloc(ii + ft_strlen(read) + 1, sizeof(char));
	while (f_data->last_read[++i])
		line[i] = f_data->last_read[i];
	ii = -1;
	while (read[ii] && read[ii] != '\n')
		line[i + ii] = read[ii];
	if (read[ii] == '\n')
	{
		f_data->last_read = &read[i + 1];
		line[i + ii] = '\n';
	}
	return (line);
}

char	*concat_line(char *prev_line, char *read, s_file *f_data, int r_status)
{
	int		i;
	int		ii;
	char	*line;

	i = -1;
	ii = ft_strlen(prev_line);
	line = ft_calloc(ii + ft_strlen(read) + 1, sizeof(char));
	if (!newline_in_string(read) && r_status == 0)
		f_data->read_complete = 1;
	while (prev_line[++i])
		line[i] = prev_line[i];
	ii = -1;
	while (read[++ii] && read[ii] != '\n')
		line[i + ii] = read[ii];
	if (read[ii] == '\n')
	{
		f_data->last_read = &read[ii + 1];
		line[i + ii] = '\n';
	}
	return (line);
}
