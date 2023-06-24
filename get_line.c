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
  size_t bufsize = 64, i = 0;
  int c;
  char *new_lineptr;

  if (lineptr == NULL || n == NULL || stream == NULL)
    return (-1);

  *lineptr = malloc(bufsize);
  if (*lineptr == NULL)
    return (-1);

  while ((c = fgetc(stream)) != EOF)
  {
    if (i >= bufsize - 1)
    {
      bufsize += 64;
      new_lineptr = realloc(*lineptr, bufsize);
      if (new_lineptr == NULL)
      {
        free(*lineptr);
        return (-1);
      }
      *lineptr = new_lineptr;
    }

    if (c == '\n')
      break;

    (*lineptr)[i++] = c;
  }

  if (i == 0 && c == EOF)
  {
    free(*lineptr);
    return (-1);
  }

  (*lineptr)[i] = '\0';
  *n = i + 1;
  return (i);
}

