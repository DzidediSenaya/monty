#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_line - Reads a line from a file
 * @lineptr: Pointer to the buffer storing the line
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * Return: The number of characters read, or -1 if an error
 * occurred or end-of-file was reached
 */

int get_line(char **lineptr, size_t *n, FILE *stream)
{
int line_length = get_line(lineptr, n, stream);

if (line_length == -1)
{
free(*lineptr);
*lineptr = NULL;
}
else if ((*lineptr)[line_length - 1] == '\n')
{
(*lineptr)[line_length - 1] = '\0'; /* Remove the trailing newline character */
}
return (line_length);
}

