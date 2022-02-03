/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srupert <srupert@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:33:55 by srupert           #+#    #+#             */
/*   Updated: 2022/02/03 19:33:59 by srupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s && *s++)
		cnt++;
	return (cnt);
}

void	*gnl_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest == NULL || src == NULL)
		return (dest);
	d = (char *) dest;
	s = (char *) src;
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}
