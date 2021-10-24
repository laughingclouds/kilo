#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "input.h"
#include "kilo.h"
#include "terminal.h"

 /* for moving cursor in the terminal
  * I changed the original commands to that of vim */
void editorMoveCursor(int key) {
    switch (key) {
        case ARROW_LEFT:    // left
            if (E.cx != 0)
                E.cx--;
            break;
        case ARROW_RIGHT:   // right
            if (E.cx != E.screencols - 1)
                E.cx++;
            break;
        // since top left would be cy=1, decrementing would
        // take it "up" and incrementing "down"
        case ARROW_UP:      // up
            if (E.cy != 0)
                E.cy--;
            break;
        case ARROW_DOWN:    // down
            if (E.cy != E.screenrows - 1)
                E.cy++;
            break;
    }
}

void editorProcessKeypress() {
    int c = editorReadKey();

    switch (c) {
        case CTRL_KEY('q'):
            write(STDOUT_FILENO, "\x1b[2j", 4);
            write(STDOUT_FILENO, "\x1b[12;40H", 3);
            exit(0);

        case ARROW_LEFT:
        case ARROW_RIGHT:
        case ARROW_UP:
        case ARROW_DOWN:
            editorMoveCursor(c);
            break;
    }
}