/*
 * continue from here
 * https://viewsourcecode.org/snaptoken/kilo/03.rawInputAndOutput.html#append-buffer
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "abuf.h"
#include "input.h"
#include "kilo.h"
#include "output.h"
#include "terminal.h"


/*** data ***/
struct editorConfig E;

/*** init ***/
void initEditor() {
	if (getWindowSize(&E.screenrows, &E.screencols) == -1) die("getWindowsSize");
}

int main() {
    enableRawMode();
    initEditor();

    while (1) {
        editorRefreshScreen();
        editorProcessKeypress();
    }
    return 0;
}
