#include "kilo.h"

/*** row operations ***/
/*
 * | used in output*/
extern int editorRowCxToRx(erow *row, int cx);
/*
 * | used in editor_ops fileio*/
extern void editorInsertRow(int at, char *s, size_t len);

/*** editor operations ***/
/*
 * | used in input */
extern void editorInsertChar(int c);
/*
 * | used in input */
extern void editorInsertNewline();
/*
 * | used in input */
extern void editorDelChar();

/*** find ***/
/*
 * | used in input */
extern void editorFind();