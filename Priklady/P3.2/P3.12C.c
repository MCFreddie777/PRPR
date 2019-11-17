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
    int n, i, flag = 0;
    printf("Zadaj cele cislo : ");
    scanf("%d", &n);
    for(i = 2; i <= n/2; ++i)
    {
        // podmienka pre i je prvocislo
        if (zisti_prvocislo(i) == 1)
        {
            // podmienka pre n-i je prvocislo
            if (zisti_prvocislo(n-i) == 1)
            {
                // n = prvocislo1 + prvocislo2
                printf("%d = %d + %d\n", n, i, n - i);
                flag = 1;
            }
        }
    }
    if (flag == 0)
        printf("Cislo %d nemozeme zapisat ako sucet dvoch prvocisel.", n);
    return 0;
}


