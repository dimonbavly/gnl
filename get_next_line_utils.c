/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srupert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 09:44:21 by srupert           #+#    #+#             */
/*   Updated: 2022/01/30 09:44:25 by srupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s && *s++)
		cnt++;
	return (cnt);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (char *) dest;
	s = (char *) src;
<<<<<<< HEAD
	while (n) {
=======
	while (n)
	{
>>>>>>> ddd
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
<<<<<<< HEAD

}

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	if (s)
		while (s[cnt])
			cnt++;
	return (cnt);
}

char	*gnl_strdup(const char *s1)
{
	char	*res;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	res = malloc(sizeof(*res) * s1_len + 1);
	if (!res)
		return (NULL);
	else
		ft_memcpy(res, s1, s1_len);
	return (res);
=======
>>>>>>> ddd
}
