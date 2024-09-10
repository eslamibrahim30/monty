#include "monty.h"

/**
 * stack_pchar - Prints the char at the top of the stack,
 * followed by a new line.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *p = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	p = *stack;
	while (p->next != NULL)
	{
		p = p->next;
	}
	if (p->n < 32 || p->n > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", p->n);
}
