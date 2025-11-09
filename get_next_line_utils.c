/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:57:59 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/09 17:27:24 by gtourdia         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*new_dst;

	i = 0;
	new_dst = s;
	while (i < n)
	{
		new_dst[i] = '\0';
		i++;
	}
}


void	*ft_calloc(char nmemb, char size)
{
	void	*alloc;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, size * nmemb);
	return (alloc);
}

int	is_terminated(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

#include <stdio.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	stringlen;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	// printf("%s //", s1);
	string = ft_calloc(sizeof(char), (ft_strlen(s1) + BUFFER_SIZE + 1));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	i = 0;
	while (i != BUFFER_SIZE && s2[i] != '\n')
	{
		stringlen = ft_strlen(string);
		string[stringlen] = s2[i];
		string[stringlen + 1] = '\0';
		i++;
	}
	if (s2[i] == '\n')
	{
		string[stringlen + 1] = '\n';
		string[stringlen + 2] = '\0';
	}
	return (string);
}

s_file	get_new_filestruct(int fd)
{
	s_file	structure;
	structure.fd = fd;
	structure.next = NULL;
	return (structure);
}

// #include <stdio.h>
// char	*add_char_string(char c, char *str)
// {
// 	int		i;
// 	char	*new_str;

// 	if (str == NULL)
// 	{
// 		str = malloc(sizeof(char) * 2);
// 		if (str == NULL)
// 			return (NULL);
// 		str[0] = c;
// 		str[1] = '\0';
// 		return (str);
// 	}
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	new_str = malloc(sizeof(char) * (i + 2));
// 	if (new_str == NULL)
// 		return (NULL);
// 	i = -1;
// 	while (str[++i])
// 		new_str[i] = str[i];
// 	new_str[i] = c;
// 	new_str[i + 1] = '\0';
// 	free(str);
// 	return (new_str);
// }

// char	*append_char(char c, char *str)
// {
// 	int		i;
// 	char	*new_str;

// 	if (str == NULL)
// 	{
// 		str = malloc(sizeof(char) * 2);
// 		if (str == NULL)
// 			return (NULL);
// 		str[0] = c;
// 		str[1] = '\0';
// 		return (str);
// 	}
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	new_str = malloc(sizeof(char) * (i + 2));
// 	if (new_str == NULL)
// 		return (NULL);
// 	i = -1;
// 	while (str[++i])
// 		new_str[i] = str[i];
// 	new_str[i] = c;
// 	new_str[i + 1] = '\0';
// 	free(str);
// 	return (new_str);
// }

// char	*add_read_to_string(char *read, char *str)
// {

	
// 	// int		i;
// 	// char	*new_str;

// 	// if (str == NULL)
// 	// {
// 	// 	str = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
// 	// 	if (str == NULL)
// 	// 		return (NULL);
// 	// 	i = -1;
// 	// 	while (read[++i] != '\n' || read[i] != '\0')
// 	// 		str[i] = read[i];
// 	// 	str[i] = '\0';
// 	// 	return (str);
// 	// }
// 	// i = -1;
// 	// while (str[++i]);
// 	// new_str = ft_calloc(sizeof(char), (i + BUFFER_SIZE + 1));
// 	// if (new_str == NULL)
// 	// 	return (NULL);
// 	// i = -1;
// 	// while (str[++i])
// 	// 	new_str[i] = str[i];
// 	// new_str 
// 	// free(str);
// 	// return (new_str);
// }
