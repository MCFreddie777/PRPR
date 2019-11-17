// uloha5-5.c -- František Gič, 26.10.2019 15:44

#include <stdio.h>

struct File {
    FILE *file;
    char *path;
    char mode[2];
};

struct Buffer {
    char chars[100];
    int size;
    short max;
};

int main() {

    struct File files[] = {
            {
                    .path = "prvy.txt",
                    .mode = "r"
            },
            {
                    .path = "druhy.txt",
                    .mode = "r"
            },
    };

    // Open the files
    for (int i = 0; i < ((int) (sizeof(files) / sizeof(files[0]))); i++) {
        if ((files[i].file = fopen(files[i].path, files[i].mode)) == NULL) {
            printf("Subor %s sa nepodarilo otvorit.\n", files[i].path);
            return 0;
        }
    }

    // Fill the buffers
    struct Buffer buffer0 = {.size = 0}, buffer1 = {.size = 0};

    int i = 0;
    while ((buffer0.chars[i++] = getc(files[0].file)) != EOF) buffer0.size++;

    i = 0;
    while ((buffer1.chars[i++] = getc(files[1].file)) != EOF) buffer1.size++;

    // Close files
    for (int i = 0; i < ((int) (sizeof(files) / sizeof(files[0]))); i++) {
        if ((fclose(files[i].file) == EOF)) {
            printf("Subor %s sa nepodarilo zatvorit.\n", files[i].path);
            return 0;
        }
    }

    short identical = 1;
    int diff = 0;

    // Get the maximum and minimum
    int max = (buffer0.size > buffer1.size) ? buffer0.size : buffer1.size;
    int min = (buffer0.size > buffer1.size) ? buffer1.size : buffer0.size;
    if (max != min) identical = 0;

    for (int i = 0; i < min; i++)
        if (buffer0.chars[i] != buffer1.chars[i]) {
            identical = 0;
            diff++;
        }

    if (identical) printf("Subory su identicke\n");
    else {
        printf("Pocet roznych znakov: %d\n", diff);
    }
    if (max != min) {
        printf("Jeden zo suborov je dlhsi o %d znakov\n", max - min);
    }
    return 0;
}