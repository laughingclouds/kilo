/**/
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

/*
 * | used in editor_ops fileio*/
extern char *editorPrompt(char *prompt, void (*callback)(char *, int));

/* deal with custom key combinations
 * | used in kilo*/
extern void editorProcessKeypress();