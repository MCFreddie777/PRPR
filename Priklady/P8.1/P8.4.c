//P8.4 Struktury a polia
#include<stdio.h>
#define POCET 3

struct pole{
       char meno[20];
       double vaha;
       double vyska;
       } osoba[POCET]={"Jozef Maly",95.5,161,"Jan Mrkvicka",75.7, 175.5,"Pavol Velky",80.3,199};

int main()
{
    int i,index;
    double max=osoba[0].vyska;
    for(i=0;i<POCET;i++){
        printf("***polozka cislo %d.***\n",i+1);
        printf("meno: %s\n",osoba[i].meno);
        printf("vaha:  %.2lf\n",osoba[i].vaha);
        printf("vyska: %.2lf\n",osoba[i].vyska);
        printf("**********************\n\n");
     }
     for(i=0;i<POCET;i++) {if(osoba[i].vyska>=max) index=i; }
    printf("Najvyssia osoba je %s (%.2lf cm)\n", osoba[index]. meno, osoba[index].vyska);
return 0;
}

