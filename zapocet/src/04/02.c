#include <stdio.h>


char *returnCharPtr(char *pismeno) {
    printf("Adresa pismena %c vo funkcii returnCharPtr: %p\n", *pismeno, pismeno);
    char *ptr;
    ptr = pismeno;
    return ptr;
}

int main() {
    char *(*p)(char *) = &returnCharPtr;

    char pismeno = 'z';
    printf("Adresa pismena %c v premennej pismeno: %p\n", pismeno, &pismeno);

    char *novePismeno = (*p)(&pismeno);
    printf("Adresa pismena %c v premennej novePismeno: %p\n", *novePismeno, novePismeno);

    return 0;
}