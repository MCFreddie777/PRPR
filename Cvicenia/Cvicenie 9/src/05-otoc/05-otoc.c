// uloha9-5.c -- František Gič, 19.11.2019 17:44

#include <stdio.h>

#include "../common/linked_list.h"

void otoc(POLOZKA **prvy) {
    POLOZKA *predch = NULL;
    POLOZKA *akt = (*prvy);
    POLOZKA *dalsi = NULL;
    
    while (akt != NULL) {
        dalsi = akt->dalsi;
        akt->dalsi = predch;
        predch = akt;
        akt = dalsi;
    }
    *prvy = predch;
}

int main() {
    POLOZKA *prvy;
    prvy = nacitaj(); // nacitaj zoznam
    otoc(&prvy);
    vypis(prvy); // vypis zoznam
    return 0;
}