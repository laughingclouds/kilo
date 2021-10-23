#include <termios.h>

#define KILO_VERSION "0.0.1"
#define CTRL_KEY(k) ((k) & 0x1f)

struct editorConfig {
    int cx, cy; //cursor coordinates
    int screenrows;
    int screencols;
    struct termios orig_termios;
};

extern struct editorConfig E; 