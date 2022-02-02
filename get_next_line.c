/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srupert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 09:40:36 by srupert           #+#    #+#             */
/*   Updated: 2022/01/30 09:40:39 by srupert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_read(char *remainder, int fd, ssize_t *ret);

char	*gnl_slice(char *remainder, char **result);

char	*gnl_chr(char *s, char c);

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*result;
	char		*tmp;
	ssize_t		ret;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (remainder)
			if (gnl_chr(remainder, '\n'))
				break ;
		tmp = remainder;
		remainder = gnl_read(remainder, fd, &ret);
		free(tmp);
		if (ret < 0)
			return (NULL);
		if (ret == 0)
			break ;
	}
	tmp = remainder;
	remainder = gnl_slice(remainder, &result);
	free(tmp);
	return (result);
}

char	*gnl_slice(char *remainder, char **result)
{
	char	*new_rem;
	size_t	len;
	char	*end;
	size_t	len_res;
	size_t	len_new_rem;

	if (remainder == NULL)
		return (NULL);
	new_rem = NULL;
	len = ft_strlen(remainder);
	end = gnl_chr(remainder, '\n');
	len_res = ((end - remainder > 2) * (end - remainder + 1) + \
		(end == remainder) + (len) * (end == NULL));
	len_new_rem = len - len_res;
	*result = malloc(sizeof (char) * (len_res + 1) * (len_res != 0));
	gnl_memcpy(*result, remainder, len_res);
	(*result)[len_res] = '\0';
	if (len_new_rem > 0)
		new_rem = malloc(sizeof(char) * (len_new_rem + 1));
	if (end)
		gnl_memcpy(new_rem, &end[1], (len_new_rem + 1));
	return (new_rem);
}

char	*gnl_read(char *remainder, int fd, ssize_t *ret)
{
	char	*buf;
	char	*new_rem;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	*ret = read(fd, buf, BUFFER_SIZE);
	if (*ret < 0 || (remainder == NULL && *ret == 0))
	{
		free(buf);
		return (NULL);
	}
	new_rem = malloc((sizeof(char) * (ft_strlen(remainder) + *ret + 1)));
	if (new_rem == NULL )
	{
		free(buf);
		return (NULL);
	}
	if (ft_strlen(remainder) > 0)
		gnl_memcpy(new_rem, remainder, ft_strlen(remainder));
	gnl_memcpy(&(new_rem[ft_strlen(remainder)]), buf, *ret + 1);
	new_rem[ft_strlen(remainder) + *ret - (remainder == 0 && *ret == 0)] = '\0';
	free(buf);
	return (new_rem);
}

char	*gnl_chr(char *s, char c)
{
	int	i;

	i = -1;
	if (s)
		while (s[++i])
			if (s[i] == c)
				return (&s[i]);
	return (NULL);
}
