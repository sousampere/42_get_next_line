/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:57:59 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/14 10:14:02 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

t_file	*add_new_node(int fd, t_file **files)
{
	t_file	*new_file;
	t_file	*files_copy;

	files_copy = (*files);
	while (files_copy->next != NULL && files_copy->fd != fd)
		files_copy = files_copy->next;
	if (files_copy->fd == fd)
		return (files_copy);
	new_file = ft_calloc(1, sizeof(t_file));
	if (!new_file)
		return (NULL);
	new_file->fd = fd;
	new_file->last_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_file->last_read)
	{
		free(new_file);
		new_file = NULL;
		return (NULL);
	}
	files_copy->next = new_file;
	return (new_file);
}

t_file	*get_file_data(int fd, t_file **files)
{
	t_file	*new_file;
	t_file	*files_copy;

	if ((*files) == NULL)
	{
		new_file = ft_calloc(1, sizeof(t_file));
		if (!new_file)
			return (NULL);
		new_file->fd = fd;
		new_file->last_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!new_file->last_read)
		{
			free(new_file);
			new_file = NULL;
			return (NULL);
		}
		(*files) = new_file;
		return (new_file);
	}
	return (add_new_node(fd, files));
}

char	*get_lastread_string(t_file	*f_data)
{
	int		i;
	char	*line;

	i = -1;
	line = ft_calloc(ft_strlen(f_data->last_read) + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (f_data->last_read[++i] && f_data->last_read[i] != '\n')
		line[i] = f_data->last_read[i];
	if (f_data->last_read[i] == '\n')
	{
		f_data->last_read = &f_data->last_read[i + 1];
		line[i] = '\n';
	}
	else
		f_data->last_read = &f_data->last_read[i];
	return (line);
}

char	*concat(t_file	*f_data, char *read)
{
	int		i;
	int		ii;
	char	*line;

	i = -1;
	ii = ft_strlen(f_data->last_read);
	line = ft_calloc(ii + ft_strlen(read) + 1, sizeof(char));
	if (!line)
		return (NULL);
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
	free(read);
	read = NULL;
	return (line);
}

char	*concat_line(char *prev_line, char *read, t_file *f_data, int r_status)
{
	int		i;
	int		ii;
	char	*line;

	i = -1;
	ii = ft_strlen(prev_line);
	line = ft_calloc(ii + ft_strlen(read) + 1, sizeof(char));
	if (!line)
		return (NULL);
	if (!newline_in_string(read) && r_status == 0)
		f_data->read_complete = 1;
	while (prev_line[++i])
		line[i] = prev_line[i];
	free(prev_line);
	prev_line = NULL;
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
