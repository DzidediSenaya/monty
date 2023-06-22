#include "monty.h"

/**
 * stack_op - this opcode sets the format of the data to a stack (LIFO)
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode in the Monty file
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
/* No action required, already in stack mode */
}


/**
 * queue - this opcode sets the format of the data to a queue (FIFO)
 *
 * @stack: Double pointer to the stack
 * @line_number: Line number of the opcode in the Monty file
 */

void queue(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
/* Reverse the stack to switch to queue mode */
rotr(stack);
}

