all:
	gcc -fsanitize=address -g3 -std=c99 -O0 -D BUFFER_SIZE=42 -I. -Wall -Wextra -Werror \
 		gnl_tester.c get_next_line.c get_next_line_utils.c \
 		-L. -lft \
 		-I. \
 		-o gnl

clean:
	rm -rf gnl

val:	all
	valgrind -q --leak-check=full ./gnl
