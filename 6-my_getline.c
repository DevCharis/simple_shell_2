#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
    static char buffer[BUFFER_SIZE];
    static size_t pos;
    static size_t chars_read;
    size_t len = 0;
    char *new_lineptr;

    if (!lineptr || !n) {
        return -1;
    }

    if (!*lineptr) {
        *n = BUFFER_SIZE;
        *lineptr = malloc(*n);
        if (!*lineptr) {
            return -1;
        }
    }

    while (1) {
        if (pos >= chars_read) {
            chars_read = read(fileno(stream), buffer, BUFFER_SIZE);
            pos = 0;
            if (chars_read <= 0) {
                return -1;
            }
        }

        (*lineptr)[len++] = buffer[pos++];
        if ((*lineptr)[len - 1] == '\n') {
            break;
        }

        if (len >= *n) {
            *n *= 2;
            new_lineptr = realloc(*lineptr, *n);
            if (!new_lineptr) {
                return -1;
            }
            *lineptr = new_lineptr;
        }
    }

    (*lineptr)[len] = '\0';
    return len;
}
