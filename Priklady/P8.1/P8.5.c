#include <stdio.h>

typedef struct student
{   char meno[50];
    int poradie;
    float prog;
    float mat;
    float fyz;
}STUDENT;

STUDENT s[10];

int main()
{
    int i;
    float priemer;
    printf("Zadaj informacie o 10 studentoch :\n");
    for(i=0; i<10; ++i)
    {
        s[i].poradie = i+1;
        printf("\n%d.\n",s[i].poradie);
        printf("Zadaj meno: ");
        scanf("%s",s[i].meno);
        printf("\nZadaj body programovanie matematika fyzika: ");
        scanf("%f %f %f",&s[i].prog, &s[i].mat, &s[i].fyz);
        printf("\n");
    } 
printf("Vysledna informacia:\n\n");
    
    for(i=0; i<10; ++i)
    {
        printf("\n%d. student\n",i+1);
        printf("Meno: ");
        puts(s[i].meno);
        printf("\nbody programovanie: %.1f",s[i].prog);
        printf("\nbody matematika: %.1f",s[i].mat);
        printf("\nbody fyzika: %.1f",s[i].fyz);
        printf("\npriemerny pocet bodov: %.2f",(s[i].prog + s[i].mat + s[i].fyz)/3.);
        printf("\n");
    }
    return 0;
}


