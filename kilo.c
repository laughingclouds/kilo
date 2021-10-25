/*
 * continue from here
 * https://viewsourcecode.org/snaptoken/kilo/04.aTextViewer.html
*/

#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#define _GNU_SOURCE

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "abuf.h"
#include "fileio.h"
#include "input.h"
#include "kilo.h"
#include "output.h"
#include "terminal.h"


/*** data ***/
struct editorConfig E;

/*** init ***/
void initEditor() {
    E.cx = 0;
    E.cy = 0;
    E.rowoff = 0;
    E.numrows = 0;
    E.row = NULL;

	if (getWindowSize(&E.screenrows, &E.screencols) == -1)
        die("getWindowsSize");
}

int main(int argc, char **args) {
    enableRawMode();
    initEditor();
    if (argc > 1)
        editorOpen(args[1]);

    while (1) {
        editorRefreshScreen();
        editorProcessKeypress();
    }
    return 0;
}
