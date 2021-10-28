/* Function declarations for terminal output*/

/***Append buffer***/
/**/
extern void abAppend(struct abuf *ab, const char *s, int len);
extern void abFree(struct abuf *ab);

/* fills screen with rows of `~` just like in vim */
extern void editorDrawRows();

extern void editorRefreshScreen();

extern void editorSetStatusMessage(const char *fmt, ...);