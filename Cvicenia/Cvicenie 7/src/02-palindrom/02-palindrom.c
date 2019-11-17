// uloha7-2.c -- František Gič, 5.11.2019 10:50

#include <stdio.h>
#include <string.h>

// Funkcia zisti, ci retazec str je palindrom. Vrati 1, ak je retazec palindrom, inak 0.
int je_palindrom(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == str[len - i - 1]) {
            continue;
        } else return 0;
    }
    return 1;
}

// ukazkovy test (spracovanie vstupu)
int main(void) {
    char buf[1000];

    // nacitanie vstupu
    while (scanf("%s", buf) > 0) {
        if (je_palindrom(buf))
            printf("PALINDROM\n");
        else
            printf("NIE\n");
    }
    return 0;
}