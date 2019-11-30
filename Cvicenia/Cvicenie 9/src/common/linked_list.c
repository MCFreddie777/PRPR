//
// Created by František Gič on 19/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

POLOZKA *nacitaj() {
    POLOZKA *prvy, *akt;
    int cislo;
    
    while (scanf("%d ", &cislo) == 1) {
        if (prvy == NULL) {
            prvy = (POLOZKA *) malloc(sizeof(POLOZKA));
            akt = prvy;
        }
        else {
            akt->dalsi = (POLOZKA *) malloc(sizeof(POLOZKA));
            akt = akt->dalsi;
        }
        akt->cislo = cislo;
    }
    akt->dalsi = NULL;
    
    return prvy;
}

void vypis(POLOZKA *prvy) {
    POLOZKA *akt = prvy;
    
    if (prvy == NULL) {
        printf("Prazdny zoznam");
        return;
    }
    
    while (akt != NULL) {
        if (akt != prvy)
            printf("-> ", akt->cislo);
        printf("%d ", akt->cislo);
        akt = akt->dalsi;
    }
    printf("\n");
}
