/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:44:58 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/10 23:53:27 by gtourdia         ###   ########.fr       */
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

#endif