/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:56:55 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/09 13:50:39 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static s_file	files;
	char			c;
	int				file_status;
	char			*line;

	// printf("File descriptor : %d -> %d\n", fd, is_open(fd, &files));
	if (!is_open(fd, &files))
		files = get_new_filestruct(fd);
	c = 0;
	line = malloc(sizeof(char) * 1);
	line[0] = '\0';
	while (c != '\n')
	{
		file_status = read(fd, &c, 1);
		if (file_status != 0)
			line = add_char_string(c, line);
		else
			c = '\n';
	}
	return (line);
}
