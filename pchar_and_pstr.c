#include "monty.h"

/** pchar - this opcode prints the char at the top of the stack,
 * followed by a new line.
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    stack_t *top = *stack;

    if (top == NULL)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (top->n < 0 || top->n > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    putchar(top->n);
    putchar('\n');
}


/**
 * pstr - opcode prints the string starting at the top of the stack,
 * followed by a new line.
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void pstr(stack_t **stack)
{
    stack_t *top = *stack;

    while (top != NULL && top->n != 0 && (top->n > 0 && top->n <= 127))
    {
        putchar(top->n);
        top = top->next;
    }

    putchar('\n');
}

