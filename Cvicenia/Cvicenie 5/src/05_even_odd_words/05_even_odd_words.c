// uloha6-5.c -- František Gič, 29.10.2019 11:14

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM_BUFFER_SIZE 100
#define MAXIMUM_STRING_LENGTH 100

struct Buffer {
    int size;
    char **data;
};

struct File {
    FILE *file;
    char *path;
    char mode[2];
    struct Buffer buffer;
};


int main() {
    struct File files[] = {
            {
                    .path = "resources/prvy.txt",
                    .mode = "r"
            },
            {
                    .path = "resources/druhy.txt",
                    .mode = "r"
            },
            {
                    .path = "resources/treti.txt",
                    .mode = "w+"
            },
    };

    // Open the files
    for (int i = 0; i < ((int) (sizeof(files) / sizeof(files[0]))); i++) {
        if ((files[i].file = fopen(files[i].path, files[i].mode)) == NULL) {
            printf("Subor %s sa nepodarilo otvorit.\n", files[i].path);
            return 0;
        }
    }


    // read "r" files into file's buffer
    for (int i = 0; i < 2; i++) {

        char word[MAXIMUM_STRING_LENGTH];
        files[i].buffer.data = (char **) malloc(MAXIMUM_BUFFER_SIZE * sizeof(char *));
        files[i].buffer.size = 0;

        while (fscanf(files[i].file, " %s", word) == 1) {
            files[i].buffer.data[files[i].buffer.size] = (char *) malloc(strlen(word));
            files[i].buffer.data[files[i].buffer.size] = strcpy(files[i].buffer.data[files[i].buffer.size], word);
            files[i].buffer.size++;
        }
    }


    char **file0 = &files[0].buffer.data[0];
    char **file1 = &files[1].buffer.data[0];

    for (int i = 1; i <= (files[0].buffer.size + files[1].buffer.size); i++) {

        char **readFile = (i % 2 == 1) ? file0 : file1;
        char **backupFile = (readFile == file0) ? file1 : file0;

        // switch files if any of files has reached the end
        if (*readFile == NULL) {
            readFile = backupFile;
        }

        printf("%c%s ", (readFile == file0) ? '+' : '-', *readFile);
        fprintf(files[2].file, "%c%s ", (readFile == file0) ? '+' : '-', *readFile);

        if (readFile == file0) file0++; else file1++;
    }

    // Close files
    for (int i = 0; i < ((int) (sizeof(files) / sizeof(files[0]))); i++) {
        if ((fclose(files[i].file) == EOF)) {
            printf("Subor %s sa nepodarilo zatvorit.\n", files[i].path);
            return 0;
        }
    }
    return 0;
}