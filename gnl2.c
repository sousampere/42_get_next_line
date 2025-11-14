/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:52:55 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/14 08:50:01 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

typedef struct s_file
{
	int				fd;
	char			*last_read;
	struct s_file	*next;
} s_file;

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

s_file	*get_file_data(int fd, s_file **files)
{
	s_file	*new_file;
	s_file	*files_copy;

	if ((*files) == NULL)
	{
		new_file = ft_calloc(1, sizeof(s_file));
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
	files_copy = (*files);
	while (files_copy->next != NULL && files_copy->fd != fd)
		files_copy = files_copy->next;
	if (files_copy->fd == fd)
		return (files_copy);
	new_file = ft_calloc(1, sizeof(s_file));
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

char	*get_next_line(int fd)
{
	static s_file	*files;
	s_file			*f_data;
	char			*line;

	f_data = get_file_data(fd, &files);
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	close(fd);
}