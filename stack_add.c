#include "monty.h"

/**
 * stack_add - Adds the top two elements of the stack.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_add(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (stack == NULL ? NULL : *stack);
	stack_t *temp;
	int sum = 0;

	if (p == NULL || p->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	sum = p->n + p->prev->n;
	temp = p;
	p->prev->next = NULL;
	temp->prev->n = sum;
	free(temp);
}
