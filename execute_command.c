
#include "shell.h"

/**
 * execute_command - Execute a command using execve
 * @command: The command to execute
 */
void execute_command(char *command)
{
    char **argv;
    char *command_path;

    argv = tokenize(command);  /* Get arguments */
    command_path = argv[0];  /* Extract command */

    if (strcmp(command_path, "exit") == 0)
    {
        /* Free allocated memory and exit shell */
        free(argv);
        free(command);
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(command_path, "env") == 0)
    {
        /* Print environment variables */
        print_env();
        free(argv);
        free(command);
        return;
    }
    else if (strcmp(command_path, "setenv") == 0)
    {
        /* Handle setenv command */
        builtin_setenv(argv);
        free(argv);
        free(command);
        return;
    }
    else if (strcmp(command_path, "unsetenv") == 0)
    {
        /* Handle unsetenv command */
        builtin_unsetenv(argv);
        free(argv);
        free(command);
        return;
    }
    else if (strcmp(command_path, "cd") == 0)
    {
        /* Handle cd command */
        builtin_cd(argv);
        free(argv);
        free(command);
        return;
    }

    if (access(command_path, X_OK) == 0)  /* Check if command exists in current directory */
    {
        if (execve(command_path, argv, environ) == -1)
        {
            perror("./hsh");  /* Error if execve fails */
        }
    }
    else
    {
        /* Try to find the executable in PATH */
        command_path = find_executable(command_path);
        if (command_path)
        {
            if (execve(command_path, argv, environ) == -1)
            {
                perror("./hsh");
            }
            free(command_path);
        }
        else
        {
            perror("./hsh");  /* Error if command is not found */
        }
    }

    free(argv);  /* Free allocated memory */
}
