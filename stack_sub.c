#include "monty.h"

/**
 * stack_sub - Subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (stack == NULL ? NULL : *stack);
	stack_t *temp;
	int sub = 0;

	if (p == NULL || p->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	sub = p->prev->n - p->n;
	temp = p;
	p->prev->next = NULL;
	temp->prev->n = sub;
	free(temp);
}
