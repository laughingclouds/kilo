#include <stdlib.h>
#include <unistd.h>

#include "kilo.h"
#include "terminal.h"

void editorProcessKeypress() {
    char c = editorReadKey();

    switch (c) {
        case CTRL_KEY('q'):
            write(STDOUT_FILENO, "\x1b[2j", 4);
            write(STDOUT_FILENO, "\x1b[12;40H", 3);
            exit(0);
            break;
    }
}