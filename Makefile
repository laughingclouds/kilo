CC=gcc
CFLAGS=-Wall -Wextra

ODIR=obj

DEPS = abuf.h input.h kilo.h output.h terminal.h

_OBJ = abuf.o input.o kilo.o output.o terminal.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

kilo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o