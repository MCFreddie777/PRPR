//
// Created by František Gič on 17/11/2019.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strdelete(char *str, int n, int offset) {
    int str_length = strlen(str);
    if (
            offset > str_length ||
            (str_length - offset) < n ||
            n > str_length
            )
        return 1;

    char *temp = (char *) malloc(str_length - n);
    int temp_length = 0;

    for (int i = 0; i < str_length; i++) {
        if (i < offset || i >= (offset + n)) {
            temp[temp_length++] = str[i];
        }
    }

    temp[temp_length] = '\0';
    str = strcpy(str, temp);
    free(temp);
    return 0;
}

int strinsert(char *dst, int len, const char *src, int offset) {
    int dst_length = strlen(dst), src_length = strlen(src);

    if (
            (dst_length + src_length) > len - 1 ||
            offset > dst_length ||
            offset < 0)
        return 1;

    char *temp = (char *) malloc(dst_length + src_length);
    int temp_length = 0;

    for (int i = 0; i < (dst_length + src_length); i++) {
        if (i < offset)
            temp[temp_length++] = dst[i];

        if (i >= offset && i < (offset + src_length))
            temp[temp_length++] = src[i - offset];

        if (i >= (offset + src_length))
            temp[temp_length++] = dst[i - src_length];
    }

//        if (i < dst_length) {
//            temp = realloc(temp, i * sizeof(char));
//            temp[temp_length++] = dst[i];
//        }
//
//        if (i < (offset + src_length))
//            dst[i] = src[i - offset];
//        else if (i == (dst_length + src_length)) {
//            dst[i] = '\0';
//            return 0;
//        } else
//            dst[i] = temp[i - (offset + src_length)];

    temp[temp_length] = '\0';
    strcpy(dst, temp);
    free(temp);
    return 0;
}



