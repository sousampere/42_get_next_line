/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:57:59 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/09 13:49:43 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

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
	structure.next = NULL;
	return (structure);
}

#include <stdio.h>
char	*add_char_string(char c, char *str)
{
	int		i;
	char	*new_str;

	if (str == NULL)
	{
		str = malloc(sizeof(char) * 2);
		if (str == NULL)
			return (NULL);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	i = 0;
	while (str[i])
		i++;
	new_str = malloc(sizeof(char) * (i + 2));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new_str[i] = str[i];
	new_str[i] = c;
	new_str[i + 1] = '\0';
	free(str);
	return (new_str);
}
