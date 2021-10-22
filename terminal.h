/* functions to work with terminal*/
extern void die(const char *s);

extern void disableRawMode();

extern void enableRawMode();

extern char editorReadKey();

extern int getCursorPosition(int *rows, int *cols);

extern int getWindowSize(int *rows, int *cols);