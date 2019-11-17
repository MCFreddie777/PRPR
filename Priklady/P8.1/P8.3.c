//P8.3 sucet komplexnych cisel
#include <stdio.h>

typedef struct complex
{
    float real;
    float imag;
} COMPLEX;

COMPLEX add(COMPLEX n1, COMPLEX n2)
{
      COMPLEX temp;

      temp.real = n1.real + n2.real;
      temp.imag = n1.imag + n2.imag;

      return temp;
}

int main()
{
    COMPLEX n1, n2, temp;

    printf("Zadaj realnu a imaginarnu cast prveho cisla \n");
    scanf("%f %f", &n1.real, &n1.imag);

    printf("Zadaj realnu a imaginarnu cast druheho cisla \n");
    scanf("%f %f", &n2.real, &n2.imag);

    temp = add(n1, n2);
    printf("Sucet = %.1f + %.1fi", temp.real, temp.imag);

return 0;
}

