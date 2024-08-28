#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t nread;
    char *input_buffer = NULL;
    char *piped_command;

    while (1)
    {
        prompt();

        /* Read input from stdin */
        nread = getline(&command, &len, stdin);

        if (nread == -1)  /* Handle Ctrl+D */
        {
            free(command);
            exit(EXIT_SUCCESS);
        }

        if (nread > 1)  /* Ignore empty commands */
        {
            command[nread - 1] = '\0';  /* Remove newline character */
            if (isatty(STDIN_FILENO))  /* Interactive mode */
            {
                execute_command(command);
            }
            else  /* Non-interactive mode */
            {
                input_buffer = strdup(command);
                if (input_buffer == NULL)
                {
                    perror("./hsh");
                    exit(EXIT_FAILURE);
                }
                piped_command = strtok(input_buffer, "\n");
                while (piped_command != NULL)
                {
                    execute_command(piped_command);
                    piped_command = strtok(NULL, "\n");
                }
                free(input_buffer);
            }
        }
    }

    return 0;
}
