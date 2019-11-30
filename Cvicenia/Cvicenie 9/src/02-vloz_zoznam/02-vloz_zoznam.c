// uloha9-2.c -- František Gič, 19.11.2019 10:50

#include <stdio.h>
#include <stdlib.h>

#include "../common/linked_list.h"

void vloz(POLOZKA **prvy, int cislo, int k) {
    
    if (*prvy == NULL) {
        *prvy = (POLOZKA *) malloc(sizeof(POLOZKA));
        (*prvy)->cislo = cislo;
        (*prvy)->dalsi = NULL;
        return;
    }
    
    if (k == 0) {
        POLOZKA *temp = *prvy;
        *prvy = (POLOZKA *) malloc(sizeof(POLOZKA));
        (*prvy)->cislo = cislo;
        (*prvy)->dalsi = temp;
        return;
    }
    
    POLOZKA *akt;
    akt = *prvy;
    
    // traverse the linked list until the found
    for (int i = 1; i < k; i++) {
        if (akt->dalsi == NULL) break;
        akt = akt->dalsi;
    }
    
    // save the current pointer to the next
    POLOZKA *temp = akt->dalsi;
    akt->dalsi = (POLOZKA *) malloc(sizeof(POLOZKA));
    akt = akt->dalsi;
    akt->dalsi = temp;
    akt->cislo = cislo;
}

int main() {
    int cislo, k;
    POLOZKA *prvy;
    
    scanf("%d %d", &cislo, &k);
    prvy = nacitaj();
    vloz(&prvy, cislo, k);
    vypis(prvy);
    return 0;
}