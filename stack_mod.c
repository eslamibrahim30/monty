#include "monty.h"

/**
 * stack_mod - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: a pointer to the head of the stack.
 * @line_number: the current line's number.
 */
void stack_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (stack == NULL ? NULL : *stack);
	stack_t *temp;
	int mod = 0;

	if (p == NULL || p->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	if (p->n == 0)
	{
		fprintf(stderr, "L%u: modision by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = p->prev->n % p->n;
	temp = p;
	p->prev->next = NULL;
	temp->prev->n = mod;
	free(temp);
}
