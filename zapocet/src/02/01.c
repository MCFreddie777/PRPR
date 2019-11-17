// uloha5-1.c -- František Gič, 22.10.2019 10:00

#include <stdio.h>

char *f();

int main(void) {
    short comment = 0;
    FILE *f = fopen("TurboPascal.txt", "r");

    char c;
    while ((c = getc(f)) != EOF) {
        if (c == '{') {
            comment = 1;
        }
        else if (!comment) {
            putchar(c);
        }
        else if (c == '}') {
            comment = 0;
        }

    }

    fclose(f);
}