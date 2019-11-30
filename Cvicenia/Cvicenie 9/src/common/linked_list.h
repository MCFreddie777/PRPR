//
// Created by František Gič on 19/11/2019.
//

#ifndef TURING_CVIC9_LINKED_LIST_H
#define TURING_CVIC9_LINKED_LIST_H


typedef struct Polozka {
    int cislo;
    struct Polozka *dalsi;
} POLOZKA;

POLOZKA *nacitaj();

void vypis(POLOZKA *);

#endif //TURING_CVIC9_LINKED_LIST_H
