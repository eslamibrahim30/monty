#include "monty.h"

/**
 * stack_swap - Swaps the top two elements of the stack.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;
	int temp;
	stack_t *count = p;
	int i = 0;

	while (count)
	{
		count = count->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	temp = p->n;
	p->n = p->prev->n;
	p->prev->n = temp;
}
