#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * builtin_exit - Exit the shell with a given status.
 * @args: Array of arguments passed to the exit command.
 */
void builtin_exit(char *args[])
{
    if (args[1] != NULL)  /* If there's an argument */
    {
        int status = atoi(args[1]);  /* Convert argument to integer */
        free(args);  /* Free allocated memory */
        exit(status);  /* Exit with the specified status */
    }
    else
    {
        free(args);  /* Free allocated memory */
        exit(EXIT_SUCCESS);  /* Exit with status 0 if no argument is provided */
    }
}
