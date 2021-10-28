/* Function declarations for terminal output*/

/*
 * | used in kilo input*/
extern void editorRefreshScreen();

/*
 * | used in fileio input kilo*/
extern void editorSetStatusMessage(const char *fmt, ...);

/*** append buffer ***/
#if !defined (ABUF_INIT) || !defined (ABUF)
#define ABUF_INIT {NULL, 0}
#define ABUF

struct abuf {
    char *b;    // stands for buffer
    int len;
};

#endif