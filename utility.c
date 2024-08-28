#include "shell.h"

void print_env(void)
{
    char **env = environ;

    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}

char *find_executable(char *command)
{
    char *path, *path_copy, *token, *full_path;
    struct stat st;

    path = getenv("PATH");
    if (!path)
        return NULL;

    path_copy = strdup(path);
    token = strtok(path_copy, ":");

    while (token)
    {
        full_path = malloc(strlen(token) + strlen(command) + 2);
        if (!full_path)
        {
            perror("hsh: allocation error");
            free(path_copy);
            return NULL;
        }

        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);

        if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
        {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
