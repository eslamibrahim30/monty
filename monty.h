#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

#define MAX_LEN 256

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void freeStack(stack_t *head);
int isnumber(char *str);
void initInstructions(instruction_t instructions[7]);
void execLine(char line[MAX_LEN], stack_t **stack, unsigned int line_number);
void (*get_op_func(char *s))(stack_t **, unsigned int);
void splitString(char *input, char **words_list, int *word_counter);
void stack_push(stack_t **stack, int value);
void stack_pall(stack_t **stack, unsigned int c_line_number);
void stack_add(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack, unsigned int line_number);
void stack_pint(stack_t **stack, unsigned int line_number);
void stack_pop(stack_t **stack, unsigned int line_number);
void stack_swap(stack_t **stack, unsigned int line_number);
void stack_sub(stack_t **stack, unsigned int line_number);
void stack_div(stack_t **stack, unsigned int line_number);
void stack_mul(stack_t **stack, unsigned int line_number);
void stack_mod(stack_t **stack, unsigned int line_number);
void stack_pchar(stack_t **stack, unsigned int line_number);
void stack_pstr(stack_t **stack, unsigned int line_number);
void stack_rotl(stack_t **stack, unsigned int line_number);
void stack_rotr(stack_t **stack, unsigned int line_number);

#endif
