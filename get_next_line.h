/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:33:26 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/10 15:32:41 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_file
{
	int				fd;
	char			*last_read;
	struct s_file	*next;
} s_file;

// int		is_open(int fd, s_file *files);
// s_file	get_new_filestruct(int fd);
// char	*get_next_line(int fd);
// char	*add_char_string(char c, char *str);
// char	*ft_strjoin(char const *s1, char const *s2);
// void	*ft_calloc(char nmemb, char size);
// int	is_terminated(char *str);

#endif