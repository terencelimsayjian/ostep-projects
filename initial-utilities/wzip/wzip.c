#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    int i;

    char new_char_buff[2];
    char old_char_buff[2];
    int count = 1;
    for (i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");

        if (fp == NULL) {
            printf("wzip: cannot open file\n");
            exit(1);
        }

        while (fread(new_char_buff, 1, 1, fp) != 0) {

            if (strcmp(old_char_buff, new_char_buff) == 0) {
                count++;
            } else {
                if (old_char_buff[0] != 0) {
                    fwrite(&count, 4, 1, stdout);
                    fwrite(old_char_buff, 1, 1, stdout);
                }

                strcpy(old_char_buff, new_char_buff);
                count = 1;
            }
        };

            
        fclose(fp);
    }

    fwrite(&count, 4, 1, stdout);
    fwrite(old_char_buff, 1, 1, stdout);
    
    
    return 0;
}