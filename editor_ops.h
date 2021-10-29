#include <stddef.h>

#include "kilo.h"

/*| used in output*/
extern int editorRowCxToRx(erow *row, int cx);

/*| used in fileio*/
extern void editorInsertRow(int at, char *s, size_t len);

/*| used in input*/
extern void editorInsertChar(int c);

/*| used in input*/
extern void editorInsertNewline();

/*| used in input*/
extern void editorDelChar();

/*| used in input*/
extern void editorFind();