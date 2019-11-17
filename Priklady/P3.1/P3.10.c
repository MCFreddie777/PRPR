#include <stdio.h>
int main()
{
    int n, i;
    unsigned long long faktorial = 1;
    printf("Zadaj cele cislo: ");
    scanf("%d",&n);
    // Chyba
    if (n < 0)
        printf("Chyba! Faktorial zaporneho cisla neexistuje");
    else
    {
        for(i=1; i<=n; ++i)
        {
            faktorial *= i;              // faktorial = faktorial*i;
        }
        printf("Faktorial  %d = %llu", n, faktorial);
    }
    return 0;
}
