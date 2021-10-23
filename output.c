#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "abuf.h"
#include "kilo.h"

void editorDrawRows(struct abuf *ab) {
    for (int y = 0; y < E.screenrows; y++) {
        if (y == E.screenrows / 3) {
            char welcome[80];
            int welcomelen = snprintf(welcome,
                                      sizeof(welcome),
                                      "Kilo editor --version %s",
                                      KILO_VERSION);

            if (welcomelen > E.screencols)  welcomelen = E.screencols;
            int padding = (E.screencols - welcomelen) / 2;
            if (padding) {
                //putting a "~" in the line of the welcome msg then
                //decrementing padding to not mess up the msg position
                abAppend(ab, "~", 1);
                padding--;
            }
            // putting spaces to bring the welcome msg to the center
            while (padding--) abAppend(ab, " ", 1);
            abAppend(ab, welcome, welcomelen);
        } else {
            abAppend(ab,"~", 1);
        }

        abAppend(ab, "\x1b[k", 3);
        if (y < E.screenrows - 1)
            abAppend(ab, "\r\n", 2);
    }
}

void editorRefreshScreen() {
    struct abuf ab = ABUF_INIT;

    abAppend(&ab, "\x1b[?25l", 6);
    abAppend(&ab, "\x1b[H", 3);

    editorDrawRows(&ab);

    char buf[32]; // bring cursor to (cx, cy) after drawing rows
    snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cy + 1, E.cx + 1);
    abAppend(&ab, buf, strlen(buf));

    abAppend(&ab, "\x1b[?25h", 6);

    write(STDOUT_FILENO, ab.b, ab.len);
    abFree(&ab);
}