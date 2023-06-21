#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - Frees the memory allocated for each
 * node in the stack.
 * @stack: Pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
    stack_t *current;

    while (stack != NULL)
    {
        current = stack;
        stack = stack->next;
        free(current);
    }
}

