#include "monty.h"

/**
 * stack_pstr - Prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *p = NULL;

	if (stack == NULL || *stack == NULL || line_number == 0)
	{
		printf("\n");
		return;
	}
	p = *stack;
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (p != NULL)
	{
		if (p->n < 32 || p->n > 126 || p->n == 0)
			break;
		printf("%c", p->n);
		p = p->prev;
	}
	printf("\n");
}
