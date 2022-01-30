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
	size_t	i;

	i = 0;
	new_rem = NULL;
	while (remainder && remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (i > 0 || (remainder != 0 && remainder[0] == '\n'))
		*result = malloc(sizeof(char) * (i + 1 + (remainder[i] == '\n')));
	if (ft_strlen(&(remainder[i])) > 1)
		new_rem = malloc(sizeof (char) * (ft_strlen(&remainder[i]) + (i != 0)));
	if (*result == NULL || (new_rem == NULL && ft_strlen(&remainder[i]) > 1))
		return (NULL);
	ft_memcpy(*result, remainder, i + 1);
	if (remainder[i] == '\n')
		(*result)[i + 1] = '\0';
	if (new_rem)
		ft_memcpy(new_rem, &(remainder[i + 1]), ft_strlen(&(remainder[i + 1]) - (i==0)));
	return (new_rem);
}

char	*gnl_read(char *remainder, int fd, ssize_t *ret)
{
	char	buf[BUFFER_SIZE + 1];
	char	*new_rem;

	*ret = read(fd, buf, BUFFER_SIZE);
	if (*ret < 0 || (remainder == NULL && *ret == 0))
		return (NULL);
	new_rem = malloc((sizeof(char) * (ft_strlen(remainder) + *ret + 1)));
	if (new_rem == NULL )
		return (NULL);
	if (ft_strlen(remainder) > 0)
		ft_memcpy(new_rem, remainder, ft_strlen(remainder));
	ft_memcpy(&(new_rem[ft_strlen(remainder)]), buf, *ret + 1);
	new_rem[ft_strlen(remainder) + *ret - (remainder == 0 && *ret == 0)] = '\0';
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
