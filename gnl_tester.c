//
// Created by Dmitry on 26.01.2022.
//
//987654321098765432109876543210987654321098

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <malloc.h>

int main()
{
	int fd;
	char *s;
    char *file = "./files/"
//				 "alternate_line_nl_no_nl"
                 "42_with_nl"
//                 "nl"
                 ;
	fd = open(file, O_RDONLY);
	while ((s = get_next_line(fd)) != NULL)
	{
		fflush(NULL);
		printf("%s", s);
		fflush(NULL);
		free(s);
	}
	return (0);
}
