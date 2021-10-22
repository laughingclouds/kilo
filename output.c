#include "kilo.h"
#include <unistd.h>


void editorDrawRows() {
    int y;
    for (y = 0; y < E.screenrows - 1; y++) {
        write(STDOUT_FILENO, "~\r\n", 3);
    }
    write(STDOUT_FILENO, "~", 1);
}

void editorRefreshScreen() {
    write(STDOUT_FILENO, "\x1b[2j", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);

    editorDrawRows();

    write(STDOUT_FILENO, "\x1b[H", 3);
}