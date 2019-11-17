#include <stdio.h>

int main() {
    FILE *fa, *fb, *fc;

    if ((fc = fopen("fc", "r")) == NULL) return 0;
    if ((fa = fopen("fa", "w+")) == NULL) return 0;
    if ((fb = fopen("fb", "w+")) == NULL) return 0;

    char c;
    while ((c = getc(fc)) != EOF) {
        if (c != '\n' && c != '\0' && (c > '0' && c <= '9')) {
            if ((c - '0') % 2 == 0)
                putc(c, fa);
            else
                putc(c, fb);
        }
    }

    if (fclose(fc) == EOF) return 0;
    if (fclose(fa) == EOF) return 0;
    if (fclose(fb) == EOF) return 0;
}