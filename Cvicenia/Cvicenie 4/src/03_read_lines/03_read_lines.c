// uloha5-3.c -- František Gič, 22.10.2019 10:53

#include <stdio.h>
#include <string.h>

#define ARR_SIZE 60

struct File {
    FILE *file;
    char *path;
    char line[ARR_SIZE];
    char mode[2];
};

struct File files[] = {
        {
                .path =  "vstup.txt",
                .mode = "r"
        },
        {
                .path = "cisla.txt",
                .mode = "a+"
        }
};

int main() {

    for (int i = 0; i < ((int) (sizeof(files) / sizeof(files[0]))); i++) {
        if ((files[i].file = fopen(files[i].path, files[i].mode)) == NULL) {
            printf("Subor %s sa nepodarilo otvorit.\n", files[i].path);
            return 0;
        }
    }

    while (s[0].line, ARR_SIZE, files[0].file) != NULL) {
        int count = 0;
        for (int i = 0; i < ARR_SIZE; i++) {
            if ((files[0].line[i] >= 97) && ((int) files[0].line[i] <= 122)) {
                count++;
            }
        }

        fputs(files[0].line, files[1].file);
        if (files[0].line[strlen(files[0].line) - 1] != '\n')
            fputc('\n', files[1].file);
        fprintf(files[1].file, "%d\n", count);
    }


    for (int i = 0; i < ((int) (sizeof(files) / sizeof(files[0]))); i++) {
        if ((fclose(files[i].file) == EOF)) {
            printf("Subor %s sa nepodarilo zatvorit.\n", files[i].path);
            return 0;
        }
    }

    return 0;
}