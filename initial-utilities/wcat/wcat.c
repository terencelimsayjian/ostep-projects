#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE (512)

int main (int argc, char *argv[]) {
    int i = argc;
    for (i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        char buff[BUFFER_SIZE];
        while (fgets(buff, BUFFER_SIZE, fp) != NULL) {
            printf("%s", buff);
        }

        fclose(fp);
    }

    return 0;
}