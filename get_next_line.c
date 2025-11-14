/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:56:55 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/14 09:35:55 by gtourdia         ###   ########.fr       */
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

char	*get_next_line_complete(t_file **f_data, int fd)
{
	char			*read_data;
	char			*line;
	int				read_val;

	if (!((*f_data)->read_complete == 0))
		return (NULL);
	read_data = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_data)
		return (NULL);
	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	line = concat((*f_data), line);
	read_val = BUFFER_SIZE;
	while (!newline_in_string(line) && read_val > 0 && line && read_data)
	{
		read_data = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_val = read(fd, read_data, BUFFER_SIZE);
		line = concat_line(line, read_data, (*f_data), read_val);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_file	*files;
	t_file			*f_data;
	char			*line;

	f_data = get_file_data(fd, &files);
	if (!f_data)
		return (NULL);
	if (newline_in_string(f_data->last_read))
		return (get_lastread_string(f_data));
	else
		line = get_next_line_complete(&f_data, fd);
	return (line);
}
