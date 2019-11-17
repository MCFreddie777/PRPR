// uloha5-1.c -- František Gič, 22.10.2019 10:00

#include <stdio.h>

char* f();

int main(void) {
    int x;
    scanf("%d", &x);
    if (x < -5 || x >= 20)
        printf("Zadane cislo nie je z intervalu <-5,20)\n");
    return 0;
}