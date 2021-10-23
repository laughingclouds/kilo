#define ABUF_INIT {NULL, 0}

/*** append buffer ***/
struct abuf {
    char *b;    // stands for buffer
    int len;
};

/* append `len` bytes of string s to ab->b (buffer) */
extern void abAppend(struct abuf *ab, const char *s, int len);

/* deallocates dynamic memory used by ab */
extern void abFree(struct abuf *ab);