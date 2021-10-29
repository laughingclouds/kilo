#include <stddef.h>

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