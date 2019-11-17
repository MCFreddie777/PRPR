#include <stdio.h>

float tax(float num,float tax_rate) {
    return num*(1+(0.01*tax_rate));
}

int main() {
    float num;
    scanf("%f",&num);

    printf("Cena bez dane: %g\n",num);
    printf("Predajna cena s danou %d%%: %.1f",20,tax(num,20));
    return 0;
}

