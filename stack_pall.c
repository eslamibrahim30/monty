#include "monty.h"

/**
 * stack_pall - Prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	if ((stack == NULL && line_number) || *stack == NULL)
	{
		return;
	}
	p = *stack;
	while (p->next != NULL)
	{
		p = p->next;
	}
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->prev;
	}
}
