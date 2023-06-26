#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_line - Reads a line from a file
 * @lineptr: Pointer to the buffer storing the line
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * Return: The number of characters read, or 0 if an error
 * occurred or end-of-file was reached
 */
int get_line(char **lineptr, size_t *n, FILE *stream)
{
size_t bufsize = 256;
size_t i = 0;
int c;
char *new_lineptr;

if (lineptr == NULL || n == NULL || stream == NULL)
return (0);

*lineptr = malloc(bufsize);
if (*lineptr == NULL)
return (0);

while ((c = fgetc(stream)) != '\n' && c != EOF)
{
(*lineptr)[i++] = c;
if (i >= bufsize - 1)
{
bufsize += 256;
new_lineptr = realloc(*lineptr, bufsize);
if (new_lineptr == NULL)
{
free(*lineptr);
return (0);
}
*lineptr = new_lineptr;
}
}
(*lineptr)[i] = '\0';
if (i == 0 && c == EOF)
{
free(*lineptr);
return (0);
}
*n = i + 1;
return (i);
}

