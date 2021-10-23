#include <stdlib.h>
#include <unistd.h>

#include "kilo.h"
#include "terminal.h"

 /* for moving cursor in the terminal
  * I changed the original commands to that of vim */
void editorMoveCursor(char key) {
    switch (key) {
        case 'h':
            E.cx--; break;
        case 'l':
            E.cx++; break;
        // since top left would be cy=1, decrementing would
        // take it "up" and incrementing "down"
        case 'k':
            E.cy--; break;
        case 'j':
            E.cy++; break;
    }
}

void editorProcessKeypress() {
    char c = editorReadKey();

    switch (c) {
        case CTRL_KEY('q'):
            write(STDOUT_FILENO, "\x1b[2j", 4);
            write(STDOUT_FILENO, "\x1b[12;40H", 3);
            exit(0);
        case 'h':
        case 'l':
        case 'j':
        case 'k':
            editorMoveCursor(c);
            break;
    }
}