/*
    denum   v 0.1
    author  Dave Smith-Hayes

    enumerates words in a string to a new line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BUFFER  1024     /* 1024B (1kB) buffer */

int
main(int argc, char *argv[]) {

    /* Variables */
    int   i;
    int   input_length;
    char  buffer[MAX_BUFFER + 1] = { 0 };
    char *word;
    FILE *input;
    bool  use_argv;

    /* Check for argc, use STDIN otherwise */
    if(argc == 1)
        use_argv = false;
    else
        use_argv = true;

    /* Operations */
    if(use_argv) {
        for(i = 1; i < argc; i++)
            fprintf(stdout, "%s\n", argv[i]);
    }
    else {
        i = 1;

        while((input_length = fread(buffer, 1, MAX_BUFFER, stdin) > 0)) {
            word = strtok(buffer, " ");

            while(word != NULL) {
                fprintf(stdout, "%s\n", word);
                word = strtok(NULL, " ");
            }
        }
    }

    /* Finale */
    return 0;
}
