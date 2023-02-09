#Makefile

CC = gcc
CPPFLAGS =
CFLAGS = -Wall -Wextra  `pkg-config --cflags gtk+-3.0 sdl2`
LDFLAGS =
LDLIBS = `pkg-config --libs gtk+-3.0 sdl2 SDL2_image` -lm


SRC = main.c 
OBJ = ${SRC:.c=.o}
EXE = ${SRC:.c=}

main:${OBJ}
.PHONY:clean
clean:
	${RM} ${OBJ}
	${RM} ${EXE}
#END
