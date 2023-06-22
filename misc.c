#include "monty.h"
#include <stdbool.h>
#include <stdlib.h>

/**
 * is_integer - Checks if a string represents a valid integer.
 * @str: The string to be checked.
 *
 * Return: True if the string is a valid integer, otherwise false.
 */

bool is_integer(const char *str)
{
if (*str == '-' || *str == '+')
str++;

if (*str == '\0')
return (false);

while (*str != '\0')
{
if (*str < '0' || *str > '9')
return (false);
str++;
}

return (true);
}


/**
 * add_node - Adds a new node to the top of the stack.
 * @stack: A pointer to the stack.
 * @value: The value to be stored in the new node.
 */
void add_node(stack_t **stack, int value)
{
stack_t *new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
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

