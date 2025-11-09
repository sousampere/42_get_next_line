/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:57:59 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/09 13:07:55 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int	is_open(int fd, s_file *files)
{
	while (files != NULL)
	{
		if (files->fd == fd)
			return (1);
		files = files->next;
	}
	return (0);
}

s_file	get_new_filestruct(int fd)
{
	s_file	structure;
	structure.fd = fd;
	structure.terminated = 0;
	structure.next = NULL;
	return (structure);
}