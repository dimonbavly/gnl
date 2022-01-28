#include <stdio.h>
#include "get_next_line.h"

char *eol(char *str, size_t len);

size_t ft_strlen(char *str);

char *gnl(char *endline, char *rem, char *buf);

char *update_remaider(char *local_start, char *result);

char	*get_next_line(int fd)
{
	char *endline;
	char buf[BUFFER_SIZE + 1];
	char *rem;

	if (fd >= 0 && BUFFER_SIZE > 0) {
		rem = update_remaider(NULL, NULL);
		if (rem) {
			if ((endline = eol(rem, ft_strlen(rem))) != NULL)
				return (gnl(endline, rem, NULL));
			}
		}
	while (1) {
		ssize_t ret;

		if ((ret = read(fd, buf, BUFFER_SIZE)) <= 0)
			return (NULL);
		buf[ret] = '\0';
		if ((endline = eol(buf, BUFFER_SIZE)) != NULL)
			return (gnl(endline, rem, buf));
		rem = update_remaider(buf, NULL);
	}
	return (NULL);
}

char *update_remaider(char *local_start, char *result) {
	static char *remainder;
    char *tmp = remainder;

	if (local_start)
	{
        if (ft_strlen(remainder) + ft_strlen(local_start) + 1 > ft_strlen(result))
            remainder = malloc(sizeof (char) * (ft_strlen(remainder) + ft_strlen(local_start) + 1 -
                ft_strlen((result))));
        else{
            free(tmp);
            return (NULL);
        }
		for (int i = 0; i < (int)(ft_strlen(tmp) + ft_strlen(local_start) + 1 - ft_strlen(result)); i++)
        {
            if (i < (int)ft_strlen(result))
                continue ;
            if (i < (int)ft_strlen(tmp))
                remainder[i] = tmp[i];
            else
                remainder[i] = local_start[i - (int)ft_strlen(tmp)];
        }
        if (tmp != NULL) // fix buf = 1 , 41- no - nl
            free(tmp);
	}
	return (remainder);
}

char *gnl(char *endline, char *rem, char *buf) {
	char *result;
	if (rem != NULL && endline >= rem && endline <= &(rem[ft_strlen(rem) - 1]))
	{
		result = malloc(sizeof(char) * (endline - rem + 1 + 1));
		for (int i = 0; i < endline - rem + 1; i++)
			result[i] = rem[i];
		result[endline - rem + 1] = '\0';
	}
	else {
		result = malloc(sizeof(char) * (ft_strlen(rem) + (endline - buf + 1 + 1)));
		int i = 0;
		while( i < (int)(ft_strlen(rem) + (endline - buf + 1)))
		{
			if (i < (int)ft_strlen(rem))
				result[i] = rem[i];
			else
                result[i] = buf[i - ft_strlen(rem)];
			i++;
		}
		result[i] = '\0'; // todo !
		}
    update_remaider(&endline[1], result);
	return (result);
}

size_t ft_strlen(char *str) {
	size_t len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char *eol(char *str, size_t len)
{
	size_t i = 0;
	if (str != NULL) {
		while (i < len)
		{
			if (str[i] == '\n' || str[i] == '\0')
				return (&str[i]);
			i++;
		}
	}
	return (NULL);
}
