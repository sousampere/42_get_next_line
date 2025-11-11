/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:34:04 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/11 20:41:56 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"

void	*ft_calloc(char nmemb, int size)
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

s_file	*save_restore_file(int fd, s_file **files)
{
	s_file	*new_file;

	new_file = malloc(sizeof(s_file) * 1);
	if ((*files) == NULL) // Si files est vide, j'y ajoute mon fichier
		(*files) = new_file;
	else
	{
		while ((*files) != NULL)
		{
			if ((*files)->fd == fd)
				return (*files);
			(*files) = (*files)->next;
		}
	}
	(*files)->fd = fd;
	(*files)->last_read = ft_calloc(BUFFER_SIZE + 1, 1);
	(*files)->next = NULL;
	return ((*files));
}

char	*concat(char **str1, char *str2)
{
	
}

char	*get_next_line(int fd)
{
	static s_file	*file_list;
	s_file			*file;
	char			*line;
	int				i;

	file = save_restore_file(fd, &file_list); // Recup previous data
	if (newline_in_string(file->last_read))
	{
		line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		i = -1;
		while (line[++i] != '\n')
			line[i] = file->last_read[i];
		file->last_read[i] += i + 1;
	}
	return (file->last_read);
}

int main()
{
	int fd = open("get_next_line.h", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	int fd2 = open("main.c", O_RDONLY);
	// printf("%s\n", get_next_line(fd));
	// s_file	*file = save_restore_file(fd, )
	close(fd);
	close(fd2);
}