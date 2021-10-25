#include <stdio.h>

/*Printing numbers using different looping constructs*/

int main() {
    int x;
    for (x = 0; x < 4; x++)
        printf("%i ", x);
    printf("\n");

    x = 0;
    while (x < 4) {
        printf("%i ", x);
        x++;
    }
    printf("\n");

    x = 0;
    do {
        printf("%i ", x);
        x++;
    } while (x < 4);
    printf("\n");
}