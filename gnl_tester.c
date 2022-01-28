//
// Created by Dmitry on 26.01.2022.
//
//987654321098765432109876543210987654321098

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int fd;
	char *s;
    char *file = "./gnlTester/files/"
                 "42_with_nl";
	fd = open(file, O_RDONLY);
	while ((s = get_next_line(fd)) != NULL)
	{
		fflush(NULL);
		printf("%s", s);
		fflush(NULL);
        if (s)
            free(s);
	}
	return (0);
}
