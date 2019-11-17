// uloha5-1.c -- František Gič, 22.10.2019 10:00

#include <stdio.h>

#define OBVOD(x, y) (2*(x+y))

char *mojstrchr(char *s1, char c) {
    int i = 0;
    while (s1[i] != NULL) {
        if (s1[i] == c) return &s1[i];
        i++;
    }
    return NULL;
}

char *mojstrcpy(char *s1, char *s2) {
    int i = 0;
    while (s2[i] != NULL) {
        s1[i] = s2[i];
        i++;
    }
    return s1;
}

int main(void) {
    char name[] = "Ferko";
    char name2[5];
    printf("mojstr: %c\n", *mojstrchr(name, 'e'));
    mojstrcpy(name2,name);
    printf("name2: %s\n",name2);
}