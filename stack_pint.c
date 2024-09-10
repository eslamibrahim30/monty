#include "monty.h"

/**
 * stack_pint - Prints the value at the top of the stack,
 * followed by a new line.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	if (p == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	printf("%d\n", p->n);
}
