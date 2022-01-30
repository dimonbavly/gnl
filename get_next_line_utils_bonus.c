//
// Created by srupert on 1/30/22.
//
#include "get_next_line_bonus.h"
size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (s && *s++)
		cnt++;
	return (cnt);
}

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

