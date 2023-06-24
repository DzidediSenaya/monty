#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void process_file(FILE *file);
void process_line(char *line, unsigned int line_number);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);
void handle_unknown_opcode(char *opcode, unsigned int line_number);

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
  FILE *file;

  if (argc != 2)
  {
    fprintf(stderr, "USAGE: monty file\n");
    return (EXIT_FAILURE);
  }

  file = fopen(argv[1], "r");
  if (!file)
  {
    fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
    return (EXIT_FAILURE);
  }

  process_file(file);

  fclose(file);

  return (EXIT_SUCCESS);
}
/**
 * process_file - Process the lines of the input file
 * @file: Pointer to the input file
 */
void process_file(FILE *file)
{
char *line = NULL;
size_t line_len = 0;
unsigned int line_number = 0;
int read;

while ((read = get_line(&line, &line_len, file)) != -1)
{
line_number++;

process_line(line, line_number);
}
}

/**
 * process_line - Process a single line of the input file
 * @line: The line to process
 * @line_number: The line number being executed
 */
void process_line(char *line, unsigned int line_number)
{
  stack_t *stack = NULL;
  char *opcode = strtok(line, " \t\n");

  if (!opcode || opcode[0] == '#')
    return;

  execute_opcode(opcode, &stack, line_number);
  free_stack(stack);
}

/**
 * execute_opcode - Execute the given opcode
 * @opcode: The opcode to execute
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number being executed
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
  if (strcmp(opcode, "push") == 0)
    push(stack, line_number);
  else if (strcmp(opcode, "pall") == 0)
    pall(stack, line_number);
  else if (strcmp(opcode, "pint") == 0)
    pint(stack, line_number);
  else if (strcmp(opcode, "pop") == 0)
    pop(stack, line_number);
  else if (strcmp(opcode, "swap") == 0)
    swap(stack, line_number);
  else if (strcmp(opcode, "add") == 0)
    add(stack, line_number);
  else if (strcmp(opcode, "sub") == 0)
    sub(stack, line_number);
  else if (strcmp(opcode, "div") == 0)
    _div(stack, line_number);
  else if (strcmp(opcode, "mul") == 0)
    mul(stack, line_number);
  else if (strcmp(opcode, "mod") == 0)
    mod(stack, line_number);
  else if (strcmp(opcode, "pchar") == 0)
    pchar(stack, line_number);
  else if (strcmp(opcode, "pstr") == 0)
    pstr(stack);
  else if (strcmp(opcode, "rotl") == 0)
    rotl(stack);
  else if (strcmp(opcode, "rotr") == 0)
    rotr(stack);
  else if (strcmp(opcode, "stack") == 0)
    stack_op(stack, line_number);
  else if (strcmp(opcode, "queue") == 0)
    queue(stack, line_number);
  else
  {
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
  }
}

/**
 * handle_unknown_opcode - Handles an unknown opcode error
 * @opcode: The unknown opcode
 * @line_number: The line number where the error occurred
 */
void handle_unknown_opcode(char *opcode, unsigned int line_number)
{
  fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
  exit(EXIT_FAILURE);
}

