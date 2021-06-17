#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE (512)

int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    
    char *searchTerm = argv[1];
    if (argc == 2) {

        char inputLine[BUFFER_SIZE];
        int size = BUFFER_SIZE;
        char * readLine = "";

        while (readLine != NULL) {
            readLine = fgets(inputLine, size, stdin);

            if (strstr(inputLine, searchTerm) != NULL) {
                printf("%s", inputLine);
            }
        }

        return 0;
    }

    int i;
    for (i = 2; i < argc; i++) {
        FILE *fp = fopen(argv[2], "r");

        if (fp == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        
        ssize_t getLineVal = 0;
        char *line = NULL;
        size_t linecapp = BUFFER_SIZE;

        while (getLineVal >= 0) {
            getLineVal = getline(&line, &linecapp, fp);

            if (strstr(line, searchTerm) != NULL) {
                printf("%s", line);
            }
        }
    }
    


    return 0;
}