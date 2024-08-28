#include "shell.h"

char **tokenize(char *command)
{
    char **tokens = NULL;
    char *token;
    size_t i = 0;
    size_t bufsize = 64;

    tokens = malloc(bufsize * sizeof(char *));
    if (!tokens)
    {
        perror("hsh: allocation error");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, " \n");
    while (token != NULL)
    {
        tokens[i] = token;
        i++;

        if (i >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                perror("hsh: allocation error");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \n");
    }
    tokens[i] = NULL;

    return tokens;
}
