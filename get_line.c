#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int get_line(char **lineptr, size_t *n, FILE *stream) {
    int line_length = get_line(lineptr, n, stream);

    if (line_length == -1) {
        free(*lineptr);
        *lineptr = NULL;
    } else if ((*lineptr)[line_length - 1] == '\n') {
        (*lineptr)[line_length - 1] = '\0';  /* Remove the trailing newline character */
    }

    return line_length;
}

