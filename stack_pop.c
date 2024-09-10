#include "monty.h"

/**
 * stack_pop - Removes the top element of the stack.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *p = NULL;
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u:  can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	p = *stack;
	if (p->next == NULL)
	{
		*stack = NULL;
		free(p);
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		temp = p;
		p->prev->next = NULL;
		free(temp);
	}
}
