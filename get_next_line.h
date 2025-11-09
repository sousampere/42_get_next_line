/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:33:26 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/09 13:05:11 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_file
{
	int				fd;
	int				terminated;
	struct s_file	*next;
} s_file;

int	is_open(int fd, s_file *files);
s_file	get_new_filestruct(int fd);
int get_next_line(int fd);

#endif