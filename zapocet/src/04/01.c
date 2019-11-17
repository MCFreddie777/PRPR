#include <stdio.h>

int main() {
    unsigned int x = 1, y = 2;

    printf("%d\n", (x && y) | x);
    printf("%d\n", (x | y) || x);
    printf("%d\n", (x ^ y));
    printf("%d\n", (x << y));

    return 0;
}