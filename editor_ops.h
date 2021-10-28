#include "kilo.h"

/*** row operations ***/
extern int editorRowCxToRx(erow *row, int cx);
extern int editorRowRxToCx(erow *row, int rx);
extern void editorUpdateRow(erow *row);
extern void editorInsertRow(int at, char *s, size_t len);
extern void editorFreeRow(erow *row);
extern void editorDelRow(int at);
extern void editorRowInsertChar(erow *row, int at, int c);
extern void editorRowAppendString(erow *row, char *s, size_t len);
extern void editorRowDelChar(erow *row, int at);

/*** editor operations ***/
extern void editorInsertChar(int c);
extern void editorInsertNewline();
extern void editorDelChar();

/*** find ***/
extern void editorFindCallback(char *query, int key);
extern void editorFind();