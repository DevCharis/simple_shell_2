#include "shell.h"

/**
 * builtin_unsetenv - Remove an environment variable
 * @args: Array of arguments for the unsetenv command
 */
void builtin_unsetenv(char *args[])
{
    if (args[1] == NULL)  /* Check if the variable name is provided */
    {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return;
    }

    if (unsetenv(args[1]) == -1)  /* Remove the environment variable */
    {
        perror("unsetenv");
    }
}
