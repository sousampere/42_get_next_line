/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:34:04 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/12 14:10:11 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"

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

	// Aucun fichier enregistre
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

char	*concat_line(char *prev_line, char *read, s_file *f_data)
{
	int		i;
	int		ii;
	char	*line;

	i = -1;
	ii = ft_strlen(prev_line);
	line = ft_calloc(ii + ft_strlen(read) + 1, sizeof(char));
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
	else
		f_data->last_read = &read[ii];
	return (line);
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

int main()
{
	int fd = open("tests.c", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	int fd2 = open("gnl.h", O_RDONLY);
	// printf("%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	// printf("%s\n", get_next_line(fd));
	// s_file	*file = save_restore_file(fd, )
	close(fd);
	close(fd2);
}