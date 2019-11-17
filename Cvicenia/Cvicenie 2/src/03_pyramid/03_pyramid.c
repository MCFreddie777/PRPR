#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);
    if (N < 1 || N > 15)  {
        printf("Cislo nie je z daneho intervalu\n");
        return 0;
    }
    else
        for (int i = 0; i < N; i++) {
            printf("%d:",(i+1));
            for (int j = N - i; j > 0; j--) {
                printf(" %d",j);
            }
            printf("\n");
        }

    return 0;
}

