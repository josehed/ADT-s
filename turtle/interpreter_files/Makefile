CC=gcc
Clang=clang
CCC=/usr/local/bin/gcc-10
COMMON= -Wall -Wextra -Wfloat-equal -pedantic -std=c90
DEBUG= -g3
SANITIZE= $(COMMON) -fsanitize=undefined -fsanitize=address -fno-omit-frame-pointer $(DEBUG)
VALGRIND= $(COMMON) $(DEBUG)
PRODUCTION= $(COMMON) -O3
LDLIBS = -lm
SDLCFLAGS=`sdl2-config --cflags`
SDLLIBS=`sdl2-config --libs`

interp : interp.c specific.h interp_functions.c interp_test.c general.c general.h realloc.c stack.h neillsdl2.c neillsdl2.h interp_functions.h
	$(CC) neillsdl2.c realloc.c interp.c interp_functions.c interp_test.c general.c -o interp -I $(PRODUCTION) $(LDLIBS) $(SDLCFLAGS) $(SDLLIBS)

clean:
	rm -f interp

