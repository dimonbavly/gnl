//
// Created by Dmitry on 26.01.2022.
//
//987654321098765432109876543210987654321098

#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"
#
int main()
{
	int fd[2];
	char *s1;
	char *s2;
    char *file1 = "./files/"
				 "alternate_line_nl_no_nl"
//               "41_with_nl"
//               "nl"
//				 "41_no_nl"
//				 "multiple_nlx5"
//			   	"empty"
                 ;
	char *file2 = "./files/"
//				 "alternate_line_nl_no_nl"
//			     "41_with_nl"
//               "nl"
				"alternate_line_nl_with_nl"
//				 "41_no_nl"
//				 "multiple_nlx5"
//  	    	"empty"
  	    	;
	fd[0] = open(file1, O_RDONLY);
	fd[1] = open(file2, O_RDONLY);
	s1 = NULL;
	s2 = NULL;
	while (1)
	{
		s1 = get_next_line_bonus(fd[0]);
		s2 = get_next_line_bonus(fd[1]);
		if (s1 == NULL && s2 == NULL)
			break ;
		fflush(NULL);
		printf("%s%s", s1, s2);
		fflush(NULL);
		free(s1);
		free(s2);
	}
	return (0);
}
