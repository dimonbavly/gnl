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
		remainder = gnl_read(remainder, fd, &ret);
		if (ret < 0)
			return (NULL);
		remainder = gnl_slice(remainder, &result);
	}
	return (result);
}

char *gnl_slice(char *remainder, char **result) {

}

char * gnl_read(char *remainder, int fd, ssize_t *ret) {
	char *buf[BUFFER_SIZE + 1];
	char *new_rem;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
		return (ret);
	new


	return 0;
}
