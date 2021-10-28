#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "kilo.h"

/***Append buffer***/
void abAppend(struct abuf *ab, const char *s, int len) {
  char *new = realloc(ab->b, ab->len + len);

  if (new == NULL)
    return;
  memcpy(&new[ab->len], s, len);
  ab->b = new;
  ab->len += len;
}

void abFree(struct abuf *ab) { free(ab->b); }

void editorScroll() {
  if (E.cy < E.rowoff)
    E.rowoff = E.cy;

  if (E.cy >= E.rowoff + E.screenrows)
    E.rowoff = E.cy - E.screenrows + 1;

  if (E.cx < E.coloff)
    E.coloff = E.cx;

  if (E.cx >= E.coloff + E.screencols)
    E.coloff = E.cx - E.screencols + 1;
}

/*** output ***/
void editorDrawRows(struct abuf *ab) {
  for (int y = 0; y < E.screenrows; y++) {
    int filerow = y + E.rowoff;
    if (filerow >= E.numrows) {
      if (E.numrows == 0 && y == E.screenrows / 3) {
        char welcome[80];
        int welcomelen = snprintf(welcome, sizeof(welcome),
                                  "Kilo editor --version %s", KILO_VERSION);

        if (welcomelen > E.screencols)
          welcomelen = E.screencols;
        int padding = (E.screencols - welcomelen) / 2;
        if (padding) {
          // putting a "~" in the line of the welcome msg then
          // decrementing padding to not mess up the msg position
          abAppend(ab, "~", 1);
          padding--;
        }
        // putting spaces to bring the welcome msg to the center
        while (padding--)
          abAppend(ab, " ", 1);
        abAppend(ab, welcome, welcomelen);
      } else {
        abAppend(ab, "~", 1);
      }
    } else {
      int len = E.row[filerow].size;
      if (len < 0)
        len = 0;
      if (len > E.screencols)
        len = E.screencols;
      abAppend(ab, E.row[filerow].chars, len);
    }

    abAppend(ab, "\x1b[k", 3);
    if (y < E.screenrows - 1)
      abAppend(ab, "\r\n", 2);
  }
}

void editorRefreshScreen() {
  editorScroll();

  struct abuf ab = ABUF_INIT;

  abAppend(&ab, "\x1b[?25l", 6);
  abAppend(&ab, "\x1b[H", 3);

  editorDrawRows(&ab);

  char buf[32]; // bring cursor to (cx, cy) after drawing rows
  snprintf(buf, sizeof(buf), "\x1b[%d;%dH", (E.cy - E.rowoff), E.cx + 1);
  abAppend(&ab, buf, strlen(buf));

  abAppend(&ab, "\x1b[?25h", 6);

  write(STDOUT_FILENO, ab.b, ab.len);
  abFree(&ab);
}

void editorSetStatusMessage(const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  vsnprintf(E.statusmsg, sizeof(E.statusmsg), fmt, ap);
  va_end(ap);
  E.statusmsg_time = time(NULL);
}