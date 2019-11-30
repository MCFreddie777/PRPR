// uloha9-6.c -- František Gič, 19.11.2019 19:42

#include <stdio.h>
#include <stdlib.h>

#include "../common/linked_list.h"

void vypis_rekur(POLOZKA *prvy) {
    
    if (prvy == NULL)
        printf("Prazdny zoznam\n");
    else {
        printf("%d", prvy->cislo);
        if (prvy->dalsi != NULL) {
            printf(" -> ");
            vypis_rekur(prvy->dalsi);
        }
    }
}

int main() {
    POLOZKA *prvy;
    prvy = nacitaj(); // nacitaj zoznam
    vypis_rekur(prvy);
    return 0;
}