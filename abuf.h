#define ABUF_INIT {NULL, 0}

/*** append buffer ***/
struct abuf {
    char *b;    // stands for buffer
    int len;
};
