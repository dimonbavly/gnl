//
// Created by srupert on 1/30/22.
//

#include "get_next_line.h"

char *gnl_read(char *remainder, int fd, ssize_t *ret);

char *gnl_slice(char *remainder, char **result);

char    *get_next_line(int fd)
{
	static char *remainder;
	char *result;
	char *tmp;
	ssize_t ret;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (result == NULL)
	{
		tmp = remainder;
		remainder = gnl_read(remainder, fd, &ret);
		free(tmp);
		if (ret < 0)
			return (NULL);
		remainder = gnl_slice(remainder, &result);
	}
	return (result);
}

char *gnl_slice(char *remainder, char **result) {
	char *new_rem;
	size_t i;

	i = 0;
	new_rem = NULL;
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (i > 0)
		*result = malloc(sizeof(char) * (i + 1 + (remainder[i] == '\n')));
	if (ft_strlen(&remainder[i]) > 1)
		new_rem = malloc(sizeof (char) *  (ft_strlen(&remainder[i]) + 1));
	if (*result == NULL || (new_rem == NULL && ft_strlen(&remainder[i]) > 1))
		return (NULL);
	memcpy(*result, remainder,  i + 1);
	if (remainder[i] == '\n')
		*result[i + 1] = '\0';//debug
	if (new_rem)
		memcpy(new_rem, &remainder[i + 1], ft_strlen(&remainder[i + 1]));
	return (new_rem);
}

char *gnl_read(char *remainder, int fd, ssize_t *ret) {
	char *buf[BUFFER_SIZE + 1];
	char *new_rem;

	*ret = read(fd, buf, BUFFER_SIZE);
	if (*ret < 0)
		return (NULL);
	new_rem = malloc((sizeof(char) * (ft_strlen(remainder) + *ret + 1)));
	if (new_rem == NULL)
		return (NULL);
	if (ft_strlen(remainder) > 0)
		ft_memcpy(new_rem, remainder, ft_strlen(remainder));
	ft_memcpy(&new_rem[ft_strlen(remainder)], buf, *ret + 1);
	new_rem[ft_strlen(remainder) + *ret] = '\0';
	return (new_rem);
}
