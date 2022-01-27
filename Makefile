all:
	gcc  -g3 -std=c99 -D BUFFER_SIZE=1 -I. -Wall -Wextra -Werror  gnl_tester.c get_next_line.c -o gnl

clean:
	rm -rf gnl

val:	all
	valgrind -q --leak-check=full ./gnl
