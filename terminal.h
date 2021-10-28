/* functions and definitions to work with terminal*/

/* Exits with error message 
 * | used in kilo terminal fileio*/
extern void die(const char *s);

/* Edits original terminal io settings to enable raw mode 
 * | used in kilo*/
extern void enableRawMode();

/* returns: character input from STDIN
 * | used in input*/
extern char editorReadKey();

/* tries to get window size from ioctl, otherwise manually tries to do so
 * returns: -1 for error, else 0 
 * | used in kilo */
extern int getWindowSize(int *rows, int *cols);