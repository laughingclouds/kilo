/* I've decided to put all (or most) of my defines or structs in
 * this header file to avoid being confused and feeling lost. */
#include <termios.h>
#include <time.h>

#define KILO_VERSION "0.0.1"
#define KILO_TAB_STOP 8
#define KILO_QUIT_TIMES 3

#define CTRL_KEY(k) ((k)&0x1f)
#define ABUF_INIT { NULL, 0 }

#define HL_HIGHLIGHT_NUMBERS (1 << 0)
#define HL_HIGHLIGHT_STRINGS (1 << 1)

#ifndef EDITORKEY
#define EDITORKEY
enum editorKey {
  BACKSPACE = 127,
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN,
  DEL_KEY,
  HOME_KEY,
  END_KEY,
  PAGE_UP,
  PAGE_DOWN
};
#endif

#ifndef EDITORHIGHLIGHTMACRO
#define EDITORHIGHLIGHTMACRO
enum editorHighlight {
  HL_NORMAL = 0,
  HL_COMMENT,
  HL_MLCOMMENT,
  HL_KEYWORD1,
  HL_KEYWORD2,
  HL_STRING,
  HL_NUMBER,
  HL_MATCH
};
#endif

/*** data ***/
#ifndef EDITORSYNTAX
#define EDITORSYNTAX
struct editorSyntax {
  char *filetype;
  char **filematch;
  char **keywords;
  char *singleline_comment_start;
  char *multiline_comment_start;
  char *multiline_comment_end;
  int flags;
};
#endif

#ifndef EROW
#define EROW
typedef struct erow {
  int idx;
  int size;
  int rsize;
  char *chars;
  char *render;
  unsigned char *hl;
  int hl_open_comment;
} erow;
#endif

#ifndef EDITORCONFIG
#define EDITORCONFIG
struct editorConfig {
  int cx, cy;
  int rx;
  int rowoff;
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

#ifndef ABUF
#define ABUF
struct abuf {
  char *b;
  int len;
};
#endif