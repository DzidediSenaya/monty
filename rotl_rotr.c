#include "monty.h"

/**
* rotr - this opcode rotates the stack to the bottom.
* The last element of the stack becomes the top element of the stack.
* @stack: Double pointer to the stack
*/
void rotr(stack_t **stack)
{
stack_t *last = *stack;

if (last == NULL || last->next == NULL)
return;

while (last->next != NULL)
last = last->next;

last->prev->next = NULL;
last->prev = NULL;
last->next = *stack;
(*stack)->prev = last;
*stack = last;
}


/**
 * rotl - this opcode rotates the stack to the top.
 * The top element of the stack becomes the last one, and the
 * second top element of the stack becomes the first one.
 *
 * @stack: Double pointer to the stack
 */
void rotl(stack_t **stack)
{
stack_t *first = *stack;
stack_t *last = *stack;

if (first == NULL || first->next == NULL)
return;

while (last->next != NULL)
last = last->next;

*stack = first->next;
(*stack)->prev = NULL;

first->next = NULL;
first->prev = last;
last->next = first;
}

