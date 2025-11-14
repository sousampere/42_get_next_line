/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:33:26 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/14 09:22:37 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stdlib.h>

typedef struct s_file
{
	int				fd;
	char			*last_read;
	struct s_file	*next;
	int				read_complete;
}	t_file;

char	*concat_line(char *prev_line, char *read, t_file *f_data, int r_status);
char	*get_lastread_string(t_file	*f_data);
t_file	*get_file_data(int fd, t_file **files);
int		newline_in_string(char *str);
size_t	ft_strlen(const char *s);
void	*ft_calloc(int nmemb, int size);
char	*concat(t_file	*f_data, char *read);

char	*get_next_line(int fd);

#endif