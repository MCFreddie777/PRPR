// uloha9-3.c -- František Gič, 19.11.2019 15:01

#include <stdio.h>
#include <stdlib.h>

#include "../common/linked_list.h"

void zmaz(POLOZKA **prvy, int k) {
    if (*prvy == NULL) return;
    
    if (k == 0) {
        POLOZKA *temp = (*prvy)->dalsi;
        free(*prvy);
        *prvy = temp;
        return;
    }
    
    POLOZKA *akt = *prvy;
    for (int i = 0; i < k - 1; i++) {
        if (akt->dalsi == NULL) break;
        akt = akt->dalsi;
    }
    
    if (akt->dalsi == NULL) return;
    POLOZKA *temp = akt->dalsi->dalsi;
    free(akt->dalsi);
    akt->dalsi = temp;
}

int main() {
    int k;
    POLOZKA *prvy;
    scanf("%d", &k);
    prvy = nacitaj(); // nacitaj zoznam
    zmaz(&prvy, k);
    vypis(prvy); // vypis zoznam
    return 0;
}