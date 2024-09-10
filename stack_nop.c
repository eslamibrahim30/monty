#include "monty.h"

/**
 * stack_nop - Doesn’t do anything :"D.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_nop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL && line_number)
		line_number = 0;
}
