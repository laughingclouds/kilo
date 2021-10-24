/* for moving cursor in the terminal
  * I changed the original commands to that of vim */
//extern void editorMoveCursor(char key);

/**/
enum editorKey {
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN 
};

/* deal with custom key combinations */
extern void editorProcessKeypress();