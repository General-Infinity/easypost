CC = gcc
CF = main.c
FN = easypost
CFLAGS = -O2 -Wall -lcurl -o ${FN}
all:
	${CC} ${CF} ${CFLAGS}