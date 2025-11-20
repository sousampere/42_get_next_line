/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtourdia <@student.42mulhouse.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:57:35 by gtourdia          #+#    #+#             */
/*   Updated: 2025/11/15 18:36:26 by gtourdia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*c_s;

	i = 0;
	c_s = s;
	while (i < n)
	{
		c_s[i] = (char) c;
		i++;
	}
	return (s);
}

void	*ft_clc(int nmemb, int size)
{
	void	*alloc;
	int		i;

	if (size != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		((char *) alloc)[i] = '\0';
		i++;
	}
	return (alloc);
}
