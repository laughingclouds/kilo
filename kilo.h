#include <termios.h>

#define KILO_VERSION "0.0.1"
#define CTRL_KEY(k) ((k) & 0x1f)

/* editor row */
typedef struct erow {
    int size;
    char *chars;
} erow;

/*Global editor state*/
struct editorConfig {
    int cx, cy; //cursor coordinates
    int screenrows;
    int screencols;
    int numrows;
    erow row;
    struct termios orig_termios;
};

extern struct editorConfig E; 