//
// Created by srupert on 1/28/22.
//

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n) {
	char *d;
	char *s;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (char *) dest;
	s = (char *) src;
	while (n) {
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);

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
}
