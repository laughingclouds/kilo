/* functions and definitions to work with terminal*/

/* Exits with error message */
extern void die(const char *s);

/* Reverts to the original terminal settings */
extern void disableRawMode();

/* Edits original terminal io settings to enable raw mode */
extern void enableRawMode();

/* returns: character input from STDIN */
extern char editorReadKey();

/* saves cursor positions into `rows` and `cols`
 * returns: -1 for error, else 0 */
extern int getCursorPosition(int *rows, int *cols);

/* tries to get window size from ioctl, otherwise manually tries to do so
 * returns: -1 for error, else 0 */
extern int getWindowSize(int *rows, int *cols);