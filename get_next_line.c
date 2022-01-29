//
// Created by srupert on 1/28/22.
//

#include <malloc.h>
#include <unistd.h>
#include "get_next_line.h"

char    *gnl_chr(char *s, char c);

ssize_t gnl_read(char **remainder, char *src, int fd);

char *gnl_slice(char **remainder, char *src, int end, int depth);

char    *get_next_line(int fd)
{
    static char *remainder;
	char **src;
    ssize_t ret;

    src = &remainder;
	if (fd >= 0 && BUFFER_SIZE > 0)
    {
        while (!gnl_chr(remainder,'\n')){
            ret = gnl_read(&remainder, *src, fd);
            if (ret < 0)
                return (NULL);
            else if (ret == 0)
                return (gnl_slice(&remainder, *src,
								  (int) (gnl_chr(remainder, '\0') - remainder),
								  0));
        }
        return (gnl_slice(&remainder,
						  remainder,
						  (int) (gnl_chr(remainder, '\n') - remainder), 0));
    }
    return (NULL);//
}

char *gnl_slice(char **remainder, char *src, int end, int depth) {
    char *result;
	char *tmp;
    int i;
	size_t len;

	len = gnl_chr(src, '\0') - src;
	tmp = *remainder;
	if (len > 0) {
		result = malloc(sizeof(char) * ((end + 1 + 1)));
		i = -1;
		while (++i < end + 1 + 1)
			result[i] = src[i];
		result[i] = '\0';
	}
	if (src[end] != '\0')
		src = &src[i];
	*remainder = gnl_slice(&src, tmp,(int) (gnl_chr(tmp, '\0') - tmp),++depth);
	if (depth == 0){
			free(tmp);
			tmp = NULL;
		}
	return ((char *)((size_t)result * (len > 0)));
}

ssize_t gnl_read(char **remainder, char *src, int fd) {
	char buf[BUFFER_SIZE + 1];
	char *tmp;
	ssize_t ret;
	int i;
	size_t len;

	len = gnl_chr(src, '\0') - src;
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret <= 0)
		return (ret);
	tmp = malloc(sizeof(char) * (len * (len > 0) + ret + 1));
	i = -1;
	while (++i < (int)(len * (len > 0) + ret + 1))
	{
		if (i < (int)(len * (len > 0)))
			tmp[i] = src[i];
		else
			tmp[i] = buf[i - (int)((len) * (len > 0))];
	}
	tmp[i] = '\0';
	free(*remainder);
	*remainder = tmp;
    return (ret);
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