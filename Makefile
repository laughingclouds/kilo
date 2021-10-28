CC=gcc
CFLAGS=-Wall -Wextra

ODIR=obj

DEPS = editor_ops.h fileio.h input.h kilo.h output.h syntax_hl.h terminal.h

_OBJ = editor_ops.o fileio.o input.o kilo.o output.o syntax_hl.o terminal.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#exists_$(ODIR):
#	if [ -d $(ODIR) ]; then echo "directory: $(ODIR) exists" ; else echo "directory not found, creating one"; mkdir $(ODIR); fi

$(ODIR)/%.o: %.c $(DEPS)
	$(obj_exists)
	$(CC) -c -o $@ $< $(CFLAGS)

kilo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o