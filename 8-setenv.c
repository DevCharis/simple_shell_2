#include "shell.h"

/**
 * builtin_setenv - Set or update an environment variable
 * @args: Array of arguments for the setenv command
 */
void builtin_setenv(char *args[])
{
    if (args[1] == NULL || args[2] == NULL)  /* Check if correct number of arguments are provided */
    {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return;
    }

    if (setenv(args[1], args[2], 1) == -1)  /* Set or update the environment variable */
    {
        perror("setenv");
    }
}
