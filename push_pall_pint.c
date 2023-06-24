#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

bool is_integer(const char *str);

/**
 * push - Pushes an element to the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number being executed
 */
void push(stack_t **stack, unsigned int line_number)
{
char *arg = strtok(NULL, " \t\n");

if (!arg || !is_integer(arg))
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

add_node(stack, atoi(arg));
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
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the opcode being executed
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
return;
}

printf("%d\n", (*stack)->n);
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

