#include <stdio.h>
#include <stdlib.h>

void push(int *arr, int value, int *arrSize) {
    realloc(arr, sizeof(int) * (*arrSize + 1));
    arr[*arrSize] = value;
    *arrSize = *arrSize + 1;
}

int main() {
    int size = 0;
    int *arr = malloc(size * sizeof(int));

    FILE *f;
    if ((f = fopen("subor.txt", "r")) != NULL) {
        char c;
        short flag = 1;

        while ((c = getc(f)) != EOF) {
            if ((c >= '1') && (c <= '9') && (flag == 1)) {
                push(arr, c - '0', &size);
                flag = 0;
            }

            // set reading mode to true if end of the line
            if (c == '\n' || c == '\0') {
                flag = 1;
            }
        }

        if (fclose(f) == EOF) {
            printf("Nezatvoreny subor");
        }

        int max = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] > max) max = arr[i];
        }

        printf("Maximum zo suboru je cislo %d\n",max);
    }
    return 0;
}