/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:56:55 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/09 13:17:37 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int get_next_line(int fd)
{
	static s_file	files;
	char			c;
	int				file_status;

	// printf("File descriptor : %d -> %d\n", fd, is_open(fd, &files));
	if (!is_open(fd, &files))
		files = get_new_filestruct(fd);
	c = 0;
	while (c != '\n')
	{
		file_status = read(fd, &c, 1);
		if (file_status != 0)
			write(1, &c, 1);
		else
			c = '\n';
	}
	return (1);
}
