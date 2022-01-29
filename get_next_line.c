//
// Created by srupert on 1/28/22.
//

#include "get_next_line.h"

char    *gnl_chr(char *s, char c);

char *gnl_read(char *remainder, int fd, ssize_t *ret);

char *gnl_slice(char **result, char *remainder, int depth);

char    *get_next_line(int fd)
{
	static char *remainder;
	char *result;
	char *tmp;
	ssize_t ret;

	result = NULL;
	tmp = NULL;
	if (fd >= 0 && BUFFER_SIZE > 0)
    {
        while (1) {
			tmp = remainder;
			remainder = gnl_read(remainder, fd, &ret);
			free(tmp);
			tmp = NULL;
			if(gnl_chr(remainder, '\n') || ret <= 0)
				break ;
		}
		tmp = remainder;
		if (ret >= 0)
			remainder = gnl_slice(&result, remainder, 0);
		free(tmp);
		tmp = NULL;
		if (ret <= 0)
			return (NULL);
	}
	return (result);
}

char *gnl_slice(char **result, char *remainder, int depth) {
	size_t len;
	char *sep;
	char *new_rem;

	sep = NULL;
	new_rem = NULL;
	if (remainder == NULL)
		return (NULL);
	if (depth == 0)
		sep = gnl_chr(remainder, '\n');
	if (!sep)
		sep = gnl_chr(remainder, '\0');
	len = sep - remainder + ((*sep == '\n') && (depth == 0)); // remaindre == NULL
	if (len > 0) {
		*result = malloc(sizeof(char) * (len + 1));
		ft_memcpy(*result, remainder, len + 1);
	}
	if (ft_strlen(&remainder[len]) > 1)
		gnl_slice(&new_rem, &remainder[len + 1], depth + 1);
	return (new_rem);




}

char * gnl_read(char *remainder, int fd, ssize_t *ret) {
	char buf[BUFFER_SIZE + 1];
	char *new_rem;
	size_t len;

	len = 0;
	buf[BUFFER_SIZE] = '\0';
	*ret = read (fd, buf, BUFFER_SIZE);
	if (*ret < 0)
		return (NULL);
	if (remainder)
		len = ft_strlen(remainder);
	new_rem = malloc(sizeof(char) * (len + *ret + 1));
	ft_memcpy(new_rem, remainder, len);
	ft_memcpy(&new_rem[len], buf, *ret + 1);
	return (new_rem);
}


char    *gnl_chr(char *s, char c) // char ** ???
{
    while (s)
    {
        if (c != '\0' && *s == '\0')
            break ;
        if (*s == c)
            return (s);
        s++;
    }
    return (NULL);
}