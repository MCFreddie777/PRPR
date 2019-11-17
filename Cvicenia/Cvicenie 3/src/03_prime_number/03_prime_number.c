// uloha3-3.c -- František Gič, 8.10.2019 10:05

#include <stdio.h>

int zisti_prvocislo(int cislo) {
    for (int i = 2; i <= cislo / 2; i++)
        if (cislo % i == 0)
            return -1;
    return 1;
}

int main() {
    int a, b, counter = 0;
    scanf("%d %d", &a, &b);

    for (int i = a + 1; i <= b; i++) {
        if (i > 1 && zisti_prvocislo(i) == 1) {
            printf("%d\n", i);
            counter++;
        }
    }
    if (counter == 0) printf("Prvocislo neexistuje\n");

    return 0;
}