CC=gcc
CFLAGS=-Wall -Wextra
OBJ = kilo.c

kilo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
