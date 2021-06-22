#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n" );
        exit(1);
    }

    int j;

    for (j = 1; j < argc; j++) {
        FILE *fp = fopen(argv[j], "r");

        if (fp == NULL) {
            printf("wunzip: cannot open file");
            exit(1);
        }

        char buff[5];
        while (fread(buff, 5, 1, fp)) {
            char intbuff[4];
            memcpy(intbuff, buff, 4);
            int count = *(int*) intbuff;

            int i;
            for (i = 0; i < count; i++) {
                printf("%c", buff[4]);
            }
        }

        fclose(fp);

    }

    return 0;
}