//P8.7 Naplnenie a vypis struktury (nie linearny zoznam) pomocou funkcii roznym sposobom
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
   char meno[30];
   int rocnik;
} STUDENT;

STUDENT *vytvor1(void) 
{
    STUDENT *p;
    p = (STUDENT *) malloc(sizeof(STUDENT));
    if (p == NULL) 
        printf("Malo pamate.\n");
    return p;
}

void vytvor2(STUDENT **p) 
{
    *p = (STUDENT *) malloc(sizeof(STUDENT));
    if (*p == NULL) 
        printf("Malo pamate.\n");
}

void nastav(STUDENT *p, char *meno, int rok) 
{
    p->rocnik = rok;
    strcpy(p->meno, meno);
}

void vypis(STUDENT *p_prvy){  
  STUDENT *p_akt;
  p_akt = p_prvy; 
 
  printf("\nrocnik:%d ", p_akt ->rocnik);
  printf("\nmeno:%s ", p_akt ->meno);
}

int main() 
{
    STUDENT  s, *p_s1, *p_s2;
    p_s1 = vytvor1();//vrati smernik na strukturu
    vytvor2(&p_s2);//nastavi adresu struktury do parametra
    //s.rocnik = p_s1->rocnik = 1;
    
    nastav(&s, "Jan", 1);
    nastav(p_s1, "Peter", 2);
    nastav(p_s2, "Michal", 3);
    vypis(&s);
    vypis(p_s1);
    vypis(p_s2);
return 0;
}

