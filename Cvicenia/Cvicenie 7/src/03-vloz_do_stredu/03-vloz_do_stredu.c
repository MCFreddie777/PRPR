// uloha7-3.c -- František Gič, 5.11.2019 11:11

#include <stdio.h>
#include <string.h>


#define N 1000

void vloz_do_stredu(char *str, char c) {
    int len = strlen(str);
    int i;
    for (i = len - 1; i >= (len / 2); i--) {
        str[i + 1] = str[i];
    }
    str[i + 1] = c;
    for (i = len+1; i < N; i++) {
        str[i] = '\0';
    }
}

int main() {
    char buf[N], znak[10];

    while (scanf("%s %s", buf, znak) == 2) {
        vloz_do_stredu(buf, znak[0]);
        printf("%s\n", buf);
    }
    return 0;
}