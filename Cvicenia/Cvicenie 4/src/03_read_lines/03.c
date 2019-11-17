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

int number_of_lowercase_chars(char *line) {
    printf("%s\n", line);
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%c %d %d\n", line[i], line[i], (line[i] >= 97) && (line[i] <= 122));
    }
    return 1;
}

#define LEN 2

int main() {

    for (int i = 0; i < ((int) (sizeof(files) / sizeof(files[0]))); i++) {
        if ((files[i].file = fopen(files[i].path, files[i].mode)) == NULL) {
            printf("Subor %s sa nepodarilo otvorit.\n", files[i].path);
            return 0;
        }

        while (fgets(files[0].line, ARR_SIZE, files[0].file) != NULL) {
            number_of_lowercase_chars(files[0].line);

            int count = 0;
            for (int i = 0; i < ARR_SIZE; i++) {
                printf("%c %d %d\n", files[0].line[i], files[0].line[i],
                       (files[0].line[i] >= 97) && (files[0].line[i] <= 122));
                if ((files[0].line[i] >= 97) && ((int) files[0].line[i] <= 122)) {
                    count++;
                }
            }
            printf("count: %d\n", count);

//            int count = number_of_lowercase_chars(&files[0].line);
//            fputs(files[0].line, files[1].file);
//            fprintf(files[1].file, "%d\n", 1);
        }

        return 0;
    }
}