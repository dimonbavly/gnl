SAN = -fsanitize=address
BONUS =
#_bonus

all:
	gcc  -g3 -std=c99 -O0 -D BUFFER_SIZE=10000000 -I. -Wall -Wextra -Werror \
 		gnl_tester.c get_next_line$(BONUS).c get_next_line_utils$(BONUS).c \
 		-o gnl

clean:
	rm -rf gnl

val:	all
	valgrind -q --leak-check=full ./gnl

san:
	gcc  -g3 $(SAN) -std=c99 -O0 -D BUFFER_SIZE=1 -I. -Wall -Wextra -Werror \
 		gnl_tester.c get_next_line$(BONUS).c get_next_line_utils$(BONUS).c \
 		-L. -lft \
 		-I. \
 		-o gnl
