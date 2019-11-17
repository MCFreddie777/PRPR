#include <stdio.h>
// Funkcia na zistenie prvocisla
int zisti_prvocislo(int n)
{
    int i, prvocislo = 1;
    for(i = 2; i <= n/2; ++i)
    {
        if(n % i == 0)
        {
            prvocislo = 0;
            break;
        }  
    }
    return prvocislo;
}
int main()
{
    int p;
    printf("Zadaj cele cislo : ");
    if (scanf("%d", &p)>0){
    
          if (zisti_prvocislo(p) == 1)
            printf("Cislo %d je prvocislo\n", p);
          else
            printf("Cislo %d nie je prvocislo\n", p);
     }
     return 0;
}

