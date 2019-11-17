// uloha7-4.c -- František Gič, 5.11.2019 11:28

#include <stdio.h>
#include <string.h>

void odstran_male_pismena(char *str) {
    char pom[1000];
    int index = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            pom[index++] = str[i];
        }
    }
    pom[index] = '\0';
    strcpy(str,pom);
}


int main() {
    char buf[1000];

    while (scanf("%s", buf) == 1) {
        odstran_male_pismena(buf);
        printf("%s\n",buf);
    }
    return 0;
}