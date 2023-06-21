#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int getline(char **lineptr, size_t *n, FILE *stream);
void free_stack(stack_t *stack);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: EXIT_SUCCESS if the program runs successfully,
 * otherwise EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
FILE *file = fopen(argv[1], "r");
stack_t *stack = NULL;
    char *line = NULL;
    size_t line_len = 0;
    unsigned int line_number = 0;
int read;
char *opcode = strtok(line, " \t\n");


    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    /* Open the Monty bytecode file*/
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }


    /*Read and process each line of the bytecode file*/
while ((read = getline(&line, &line_len, file)) != EOF)
{
        line_number++;

        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        /* Tokenize the line to extract the opcode*/
        if (opcode == NULL || opcode[0] == '#')
            continue;

        /* Process the opcode*/
        if (strcmp(opcode, "push") == 0)
        {
            push(&stack, line_number);
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            free(line);
            fclose(file);
            free_stack(stack);
            return EXIT_FAILURE;
        }
    }

    /*Free allocated memory and close the file*/
    free(line);
    fclose(file);
    free_stack(stack);

    return EXIT_SUCCESS;
}

