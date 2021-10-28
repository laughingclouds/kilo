#include <termios.h>
#include <time.h>

#define KILO_VERSION "0.0.1"
#define KILO_TAB_STOP 8
#define KILO_QUIT_TIMES 3
#define CTRL_KEY(k) ((k) & 0x1f)

#if !defined (EROW) || !defined (EDITORCONFIG)
#define EROW
#define EDITORCONFIG
/* editor row */
typedef struct erow {
    int idx;
    int size;
    int rsize;
    char *chars;
    char *render;
    unsigned char *hl;
    int hl_open_comment;
} erow;

/*Global editor state*/
struct editorConfig {
    int cx, cy; //cursor coordinates
    int rx;
    int rowoff; // offset
    int coloff;
    int screenrows;
    int screencols;
    int numrows;
    erow *row;
    int dirty;
    char *filename;
    char statusmsg[80];
    time_t statusmsg_time;
    struct editorSyntax *syntax;
    struct termios orig_termios;
};

#endif

extern struct editorConfig E; 

/*** append buffer ***/
#if !defined (ABUF_INIT) || !defined (ABUF)
#define ABUF_INIT {NULL, 0}
#define ABUF

struct abuf {
    char *b;    // stands for buffer
    int len;
};

#endif

/* append `len` bytes of string s to ab->b (buffer) */
extern void abAppend(struct abuf *ab, const char *s, int len);

/* deallocates dynamic memory used by ab */
extern void abFree(struct abuf *ab);