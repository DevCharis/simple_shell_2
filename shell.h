#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>



/* Function prototypes for built-in commands */
void builtin_exit(char *args[]);
void builtin_setenv(char *args[]);
void builtin_unsetenv(char *args[]);
void builtin_cd(char *args[]);
/* Global variable */
extern char **environ;

/* Function Prototypes */

/* main.c */
void prompt(void);

/* execute_command.c */
void execute_command(char *command);
char *find_executable(char *command_path);
void fork_and_exec(char *command_path, char **argv);
/* utility.c */
char **tokenize(char *command);
void free_tokens(char **tokens);
void print_env(void);

/* string_utils.c */
int _strcmp(char *s1, char *s2);
char *_strdup(const char *s);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
int _strlen(const char *s);

#endif /* SHELL_H */
