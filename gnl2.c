/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:52:55 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/15 00:34:52 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#ifndef MAX_FD
# define MAX_FD 1024
#endif

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*c_s;

	i = 0;
	c_s = s;
	while (i < n)
	{
		c_s[i] = (char) c;
		i++;
	}
	return (s);
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

int	ft_strlen(const char *s, int newline_factor)
{
	int	i;

	i = 0;
	if (newline_factor == 1)
	{
		while (s[i] != '\n' && s[i])
			i++;
		if (s[i] == '\n')
			return (i + 1);
		return (i);
	}
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

char	*get_string_and_truncate(char prev_read[MAX_FD][BUFFER_SIZE + 1], int fd)
{
	int		i;
	int		ii;
	char	*line;

	i = -1;
	line = ft_calloc(ft_strlen(prev_read[fd], 1) + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (prev_read[fd][++i] != '\0' && prev_read[fd][i] != '\n')
		line[i] = prev_read[fd][i];
	if (prev_read[fd][i] == '\n')
	{
		line[i++] = '\n';
		line[i] = '\0';
		ii = -1;
		while (prev_read[fd][i + ++ii])
			prev_read[fd][ii] = prev_read[fd][i + ii];
		prev_read[fd][ii] = '\0';
		return (line);
	}
	line[i] = '\0';
	ft_memset(&prev_read[fd][0], 0, BUFFER_SIZE + 1);
	return (line);
}

char	*join_strings(char *line, char *rd)
{
	int	i;
	int	ii;
	char	*new_line;

	i = -1;
	new_line = ft_calloc(ft_strlen(line, 0) + ft_strlen(rd, 1)
		+ 1, sizeof(char));
	while (line[++i])
		new_line[i] = line[i];
	ii = -1;
	while (rd[++ii])
		new_line[i + ii] = rd[ii];
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	prev_read[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	int			read_value;

	if (newline_in_string(prev_read[fd]))
		return (get_string_and_truncate(prev_read, fd));
	line = ft_calloc(2, 1);
	line = join_strings(get_string_and_truncate(prev_read, fd), line);
	read_value = BUFFER_SIZE;
	while (!newline_in_string(line) && read_value > 0)
	{
		read_value = read(fd, &prev_read[fd][0], BUFFER_SIZE);
		line = join_strings(line, get_string_and_truncate(prev_read, fd));
	}
	if (read_value == 0 && ft_strlen(line, 1) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	int fd2 = open(".gitignore", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd2));
	// char	**strs;
	// strs[1][0] = '1';
	// strs[1][1] = '2';
	// strs[1][2] = '\n';
	// strs[1][3] = '3';
	// strs[1][4] = '\0';
	// printf("%s", get_string_and_truncate(strs, 1));
	close(fd);
	close(fd2);
}