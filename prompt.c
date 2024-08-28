#include "shell.h"

/**
 * prompt - Display the shell prompt
 */
void prompt(void)
{
    write(STDOUT_FILENO, "#cisfun$ ", 9);
}
