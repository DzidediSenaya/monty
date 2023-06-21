#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_number(const char *str);

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file where the opcode is encountered
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");
    stack_t *new_node;

    if (arg == NULL || !is_number(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(arg);
    new_node->prev = NULL;

    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the file where the opcode is encountered
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    stack_t *temp = *stack;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

int is_number(const char *str)
{
int i = 0;

    if (str == NULL || *str == '\0')
        return (0);

    if (str[0] == '-' || str[0] == '+')
        i = 1;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }

    return (1);
}

