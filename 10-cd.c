#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * builtin_cd - Change the current directory of the process
 * @args: The arguments passed to the cd command
 */
void builtin_cd(char *args[])
{
    char *dir;
    char cwd[1024];
    static char prev_dir[1024] = "";

    if (args[1] == NULL)
    {
      /* No argument provided, change to HOME directory */
        dir = getenv("HOME");
        if (dir == NULL)
        {
            fprintf(stderr, "cd: HOME not set\n");
            return;
        }
    }
    else if (strcmp(args[1], "-") == 0)
    {
      /* Change to previous directory */
        dir = prev_dir;
        if (dir[0] == '\0')
        {
            fprintf(stderr, "cd: no previous directory\n");
            return;
        }
    }
    else
    {
      /* Change to the directory specified in args[1] */
        dir = args[1];
    }

    if (chdir(dir) != 0)
    {
        perror("cd");
        return;
    }

    /* Update PWD environment variable */
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        setenv("PWD", cwd, 1);
    }
    else
    {
        perror("getcwd");
    }

    /* Update previous directory */
    if (strcmp(dir, prev_dir) != 0)
    {
        strncpy(prev_dir, cwd, sizeof(prev_dir));
        prev_dir[sizeof(prev_dir) - 1] = '\0';
    }
}
