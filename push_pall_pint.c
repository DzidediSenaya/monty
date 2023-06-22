#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

/**
 * push - Pushes an element to the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number being executed
 */
void push(stack_t **stack, unsigned int line_number)
{
char *arg = strtok(NULL, " \t\n");
int n;
stack_t *new_node = malloc(sizeof(stack_t));

if (arg == NULL || !is_number(arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

n = atoi(arg);
/* Create new stack node */
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = n;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}

/**
 * pall - Prints all the values on the stack, starting from the top
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number being executed
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

(void)line_number;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
 * free_stack - Frees the entire stack
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
stack_t *current = stack;

while (current != NULL)
{
stack_t *temp = current;
current = current->next;
free(temp);
}
}

/**
 * is_number - Checks if a string is a valid integer
 * @str: The string to check
 *
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int is_number(const char *str)
{
if (str == NULL || *str == '\0')
return (0);

while (*str)
{
if (!isdigit(*str) && *str != '-')
return (0);
str++;
}
return (1);
}

