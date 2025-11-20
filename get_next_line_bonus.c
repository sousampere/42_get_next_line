/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:56:55 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/16 14:04:09 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	newline_in_string(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*get_string_and_truncate(char pre_read[MAX_FD][BUFFER_SIZE + 1], int fd)
{
	int		i;
	int		ii;
	char	*line;

	i = -1;
	line = ft_clc(ft_strlen(pre_read[fd], 1) + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (pre_read[fd][++i] != '\0' && pre_read[fd][i] != '\n')
		line[i] = pre_read[fd][i];
	if (pre_read[fd][i] == '\n')
	{
		line[i++] = '\n';
		line[i] = '\0';
		ii = -1;
		while (pre_read[fd][i + ++ii])
			pre_read[fd][ii] = pre_read[fd][i + ii];
		pre_read[fd][ii] = '\0';
		return (line);
	}
	line[i] = '\0';
	ft_memset(&pre_read[fd][0], 0, BUFFER_SIZE + 1);
	return (line);
}

char	*join_strings(char *line, char *rd)
{
	int		i;
	int		ii;
	char	*new_line;

	if (line == NULL || rd == NULL)
		return (NULL);
	i = -1;
	new_line = ft_clc(ft_strlen(line, 0) + ft_strlen(rd, 1)
			+ 1, sizeof(char));
	if (!new_line)
		return (NULL);
	while (line[++i])
		new_line[i] = line[i];
	ii = -1;
	while (rd[++ii])
		new_line[i + ii] = rd[ii];
	free(line);
	free(rd);
	return (new_line);
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

char	*get_next_line(int fd)
{
	static char	prev_read[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	int			read_value;

	if (fd < 0 || fd > MAX_FD)
		return (NULL);
	if (newline_in_string(prev_read[fd]))
		return (get_string_and_truncate(prev_read, fd));
	line = join_strings(get_string_and_truncate(prev_read, fd), ft_clc(1, 1));
	if (!line)
		return (NULL);
	read_value = BUFFER_SIZE;
	while (!newline_in_string(line) && read_value > 0)
	{
		read_value = read(fd, &prev_read[fd][0], BUFFER_SIZE);
		line = join_strings(line, get_string_and_truncate(prev_read, fd));
		if (!line)
			return (NULL);
	}
	if (read_value <= 0 && ft_strlen(line, 1) == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
