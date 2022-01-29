//
// Created by srupert on 1/28/22.
//

#include <malloc.h>
#include <unistd.h>
#include "get_next_line.h"

char    *gnl_chr(char *s, char c);

ssize_t gnl_read(char **remainder, char *src, int fd);

char *gnl_slice(char **remainder, int start, int end, int depth);

char    *get_next_line(int fd)
{
	static char *remainder;
    char *src;
    ssize_t ret;

	if (fd >= 0 && BUFFER_SIZE > 0)
    {
        while (!gnl_chr(src, '\n')){
            ret = gnl_read(&src, src, fd);

            if (ret < 0)
                return (NULL);
            else if (ret == 0)
			{
				remainder = src;
				return (gnl_slice(&src, 0,
								   (int) (gnl_chr(src, '\0') - src),
								   0));
			}
        }
		remainder = src;
		if (remainder)
			ret = 0;
		return (gnl_slice(&src, 0,
						  (int) (gnl_chr(src, '\n') - src), 0));
    }
    return (NULL);//
}

char *gnl_slice(char **remainder, int start, int end, int depth) {
    char *result;
	char *tmp;
	size_t len = ft_strlen(remainder[start]);

	tmp = *remainder;
	if (*remainder[end] == '\0'  && len > 0) {
		result = malloc (sizeof(char) * (end - start + 1));
		ft_memcpy(result, &*remainder[start], end - start + 1);
	}
	else if (*remainder[end] == '\n' && len > 0 && depth == 0)
	{
		result = malloc(sizeof (char) * (end - start + 2));
		ft_memcpy(result, &*remainder[start], end - start + 2);
		len = ft_strlen(&*remainder[end + 1]);
		tmp = gnl_slice(remainder, end + 1, (int)len, depth + 1);
	}
	if (depth == 0)
		free(*remainder);
	*remainder = tmp;
	return ((char *)((size_t)result * (len > 0)));
}

ssize_t gnl_read(char **remainder, char *src, int fd) {
	char buf[BUFFER_SIZE + 1];
	char *tmp;
	ssize_t ret;
	int i;
	size_t len = ft_strlen(src);

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret <= 0)
		return (ret);
	if (len + ret > 0)
		tmp = malloc(sizeof(char) *(len + ret + 1));
	i = 0;
	while (i < (int)(len + ret))
	{
		if (i < (int)len)
			tmp[i] = src[i];
		else
			tmp[i] = buf[i - len];
		i++;
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