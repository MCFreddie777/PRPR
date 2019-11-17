#include <stdio.h>

int main() {
    char c, *p1, *p2;

    c = 'b';
    p1 = &c;
    p2 = p1;

    printf("%c %c %c\n", c, *p1 + 1, *p2);
    *p1 = c + 3;
    printf("%c %c %c\n", c, *p1, *p2+1);

    return 0;
}