#include <stdio.h>

int main() {
    int i, j;

    for (i=5; i<25;i++) {                       // 5 6 7 8 9 10 .. 24
        for (j = 2; j <= i/2;j++) {             // 2, 2 3, 2 3, 2 3 4, 2 3 4, 2 3 4 5
            if (!(i%j)) break;                  // 1,0 0, 1 1, 0 1 0, 1 0 1
            if (j>i/2) printf("%d \n",i);       //  ,
        }
    }
    return 0;
}