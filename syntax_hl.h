#include "kilo.h"

#define HL_HIGHLIGHT_NUMBERS (1<<0)
#define HL_HIGHLIGHT_STRINGS (1<<1)
#define HLDB_ENTRIES (sizeof(HLDB) / sizeof(HLDB[0]))

#ifndef  EDITORHIGHLIGHT

#define EDITORHIGHLIGHT
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

extern struct editorSyntax HLDB[];

extern int is_separator(int c);
extern void editorUpdateSyntax(erow *row);
extern int editorSyntaxToColor(int hl);
extern void editorSelectSyntaxHighlight();