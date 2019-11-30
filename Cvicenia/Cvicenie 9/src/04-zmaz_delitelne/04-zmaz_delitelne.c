// uloha9-4.c -- František Gič, 19.11.2019 15:53

#include <stdio.h>
#include <stdlib.h>

#include "../common/linked_list.h"

void zmaz_delitelne(POLOZKA **prvy, int k) {
    if (*prvy == NULL) return;
    
    POLOZKA *predch = NULL;
    POLOZKA *akt = *prvy;
    
    while (akt != NULL) {
        if (akt->cislo % k == 0) {
            POLOZKA *temp;
            
            if (predch == NULL) {
                temp = (*prvy)->dalsi;
                free(*prvy);
                *prvy = temp;
                akt = *prvy;
            }
            else {
                predch->dalsi = akt->dalsi;
                free(akt);
                akt = predch->dalsi;
            }
        }
        else {
            predch = akt;
            akt = akt->dalsi;
        }
    }
}

int main() {
    int k;
    POLOZKA *prvy;
    scanf("%d", &k);
    prvy = nacitaj(); // nacitaj zoznam
    zmaz_delitelne(&prvy, k);
    vypis(prvy); // vypis zoznam
    return 0;
}