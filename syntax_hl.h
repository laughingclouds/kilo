#include "kilo.h"

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

/*
 * | used in editor_ops syntax_hl*/
extern void editorUpdateSyntax(erow *row);

/*
 * | used in output */
extern int editorSyntaxToColor(int hl);
/*
 * |  used in fileio */
extern void editorSelectSyntaxHighlight();