/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:56:55 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/10 14:50:55 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	// static s_file	files;
	char			*read_result;
	int				file_status;
	char			*line;

	// printf("File descriptor : %d -> %d\n", fd, is_open(fd, &files));
	// if (!is_open(fd, &files))
	// 	files = get_new_filestruct(fd);
	line = ft_calloc(sizeof(char), 1);
	read_result = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	file_status = 1;
	while (file_status)
	{
		file_status = read(fd, read_result, BUFFER_SIZE);
		if (file_status != 0 && !is_terminated(line))
		{
			line = ft_strjoin(line, read_result);
		}
	}
	return (line);
}
