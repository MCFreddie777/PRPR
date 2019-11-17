// uloha7-5.c -- František Gič, 5.11.2019 13:51

#include <ctype.h>
#include <stdio.h>
#include <string.h>

char najcastejsi_znak(char *str) {
    const int range = (int) 'z' - (int) 'a';
    int abeceda[range];
    memset(abeceda, 0, sizeof abeceda);

    for (int i = 0; i < strlen(str); i++) {
        abeceda[str[i] - 'a']++;
    }

    int max = 0;
    for (int i = 0; i < range; i++) {
        if (abeceda[i] >= abeceda[max]) max = i;
    }

    return (char) ('a' + max);
}

int main(void) {
    char buf[1000];
    while (fgets(buf, 1000, stdin))
        printf("%c\n", najcastejsi_znak(buf));
    return 0;
}