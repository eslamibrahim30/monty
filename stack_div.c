#include "monty.h"

/**
 * stack_div - Divides the second top element of the stack
 * by the top element of the stack.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_div(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (stack == NULL ? NULL : *stack);
	stack_t *temp;
	int div = 0;

	if (p == NULL || p->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	if (p->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	div = p->prev->n / p->n;
	temp = p;
	p->prev->next = NULL;
	temp->prev->n = div;
	free(temp);
}
