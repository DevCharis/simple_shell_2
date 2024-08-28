#include "shell.h"
#include <stdlib.h>
#include <string.h>

char **my_tokenizer(char *input, const char *delimiters) {
    int bufsize = 64;
    int pos = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, delimiters);
    while (token != NULL) {
        tokens[pos] = token;
        pos++;

        if (pos >= bufsize) {
            bufsize *= 2;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, delimiters);
    }
    tokens[pos] = NULL;
    return tokens;
}
