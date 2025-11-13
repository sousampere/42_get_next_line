/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:33:26 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/12 14:20:44 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>

typedef struct s_file
{
	int				fd;
	char			*last_read;
	struct s_file	*next;
} s_file;

char	*concat_line(char *prev_line, char *read, s_file *f_data);
char	*get_lastread_string(s_file	*f_data);
s_file 	*saved_file_data(int fd, s_file **files);
int		newline_in_string(char *str);
size_t	ft_strlen(const char *s);
void	*ft_calloc(int nmemb, int size);
char	*concat(s_file	*f_data, char *read);

char	*get_next_line(int fd);

#endif