// uloha9-7.c -- František Gič, 19.11.2019 19:54

#include <stdio.h>
#include <stdlib.h>

#include "../common/linked_list.h"

void opacny_vypis_rekur(POLOZKA *prvy) {
    
    if (prvy == NULL)
        printf("Prazdny zoznam\n");
    else {
        if (prvy->dalsi != NULL) {
            opacny_vypis_rekur(prvy->dalsi);
            printf(" -> ");
        }
        printf("%d", prvy->cislo);
    }
}

int main() {
    POLOZKA *prvy;
    prvy = nacitaj(); // nacitaj zoznam
    opacny_vypis_rekur(prvy);
    return 0;
}