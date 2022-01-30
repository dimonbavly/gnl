//
// Created by srupert on 1/28/22.
//

#ifndef GNL_GET_NEXT_LINE_BONUS_H
#define GNL_GET_NEXT_LINE_BONUS_H

#include <malloc.h>
#include <unistd.h>
#include "libft.h"

#define ULIMIT_N 4096
#define BS 0
#define BM 1
#define BE 2
#define RS 3
#define RM 4
#define RE 5
#define OT 6

char    *get_next_line_bonus(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);

#endif //GNL_GET_NEXT_LINE_H
