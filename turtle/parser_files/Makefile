CC=gcc
Clang=clang
CCC=/usr/local/bin/gcc-10
COMMON= -Wall -Wextra -Wfloat-equal -pedantic -std=c90
DEBUG= -g3
SANITIZE= $(COMMON) -fsanitize=undefined -fsanitize=address -fno-omit-frame-pointer $(DEBUG)
VALGRIND= $(COMMON) $(DEBUG)
PRODUCTION= $(COMMON) -O3
LDLIBS =

parse : parsing.c specific.h pars_functions.c pars_functions.h pars_test.c general.c general.h
	$(CC) parsing.c pars_functions.c pars_test.c general.c -o parse -I $(PRODUCTION) $(LDLIBS)

clean:
	rm -f parse

